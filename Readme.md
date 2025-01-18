# Projekt na przedmiot Architektura oprogramowania systemów wbudowanych

## Autorzy 

- Michał Mokrzycki
- Karol Pieczka

### Development i struktura branchy
- *main*: Tylko przetestowany i działający kod, zabronione commitowanie na tego brancha,tylko merge z deva
- *dev*: możliwe proste commity, zalecane merge z innych branchy rozwijające funkcjonalności
- *inne branche*: niestabilny kod 

Należy zaczynać każdy plik poprzez ```/**```
Pozwoli to wygenerować Doxygen-style komentarze:
```
/**
 * @file app_core.h
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
Przydatne potem w tworzeniu dokumentacji.


##### Framework

Enkapsulacja operacji na peryferiach w interfejs

### ToDo

Mieć driver do SN74AHCT367PWR, pozwoli na sterownaie matrycą led i serwami.
Ewentualnie prosty driver do wyświetlacza led ssd1306.

#### Pinout

Konfiguracja stm32l476 na nucleo wygląda następująco:
(Należy updatować readme po konifguracji w cubemx)

![CubeMx](docs/update_pinout.png)

### Znalezione Problemy

- test_Mediator.c działą różnie w zależnosci od platformy(widnows/ubuntu)
zakomnetowane testy działają na windowsie, jednak na Ubuntu  powodują  segmentation fault - powód  nieznany

#### Dokumentacja

- Nieścisłości/błędy w oznaczeniach
-i2c2 w dokumntacji to tak naprawdę i2c3, wskazane piny nie pozwalją na konfiguracj i2c2 tylko i2c3
- spi2 to spi3

`wydaje mi się ze to tylko kwestia nazewnictwa i nie powinno być problemów`


### Zaincludowane dirvery i biblioteki

#### Biblioteka to wyświetlacza OLED

Wszystkie zmiany wprowadzamy w napisanym pliku ssd1306_conf.h
Ustalamy tam m.in
- szerokość  i wysokośc  ekranu

### UWAGA

Po kazdej generacji kodu należy do pliku cmake/stm32cubemx/CMakeLists.txt dodac 
../../Drivers/OLedDriver/Include w sekji target_include_directories 
oraz
../../Drivers/OLedDriver/Src/ssd1306.c
    ../../Drivers/OLedDriver/Src/ssd1306_fonts.c
    ../../Drivers/OLedDriver/Src/ssd1306_tests.c w sekcji target sources