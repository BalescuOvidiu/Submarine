# Submarin dronă - Clasa Metere


![](https://raw.githubusercontent.com/BalescuOvidiu/Submarine/master/img/Surface.jpg)

## Cuprins

1. [Despre proiect](https://github.com/BalescuOvidiu/Submarine#despre-proiect)<br>
3. [Caracteristici generale](https://github.com/BalescuOvidiu/Submarine#caracteristici-generale)<br>
2. [Structură](https://github.com/BalescuOvidiu/Submarine#structură)<br>
5. [Circuit electric](https://github.com/BalescuOvidiu/Submarine#circuit-electric)<br>
5. [Software](https://github.com/BalescuOvidiu/Submarine#software)<br>
6. [Viitoare îmbunătățiri](https://github.com/BalescuOvidiu/Submarine#viitoare-îmbunătățiri)<br>
7. [Versiuni](https://github.com/BalescuOvidiu/Submarine#versiuni)<br>
7. [Unități](https://github.com/BalescuOvidiu/Submarine#unități)<br>
7. [Teste](https://github.com/BalescuOvidiu/Submarine#teste)<br>
8. [Rezultate](https://github.com/BalescuOvidiu/Submarine#rezultate)<br>

## Despre proiect

<p align = "justify">
Acest proiect e reprezentat de un tip de vehicul mic capabil să meargă prin apă, controlate printr-o telecomandă sau cu un laptop. Scopul acestuia este de a explora spațiul acvatic, de găsi obiecte pierdute în apă sau pentru divertisment.
</p>
<p align = "justify">
O dronă, este un vehicul căruia îi lipsește pilotul uman, fiind ghidat fie de către un pilot automat digital aflat la bordul său, fie prin telecomandă. Un submarin este un vehicul capabil să meargă prin apă la diverse adâncimi și să se ridice la suprafață. Vehiculul acestui proiect este un submarin dronă. 
</p>


## Caracteristici generale

| Nume clasă &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Metere  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |                                           
|:-----------------|:-------------------------------------|
| Cost unitate | 1630.10 RON   |
| Deplasament  | La suprafață: 5.8 kg  <br> În imersie: 9.1 kg |
| Lungime      | 120.0 cm   |
| Lățime       | 10.0 cm  |
| Pescaj       | 7.0 cm  |
| Propulsie    | <a href = "https://www.pololu.com/category/60/micro-metal-gearmotors">1 motor DC cu reductor 50:1 HPCB 6 V </a><br> <a href = "https://en.wikipedia.org/wiki/Pump-jet">1 elice cu 7 lame pompă-jet</a>   |
| Viteză  | 5.2 noduri (9.7 km / h)   |
| Autonomie    | 3 ore  |
| Adâncime operațională   | 1.0 m (3.2 ft) fără cablu  |
| Adâncime maximă   | 10.0 m (65.6 ft)   |
| Rază acoperire comunicații | 1000 m (3280.8 ft) la suprafață |
| Sensori și sisteme de procesare  | 2 <a href = "https://www.optimusdigital.ro/ro/compatibile-cu-arduino-nano/1686-placa-de-dezvoltare-compatibila-cu-arduino-nano-atmega328p-i-ch340.html" >plăci de dezvoltare Arduino Nano v3</a> <br> 1 <a href = "https://www.optimusdigital.ro/ro/ism-24-ghz/119-modul-nrf24l01-pentru-distante-mari.html" >transceiver nRF24L01</a> <br> 1 <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-inertiali/865-modul-senzor-cu-9-axe-mpu9250.html" >IMU MPU9250</a> <br>3 <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-ultrasonici/2943-modul-senzor-ultrasonic-rezistent-la-apa-jsn-sr04t-cu-sonda-pt-masurare-la-distana.html" >senzori de distanță JSN-SR04T</a> |
| Alimentare  | 6 <a href = "https://www.soselectronic.ro/products/panasonic/hr-3u-2700-bp4-phr3u2700-4bp-1-56597">acumulatori AA de 1.2 V, 2700 mAh</a><br>18 <a href = "https://www.soselectronic.ro/products/conrad-energy/4aa2500mwh1-6v-bp4-1-153207">acumulatori AA de 1.6 V, 1500 mAh</a>  |


## Structură

<p align = "justify">
Denumirea clasei vine de la numele celor două materiale principale folosite la construirea corpului interior: metal(oțel în cazul nostru) și polietilenă tereftalată (PET). Principiul de construire constă în combinarea metalului și plasticului astfel încât structura să fie cât mai rezistentă și cât mai ușoară. Oțelul e rezistent, dar greu și oxidabil. Polietilena tereftalată e ușoară, flexibilă, nu ruginește, dar fragilă.
</p>
<p align = "justify">
PET-ul este o masă plastică folosită de obicei la fabricarea diverselor ambalaje, care în cele din urmă ajung gunoi și contaminează apa cu microplastic. Totuși aceasta poate fi folosită pentru a proteja câteva circuite de apa rece a mării, iar o structură metalică poate oferi o rezistență deosebită ambalajului de plastic.
</p>
<p align = "justify">
Carcasa submarinul este construită din PET și este acoperită cu silicon. Același principiu este aplicat cârmelor și hidroplanelor. Siliconul e mult mai rezistent față de cauciuc sau de vopsea și este mult mai ecologic în sensul că nu interacționează cu apa și nu lasă în urmă particule.
</p>
<p align = "justify">
Structura este modulară pentru a fi ușor de reparat. Fiecare compartiment este alcătuit din două capace metalice conectate cu 4 colțare așezate în formă de cruce. Fiecare colțar este conectat cu cel de pe celălalt capac cu o placă de oțel zincat de îmbinare. Toată structura compartimentului este acoperită cu o folie de PET îmbinată de structura metalică cu șuruburi, formând un cilindru. Fiecare compartiment se poate deschide în partea de sus. Cele două capace metalice ale compartimentului au 8 găuri pentru îmbinarea cu alte compartimente și încă 2 găuri pentru fire. Compartimentele sunt conectate cu 4 plăci de îmbinare zincate.
</p>


![](https://raw.githubusercontent.com/BalescuOvidiu/Submarine/master/img/Inside.jpg)


#### Compartimente

| &nbsp; &nbsp; # | Compartiment &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | &nbsp; &nbsp; # | Compartiment &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
|----:|:---------------------------------------------------|----:|:---------------------------------------------------|
| 1 | Camera propulsiei                  | 7  | Compartiment utilitar                          |
| 2 | Compartimentul motoarelor          | 8  | Control sisteme auxiliare                      |
| 3 | Alimentare motoare și servomotoare | 9  | Alimentare Arduino și senzori                  |
| 4 | Control motoare și servomotoare    | 10 | Camera circuitului central                     |
| 5 | Compartiment utilitar              | 11 | Control hidroplane față și sistem de orientare |
| 6 | Corpul de navigare                 | 12 | Provă                                          |

![](https://raw.githubusercontent.com/BalescuOvidiu/Submarine/master/img/Compartments.png)


## Circuit electric

<p align = "justify">
Cele două plăci Arduino sunt conectate la cele două baterii externe. Senzorii și modulele auxiliare sunt conectate la sursele de alimentarea al celor două plăci Arduino, la 3.3 V sau 5.0 V în funcție de nevoi. Un comutator este folosit pentru a opri sau porni alimentarea pentru plăcile Arduino.
</p>
<p>
Fiecare motor, sau servomotor e alimentat la câte o sursă de 6.0 V. Fiecare sursă pentru motor are în serie 4 acumulatori AA: 3 de 1.6 V, 1500 mAh și 1 de 1.2 V, 2700 mAh.
Fiecare dintre aceste surse primește semnal de pornire sau de oprire, de la plăcile Arduino prin intermediul unui tranzistor. Atunci când alimentarea celor două plăci sunt oprite, alimentarea motoarelor este oprită. La fel este și atunci când sunt pornite cele două plăci.
</p>

![](https://raw.githubusercontent.com/BalescuOvidiu/Submarine/master/img/Schematic.png)


## Software
<p align = "justify">
Programele pentru plăcile <a href = "https://www.arduino.cc/">Arduino</a> de pe vehicul și telecomandă au fost scrise în C++ pentru arhitectura ARV, microcontrolere.</p>
<p align = "justify">
Interfața grafică a fost scrisă în limbajul <a href = "http://www.cplusplus.com/">C++ 11</a> folosind framework-ul <a href = "https://www.sfml-dev.org/">SFML 2.5.1</a>. Aceasta are scopul de a vizualiza datele de la senzorii submarinului și de controla componentele de pe acesta.</p>

![](https://raw.githubusercontent.com/BalescuOvidiu/Submarine/master/img/ScreenshotGraphicInterface.png)

#### Cerințe minime sistem pentru interfață
1. Procesor DualCore 2.0 GHz,
2. DDR2 RAM 2G,
3. Placă video 256MB,
4. Sistem de operare Linux, Windows sau Mac. 

## Viitoare îmbunătățiri
1. Optimizare și îmbunătățire software,
2. Optimizarea consumului curentului electric,
3. Instalarea unei camere,
4. Adăugarea unui generator din cupru și aluminiu care să încarce acumulatorii.


## Versiuni

| # | Data | Descriere                                |
|--:|:-------|:--------------------------------------------------------------------|
| 0.2 | 20 Octombrie 2019 | Compartimentele au fost restructurate și etanșate separat. Carcasa din PET a fost reconstruită și acoperită cu silicon. La fel și aripile. Propulsia cu elice 7 lame a fost înlocuită cu elice cu 7 lame pompă-jet.<br> Servomotoarele <a href="https://www.optimusdigital.ro/ro/motoare-servomotoare/271-servomotor-mg90s.html">MG90S</a> montate anterior au fost înlocuite cu <a href="https://www.optimusdigital.ro/ro/motoare-servomotoare/1160-servomotor-metalic-digital-mg996.html">MG996</a> și s-a adăugat unul pentru planele de scufundare din față. <br> Receptorul infrarosu a fost înlocuit cu un modul <a href = "https://www.optimusdigital.ro/ro/ism-24-ghz/119-modul-nrf24l01-pentru-distante-mari.html" >transceiver nRF24L01</a>. Bateriile AA de 1.5V au fost înlocuite cu <a href = "https://www.soselectronic.ro/products/panasonic/hr-3u-2700-bp4-phr3u2700-4bp-1-56597">acumulatori AA de 1.2 V, 2700 mAh</a> și <a href = "https://www.soselectronic.ro/products/conrad-energy/4aa2500mwh1-6v-bp4-1-153207">acumulatori AA de 1.6 V, 1500 mAh</a>. <br> S-au adăugat: trei senzori de umiditate pentru detectatarea scurgeriilor, un sistem pe bază de tranzistori bipolari de putere pentru controlul surselor de alimentare al motoarelor, un <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-inertiali/865-modul-senzor-cu-9-axe-mpu9250.html" >IMU MPU9250</a> și 3 senzori ultrasonici de distanță <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-ultrasonici/2943-modul-senzor-ultrasonic-rezistent-la-apa-jsn-sr04t-cu-sonda-pt-masurare-la-distana.html" >JSN-SR04T</a>. |
| 0.1 | 1 Ianuarie 2019 | Prima versiune.                                          |



## Unități

<p align = "justify">
În momentul actual proiectul este în faza experimentală și se urmărește dezvoltarea doar unei singure unități.
</p>

| # | Nume | Versiune | Lansare | Începerea construcției | Dezvoltator | Status |
|:----|:--------|:---------|:----------------------|:----------------|:----------------------------|:----------------------------------------------------|
| ME-212 | Danubius | 0.1 | 16 Aprilie 2019 | 1 Ianuarie 2019 | Bălescu Ovidiu-Gheorghe | În construcție pentru a trece la versiunea 0.2 |


## Teste

#### Testare versiunea 0.1 - 16 Aprilie 2019 
<p align = "justify">
S-a desfășurat pe lacul din Parcul Tineretului, București. S-a deplasat fără probleme la suprafața apei, dar nu a reușit să execute o submersie. 
Problema era cauzată de planele de scufundare din față, fiind fixate(nu erau conectate la un motor, ci doar lipite). Asta nu a permis să încline submarinul cu botul în jos și să execute o submersie dinamică. Carcasa din PET acoperită cu lac de lemn nu a permis apei să intre, dar în urma unor șocuri mecanice s-a observat că lacul întărit se desprinde de pe plastic.
Click <a href = "https://drive.google.com/file/d/1TcdASmKPXG35pqwhGr6TglmWBqajAN5j/view?usp=share_link" >aici</a> pentru a vedea video-ul. 
</p>


## Rezultate

#### Proiect la cursul de Introducere în Robotică, anul universitar 2018 - 2019

| Universitatea București &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Facultatea de Matematică și Informatică &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
|:------------------------|:---------------------------------------------------------------|
| Profesor coordonator    | Dumitriu Andrei                                                |
| Laborant                | Octavia Ivona                                                  |
| Student                 | Bălescu Ovidiu-Gheorghe                                        |
| Notă evaluare           | 10 / 10                                                        |


#### Proiect prezentat la Sesiunea de comunicări Științifice Studențești - 2019

| Universitatea București &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Facultatea de Matematică și Informatică &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
|:------------------------|:---------------------------------------------------------------|
| Profesor coordonator    | Dumitriu Andrei                                                |  
| Student                 | Bălescu Ovidiu-Gheorghe                                        |
| Loc                     | II                                                             |
