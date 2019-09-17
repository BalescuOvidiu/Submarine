# Submarin dronă - Clasa Metere


## Cuprins

1. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#despre-proiect">
Despre proiect
</a>
2. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#principiu-de-construire">
Principiu de construire
</a>
3. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#caracteristici-generale">Caracteristici generale</a>
4. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#compartimente">Compartimente</a>
5. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#circuit-electric">Circuit electric</a>
6. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#dezvoltare">Dezvoltare</a>
7. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#unități">Unități</a>
8. <a href="https://github.com/BalescuOvidiu/Submarine/blob/master/README.md#rezultate">Rezultate</a>


## Despre proiect

<p align = "justify">
Oceanele ocupă cel puțin 71% din suprafața planetei și cea mai mare parte a lor e neexplorată. Ideologia pe care se bazează această clasă de submarin este aceea de a respecta oceanele și de a le explora.
</p>
<p align = "justify">
O dronă, este un vehicul căruia îi lipsește pilotul uman, fiind ghidat fie de către un pilot automat digital aflat la bordul său, fie prin telecomandă de la un centru de control de la sol sau care este situat în alt vehicul.
</p>
<p align = "justify">
PET-ul este o masă plastică folosită de obicei la fabricarea diverselor ambalaje, care în cele din urmă ajung gunoi și contaminează apa cu microplastic. Totuși aceasta poate fi folosită pentru a proteja câteva circuite de apa rece a mării. Iar o structură metalică, poate oferi o rezistență deosebită.
</p>
<p align = "justify">
Submarinul a fost testat de câteva ori în lacul Tineretului din București. Click <a href = "https://www.youtube.com/watch?v=reCAACpi1qQ" >aici</a> pentru a vedea video-ul. 
</p>

<img src = "https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/onWater.jpg"/>


## Principiu de construire

<p align = "justify">
Denumirea clasei vine de la metal și polietilenă tereftalată (PET). Principiul de construire constă în obținerea unei construcții din metal și plastic cu proprietăți similare a unei construcții complet făcută din metal. Oțelul e rezistent, dar greu și oxidabil. Polietilena tereftalată e ușor, flexibil, rezistent la apă, dar fragil.
Carcasa submarinul este construită din 4 sticle de PET lipite între ele și este vopsită cu două straturi de lac de lemn. Structura interioară a submarinului se bazează pe un schelet metalic construit din plăcuțe de îmbinare, colțare și capace metalice. De asemenea fiecare compartiment a structurii are o carcasă proprie de PET.
</p>


## Caracteristici generale

| Nume clasă  | Metere  |
|:-----------------|:-------------------------------------|
| Cost unitate | 457.5 RON   |
| Deplasament   | 2.5 kg  |
| Lungime   | 95.0 cm   |
| Lățime  | 9.0 cm  |
| Pescaj  | 5.0 cm  |
| Propulsie   | 1 motor HPCB 6 V <br> 1 elice cu 7 lame   |
| Viteză  | 5.2 noduri (9.7 km / h)   |
| Autonomie   | 5:00 ore   |
| Adâncime operațională   | 5.0 metri   |
| Sensori și  sisteme de procesare  | 1 placă de dezvoltare Arduino Nano <br> 1 receptor infra-roșu pentru telecomandă <br> 1 senzor de umiditate pentru detectarea scurgeriilor  |
| Alimentare  | 4 acumulatori 1.2 V, 2100 mAh <br> 8 acumulatori 1.6 V, 1500 mAh  |


## Compartimente

|#|Compartiment|#|Compartiment|
|-------------:|:---------------------|---------------:|:---------------------|
| 1 | Camera propulsiei | 6 | Alimentare Arduino și sensori |
| 2 | Control hidroplane spate | 7 | Arduino și sensori |
| 3 | Alimentare Hidroplane | 8 | Corpul de navigare |
| 4 | Alimentare cârme | 9 | Control hidroplane față |
| 5 | Balast | 10 | Stabilizator |

![](https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/parts.png?raw=true)


## Circuit electric

<p align = "justify">
Componentele electronice, motoarele și senzorii, sunt controlate cu o placă de dezvoltare Arduino Nano V3. Toate aceastea sunt alimentate cu acumulatori de tip AA, cu o tensiune de 1.2 V sau 1.6 V, grupate în serie câte patru. Placa arduino și fiecare motor au o sursă de alimentare proprie. Senzorii sunt alimentați la 3.3 V sau 5 V la placa Arduino.
</p>

![](https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/schem.png)


## Dezvoltare

<p align = "justify">
Momentan s-au adunat 120 de ore de lucru la construirea acestui prototip: curățarea sticlelor modelarea carcasei, cârmelor și hidroplanelor, construirea scheletului, asamblarea și conectarea componentelor electronice și de asemenea dezvoltarea software. Acesta este încă în dezvoltare, urmând să aibe implementări și îmbunătățiri ulterioare.
</p>

__Viitoare implementări:__

1. Implementarea balastului,
2. Implementarea unei device de orientare,
3. Adăugarea unui generator din cupru și aluminiu care să încarce acumulatorii.

![](https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/inside.jpg)


## Unități

<p align = "justify">
Documentația unei clase de submarin conține și un tabel cu unitățiile construite. În momentul de față se urmărește doar dezvoltarea unei singure unități, proiectul având mai mult un scop educativ.
</p>

| # | Nume | Dezvoltator | Primul test | Stare |
|:-|:------|:-----------|:-------------------------------|:-------------------|
| ME - 212 | Delfinul | Bălescu Ovidiu-Gheorghe | 23 Aprilie 2019 | În dezvoltare |


## Rezultate

#### Proiect la cursul de Introducere în Robotică, anul universitar 2018 - 2019

| Universitatea București | Facultatea de Matematică și Informatică |
|:------------------------|:----------------------------------------|
| Profesor coordonator    | Dumitriu Andrei                         |  
| Laborant                | Ivona Octavia                           |
| Student                 | Bălescu Ovidiu-Gheorghe                 |
| Notă evaluare           | 10 / 10                                 |


#### Proiect prezentat la Sesiunea de comunicări Științifice Studențești - 2019

| Universitatea București | Facultatea de Matematică și Informatică |
|:------------------------|:----------------------------------------|
| Profesor coordonator    | Dumitriu Andrei                         |  
| Student                 | Bălescu Ovidiu-Gheorghe                 |
| Loc                     | II                                      |