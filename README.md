# Java_Analizator


## Opis programa
Program radi semantičku analizu Java koda, gde ispisuje gde se greška nalazi i tip greške za dati java fajl. Predstavlja seminarski rad za predmet Konstukcije kompilatora na Matematičkom fakultetu.
---
## Zavisnosti
* [git](https://git-scm.com/) - alati za kontrolu verzije
* [bison](https://www.gnu.org/software/bison/) - paket za parsiranje teksta
* [flex](https://www.gnu.org/software/flex/) -  paket za leksičku analizu teksta
---
## Instaliranje zavisnosti za linux
git
```sh
$ sudo apt-get install git
```
bison
```sh
$ sudo apt-get install bison
```
flex
```sh
$ sudo apt-get install flex
```
---
## Upustva za rukovanje Git-om
Skidanje projekta
```sh
$ git clone https://github.com/NikolaR92/Java_Analizator.git
```
Pravljenje nove grane
```sh
$ git checkout -b naziv_grane
```
Prebacivanje na drugu granu
```sh
$ git checkout master
```
Azuriranje lokalnog koda
```sh
$ git pull
```
Dodavanja promena u kodu na granu
```sh
$ git add *
$ git commit -m "Komentar na promene koda" 
```
Postavljanje promenjenog koda na GitHub
```sh
$ git push origin naziv_grane
```
---

## Kompajliranje koda
```sh
$ make
```
---
## Upustva za rukovanje programom
```sh
$ ./java java_fajl
```
---
## Autori

Jovana Jelenković 169/2014
 
Nikola Ristić 310/2011
