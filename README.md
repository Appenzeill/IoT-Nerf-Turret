## Inhoudsopgave 
* [Algemene informatie](#algemene-informatie)
* [Technologieën](#technologieën)
* [Setup](#setup)
* [Studenten](#studenten)
* [Licentie](#licentie)

## Algemene informatie
Dit project is een eindopdracht van periode C 2021.

Het doel is om een IoT device te maken. Wij hebben besloten een Nerf turret te maken die op afstand te besturen is.
	
## Technologieën
Project is gemaakt met:
* CMake 
* Make
* C++ 14
* WiringPie
	
## Setup
Het project kan worden gebuild doormiddel vand de volgende instructies:

### POSIX
```
$ git clone https://github.com/Appenzeill/IoT-Nerf-Turret.git
$ mkdir build
$ cd build
$ cmake ..
$ make
```
### Binaries
Er zijn 2 binaries, turret en controller.

```
$ ./controller
```

en

```
$ sudo ./turret
```

Let op, turret heeft su permissies nodig.

## Studenten 
* Jarno Bröcker | 1781716 | [Jarno-2003](https://github.com/Jarno-2003) 
* Rick Nuhaan | 1787435 | [Rick2003](https://github.com/rick2003)
* Ray de Kruif | 1787534 | [Rayax10](https://github.com/Rayax10)
* Daan Roth | 1782443 | [Appenzeill](https://github.com/Appenzeill)
* Daniël Berkhout | 1791498 | [DanielBerkhout](https://github.com/DanielBerkhout)

## Licentie

Dit project heeft de GNU General Public Licentie v3 [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html)
