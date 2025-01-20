# AOSYW 2024 Z

## Autorzy
- Michał Mokrzycki
- Karol Pieczka

### Architektura systemu

### Zależności między peryferiami

### Środowisko programistyczne i automatyzacja generacji kodu

W projekcie wykorzystano środowisko programistyczne **Visual Studio Code**, rozszerzone o dodatki dedykowane dla STM32, takie jak **STM32CubeMX** i **STM32CubeIDE**. STM32CubeMX umożliwiło automatyczną generację kodu inicjalizacyjnego dla peryferiów, co znacząco przyspieszyło proces konfiguracji mikrokontrolera i zmniejszyło ryzyko błędów wynikających z ręcznej konfiguracji rejestrów.

Projekt został zaprojektowany w sposób umożliwiający łatwe dodawanie nowych platform sprzętowych. Dzięki wykorzystaniu metodologii opartej na automatycznej generacji kodu, wszelkie zmiany lub dodanie nowych peryferiów wymagały minimalnej modyfikacji kodu źródłowego, co znacznie poprawia elastyczność rozwiązania.

Cały projekt jest kompilowany przy pomocy plików konfiguracji **CMakeLists**, co zapewnia niezależność od konkretnego środowiska IDE. Dzięki zastosowaniu CMake proces budowy projektu jest bardziej uniwersalny i łatwo przenoszalny pomiędzy różnymi platformami programistycznymi oraz systemami operacyjnymi.

### Struktura projektu

![Structure](docs/AosywStructure.png)

Diagram przedstawia strukturę projektu opartą na warstwowej architekturze, wzbogaconą o Mediatora i zintegrowaną z systemem FreeRTOS. Rozwiązanie to ułatwia zarządzanie komunikacją i obsługę różnorodnych peryferiów.

HAL (Hardware Abstraction Layer): Warstwa abstrakcji sprzętowej, która izoluje dostęp do sprzętu, dostarczając jednolite interfejsy dla modułów wyższych warstw.

LLProxys (Low-Level Proxies): Moduły te oddzielają warstwę HAL od warstwy aplikacyjnej, tłumacząc specyficzne protokoły sprzętowe (np. SPI, I2C, ADC) na bardziej uniwersalne interfejsy. Dzięki temu warstwa aplikacyjna nie wymaga wiedzy o szczegółach sprzętowych.

HLProxys (High-Level Proxies): Moduły wysokopoziomowe, które implementują logikę specyficzną dla danych urządzeń (np. ToF Sensor Proxy, Light Sensor Proxy). Po wykonaniu polecenia execute() przesyłają wynik testu do Mediatora.

Mediator: Centralny moduł zarządzający komunikacją pomiędzy HLProxys. Wywołuje funkcję notify(), aby powiadomić wszystkie proxy o konieczności wykonania testów, a następnie zbiera wyniki od poszczególnych modułów. Mediator minimalizuje bezpośrednie zależności między komponentami, co upraszcza integrację.

FreeRTOS: Odpowiada za harmonogramowanie zadań w czasie rzeczywistym, zapewniając wydajną i bezpieczną pracę systemu, np. w obsłudze OLED Display Proxy.

Dzięki takiej architekturze łatwo można dodawać nowe peryferia i moduły. Wystarczy utworzyć odpowiedni LL Proxy oraz HL Proxy, bez konieczności modyfikacji istniejącego kodu. 

#### Stuktura Proxy


### Testowanie
Do testowania oprogramowania wykorzystano framework Ceedling, który pozwala na wygodne pisanie i uruchamianie testów jednostkowych w języku C. W procesie developmentu starano się stosować dobre praktyki inżynierii oprogramowania, takie jak iteracyjne podejście do wprowadzania zmian oraz wczesne i częste testowanie.

W celu eliminacji zależności od warstwy sprzętowej (np. Hardware Abstraction Layer - HAL), zastosowano mocki. Niektóre mocki zostały napisane od zera, ale w niektórych przypadkach użyto też gotowych mocków z frameworka *Ceedling*. Dzięki temu możliwe było przetestowanie logiki aplikacji niezależnie od fizycznego sprzętu oraz zminimalizowanie potencjalnych błędów związanych z integracją.

Wszystkie testy zostały zaprojektowane w taki sposób, aby były modularne i łatwe do utrzymania. Przypadki testowe pozwoliły upewnić się, że oprogramowanie działa zgodnie z założeniami w różnych scenariuszach.

Konfiguracja środowiska testowego zawarta jest w ***project.yml***.

### Użyte biblioteki zewnętrzne - Zarządzanie wyświetlaczem OLED

W projekcie wykorzystano bibliotekę **stm32-ssd1306** autorstwa [afiskon](https://github.com/afiskon/stm32-ssd1306) do zarządzania wyświetlaczem OLED opartym na kontrolerze SSD1306. Biblioteka ta zapewnia funkcjonalności umożliwiające łatwą obsługę wyświetlacza, takie jak rysowanie pikseli, tekstu czy prostych kształtów.  

Aby oddzielić bibliotekę od aplikacji oraz zwiększyć jej przenośność i modularność, została opakowana w warstwę abstrakcji nazwaną **OLedProxy**. Warstwa ta pełni rolę interfejsu pomiędzy logiką aplikacji a implementacją specyficzną dla wyświetlacza, co pozwala na:  
- Łatwą wymianę używanej biblioteki w przyszłości.  
- Zachowanie czystości kodu aplikacji, który nie zależy bezpośrednio od szczegółów implementacyjnych biblioteki.  
- Ułatwienie testowania aplikacji poprzez możliwość mockowania funkcjonalności wyświetlacza.  

### Pinout

Konfiguracja stm32l476 na nucleo wygląda następująco:
(Należy updatować readme po konifguracji w cubemx)

![CubeMx](docs/update_pinout.png)


### Development i struktura branchy
- *main*: Tylko przetestowany i działający kod, zabronione commitowanie na tego brancha,tylko merge z deva
- *dev*: możliwe proste commity, zalecane merge z innych branchy rozwijające funkcjonalności
- *inne branche*: niestabilny kod 

Należy zaczynać każdy plik poprzez ```/**```
Pozwoli to wygenerować Doxygen-style komentarze:
```
/**
 * @file "file_name"
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */ 
 (Pomijamy copyright i wersję)
```

### Uwagi i natrafione problemy

Z racji tego, że automatyczna generacja kodu nadpisuje jedną z *CmakeLists.txt*
Po kazdej generacji kodu należy do pliku cmake/stm32cubemx/CMakeLists.txt dodac 
../../Drivers/OLedDriver/Include w sekji target_include_directories 
oraz
../../Drivers/OLedDriver/Src/ssd1306.c
    ../../Drivers/OLedDriver/Src/ssd1306_fonts.c
    ../../Drivers/OLedDriver/Src/ssd1306_tests.c w sekcji target sources

Aby zmienić szerokość i wysokoć ekranu OLED oraz inne prametry:
Zmiany wprowadzamy w napisanym pliku ssd1306_conf.h
Ustalamy tam m.in
- szerokość  i wysokośc  ekranu

