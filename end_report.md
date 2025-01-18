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

### Testowanie
Do testowania oprogramowania wykorzystano framework Ceedling, który pozwala na wygodne pisanie i uruchamianie testów jednostkowych w języku C. W procesie developmentu starano się stosować dobre praktyki inżynierii oprogramowania, takie jak iteracyjne podejście do wprowadzania zmian oraz wczesne i częste testowanie.

W celu eliminacji zależności od warstwy sprzętowej (np. Hardware Abstraction Layer - HAL), zastosowano mocki. Niektóre mocki zostały napisane od zera, ale w niektórych przypadkach użyto też gotowych mocków z frameworka *Ceedling*. Dzięki temu możliwe było przetestowanie logiki aplikacji niezależnie od fizycznego sprzętu oraz zminimalizowanie potencjalnych błędów związanych z integracją.

Wszystkie testy zostały zaprojektowane w taki sposób, aby były modularne i łatwe do utrzymania. Przypadki testowe pozwoliły upewnić się, że oprogramowanie działa zgodnie z założeniami w różnych scenariuszach.

Konfiguracja środowiska testowego zawarta jest w ***project.yml***.

### Użyte biblioteki zewnętrzne
## Zarządzanie wyświetlaczem OLED

W projekcie wykorzystano bibliotekę **stm32-ssd1306** autorstwa [afiskon](https://github.com/afiskon/stm32-ssd1306) do zarządzania wyświetlaczem OLED opartym na kontrolerze SSD1306. Biblioteka ta zapewnia funkcjonalności umożliwiające łatwą obsługę wyświetlacza, takie jak rysowanie pikseli, tekstu czy prostych kształtów.  

Aby oddzielić bibliotekę od aplikacji oraz zwiększyć jej przenośność i modularność, została opakowana w warstwę abstrakcji nazwaną **OLedProxy**. Warstwa ta pełni rolę interfejsu pomiędzy logiką aplikacji a implementacją specyficzną dla wyświetlacza, co pozwala na:  
- Łatwą wymianę używanej biblioteki w przyszłości.  
- Zachowanie czystości kodu aplikacji, który nie zależy bezpośrednio od szczegółów implementacyjnych biblioteki.  
- Ułatwienie testowania aplikacji poprzez możliwość mockowania funkcjonalności wyświetlacza.  

