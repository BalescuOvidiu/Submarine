# Submarin dronă - Clasa Metere


<a href = "https://www.youtube.com/watch?v=reCAACpi1qQ" > ![](https://i.imgur.com/9HU73ur.jpg) </a>

## Cuprins

1. [Despre proiect](https://github.com/BalescuOvidiu/Submarine#despre-proiect)<br>
2. [Principiu de construire](https://github.com/BalescuOvidiu/Submarine#principiu-de-construire)<br>
3. [Caracteristici generale](https://github.com/BalescuOvidiu/Submarine#caracteristici-generale)<br>
4. [Compartimente](https://github.com/BalescuOvidiu/Submarine#compartimente)<br>
5. [Circuit electric](https://github.com/BalescuOvidiu/Submarine#circuit-electric)<br>
6. [Dezvoltare](https://github.com/BalescuOvidiu/Submarine#dezvoltare)<br>
7. [Versiuni](https://github.com/BalescuOvidiu/Submarine#versiuni)<br>
7. [Unități](https://github.com/BalescuOvidiu/Submarine#unități)<br>
8. [Rezultate](https://github.com/BalescuOvidiu/Submarine#rezultate)<br>

## Despre proiect

<p align = "justify">
Acest proiect e reprezentat de un tip de vehicul mic capabil să meargă prin apă, controlate printr-o telecomandă sau cu un laptop. Scopul acestuia este de a explora spațiul acvatic, de găsi obiecte pierdute în apă sau pentru divertisment.
</p>
<p align = "justify">
Oceanele ocupă cel puțin 71% din suprafața planetei și cea mai mare parte a lor e neexplorată. Scopul acestui proiect este acela de a promova explorarea, și respectul față de natură.
</p>
<p align = "justify">
O dronă, este un vehicul căruia îi lipsește pilotul uman, fiind ghidat fie de către un pilot automat digital aflat la bordul său, fie prin telecomandă. Un submarin este un vehicul capabil să meargă prin apă la diverse adâncimi și să se ridice la suprafață. Vehiculul acestui proiect este un submarin dronă. Prototipul din imagine a fost testat de câteva ori în lacul Tineretului din București.
</p>
<p align = "justify" id = "video">
Click <a href = "https://www.youtube.com/watch?v=reCAACpi1qQ" >aici</a> pentru a vedea video-ul. 
</p>


## Caracteristici generale

| Nume clasă &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | Metere  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |                                           
|:-----------------|:-------------------------------------|
| Cost unitate | 2067.2 RON   |
| Deplasament   | La suprafață: 6.1 kg  <br> În imersie: 9.1 kg |
| Lungime   | 120.0 cm   |
| Lățime  | 11.0 cm  |
| Pescaj  | 7.0 cm  |
| Propulsie   | <a href = "https://www.pololu.com/category/60/micro-metal-gearmotors">1 motor DC cu reductor 50:1 HPCB 6 V </a><br> <a href = "https://en.wikipedia.org/wiki/Pump-jet">1 pompă cu jet de apă</a>   |
| Viteză  | 5.2 noduri (9.7 km / h)   |
| Autonomie   | 3:10 h   |
| Adâncime operațională   | 1.0 m (3.2 ft) limitată de comunicații  |
| Adâncime maximă   | 20.0 m (65.6 ft)   |
| Rază acoperire comunicații | 1000 m (3280.8 ft) la suprafață |
| Sensori și sisteme de procesare  | 2 <a href = "https://www.optimusdigital.ro/ro/compatibile-cu-arduino-nano/1686-placa-de-dezvoltare-compatibila-cu-arduino-nano-atmega328p-i-ch340.html" >plăci de dezvoltare Arduino Nano v3</a> <br> 1 <a href = "https://www.optimusdigital.ro/ro/ism-24-ghz/119-modul-nrf24l01-pentru-distante-mari.html" >transceiver nRF24L01</a> <br> 1 <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-inertiali/865-modul-senzor-cu-9-axe-mpu9250.html" >IMU MPU9250</a> <br>3 <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-ultrasonici/2943-modul-senzor-ultrasonic-rezistent-la-apa-jsn-sr04t-cu-sonda-pt-masurare-la-distana.html" >senzori de distanță JSN-SR04T</a> |
| Alimentare  | 2 <a href = "https://altex.ro/baterie-externa-promate-energi-10c-10000mah-1xusb-1xtype-c-negru/cpd/AISENERGI10CBK/">baterii externe 5.0 V, 10000 mAh</a> <br>5 <a href = "https://www.emag.ro/acumulatori-reincarcabili-varta-aa-2100-mah-4-buc-hr6-1-2-v-781393/pd/D7B5HLBBM/">acumulatori AA de 1.2 V, 2100 mAh</a> <br>11 <a href = "https://www.soselectronic.ro/products/panasonic/hr-3u-2700-bp4-phr3u2700-4bp-1-56597">acumulatori AA de 1.2 V, 2700 mAh</a><br>8 <a href = "https://www.soselectronic.ro/products/conrad-energy/4aa2500mwh1-6v-bp4-1-153207">acumulatori AA de 1.6 V, 1500 mAh</a>  |


## Principiu de construire

<p align = "justify">
Denumirea clasei vine de la numele celor două materiale principale folosite la construirea corpului interior: metal(oțel în cazul nostru) și polietilenă tereftalată (PET). Principiul de construire constă în combinarea metalului și plasticului astfel încât structura să fie cât mai rezistentă și cât mai ușoară. Oțelul e rezistent, dar greu și oxidabil. Polietilena tereftalată e ușoară, flexibilă, rezistentă chimic la apă, dar fragilă.
</p>
<p align = "justify">
PET-ul este o masă plastică folosită de obicei la fabricarea diverselor ambalaje, care în cele din urmă ajung gunoi și contaminează apa cu microplastic. Totuși aceasta poate fi folosită pentru a proteja câteva circuite de apa rece a mării, iar o structură metalică poate oferi o rezistență deosebită ambalajului de plastic.
</p>
<p align = "justify">
Carcasa submarinul este construită din PVC și este acoperită cu silicon. Același principiu este aplicat cârmelor și hidroplanelor. Siliconul e mult mai rezistent față de cauciuc sau de vopsea și este mult mai ecologic în sensul că nu interacționează cu apa și nu lasă în urmă particule.
</p>
<p align = "justify">
Fiecare compartiment este alcătuit din două capace metalice acoperite pe margini cu bandă de izolare din cauciuc. Câte 4 colțare așezate în formă de cruce sunt așezate pe fiecare capac. Fiecare colțar este conectat cu cel de pe celălalt capac cu o placă de oțel zincat de îmbinare. Toată structura compartimentului este acoperită cu o folie de PET îmbinată de structura metalică cu șuruburi, formând un cilindru. Fiecare compartiment se poate deschide în partea de sus sau dreapta în funcție de componentele lui și de rolul acestuia. Cele două capace metalice ale compartimentului au 8 găuri pentru îmbinarea cu alte compartimente și încă 2 găuri pentru fire. Compartimentele se conectează cu 8 bucăți de tijă filetată de 3 cm.
</p>


## Compartimente

| &nbsp; &nbsp; # | Compartiment &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | &nbsp; &nbsp; # | Compartiment &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; |
|----:|:---------------------------------------------------|----:|:---------------------------------------------------|
| 1 | Camera propulsiei                  | 7  | Tub cu aer comprimat pentru balast             |
| 2 | Compartimentul motoarelor          | 8  | Control sisteme auxiliare                      |
| 3 | Control motoare și servomotoare    | 9  | Camera circuitului central                     |
| 4 | Alimentare motoare și servomotoare | 10 | Alimentare Arduino și senzori                  |
| 5 | Balast                             | 11 | Control hidroplane față și sistem de orientare |
| 6 | Corpul de navigare                 | 12 | Provă                                          |

![](https://i.imgur.com/JQC6UwU.png)


## Circuit electric

<p align = "justify">
Cele două plăci Arduino sunt conectate la cele două baterii externe. Senzorii și modulele auxiliare sunt conectate la sursele de alimentarea al celor două plăci Arduino, la 3.3 V sau 5.0 V în funcție de nevoi. Un comutator este folosit pentru a opri sau porni alimentarea pentru plăcile Arduino.
</p>
<p>
Fiecare motor, sau servomotor e alimentat la câte o sursă de 6.0 V. Fiecare sursă pentru motor are în serie 4 acumulatori AA: 3 de 1.6 V, 1500 mAh și 1 de 1.2 V, 2100 mAh.
Fiecare dintre aceste surse primește semnal de pornire sau de oprire, de la plăcile Arduino prin intermediul unui tranzistor. Atunci când alimentarea celor două plăci sunt oprite, alimentarea motoarelor este oprită. La fel este și atunci când sunt pornite cele două plăci.
</p>

![](https://i.imgur.com/1PS2cFl.png)


## Dezvoltare

<p align = "justify">
Momentan s-au adunat 140 de ore la dezvoltarea acestui tip de dronă: curățarea și prelucrarea anumitor materiale, construirea diverselor componente, asamblarea corpului interior, asamblarea și conectarea componentelor electronice și de asemenea dezvoltarea software. Se vor aduce în continuarea îmbunătățiri și implementări ulterioare.
</p>

#### Viitoare îmbunătățiri

1. Optimizare și îmbunătățire software,
2. Optimizarea consumului curentului electric,
3. Instalarea rezervorului pentru balast,
4. Adăugarea unui generator din cupru și aluminiu care să încarce acumulatorii.

![](https://i.imgur.com/t15tBjh.jpg)


## Versiuni

| # | Data | Descriere                                |
|--:|:-------|:--------------------------------------------------------------------|
| 0.1 | 3 Ianuarie 2018 | Prima versiune.                                          |
| 0.2 | 20 Octombrie 2019 | Compartimentele au fost restructurate și etanșate separat. Carcasa din PET a fost înlocuită cu una din PVC acoperită cu silicon. La fel și aripile. Propulsia cu elice a fost înlocuită cu propulsie pe jet de apă. <br> Receptorul infrarosu a fost înlocuit cu un modul <a href = "https://www.optimusdigital.ro/ro/ism-24-ghz/119-modul-nrf24l01-pentru-distante-mari.html" >transceiver nRF24L01</a>. Bateriile AA de 1.5V au fost înlocuite cu <a href = "https://www.emag.ro/acumulatori-reincarcabili-varta-aa-2100-mah-4-buc-hr6-1-2-v-781393/pd/D7B5HLBBM/">acumulatori AA de 1.2 V, 2100 mAh</a>, <a href = "https://www.soselectronic.ro/products/panasonic/hr-3u-2700-bp4-phr3u2700-4bp-1-56597">acumulatori AA de 1.2 V, 2700 mAh</a> și <a href = "https://www.soselectronic.ro/products/conrad-energy/4aa2500mwh1-6v-bp4-1-153207">acumulatori AA de 1.6 V, 1500 mAh</a>. <br> S-au adăugat: trei senzori de umiditate pentru detectatarea scurgeriilor, un sistem pe bază de tranzistori bipolari de putere pentru controlul surselor de alimentare al motoarelor, un <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-inertiali/865-modul-senzor-cu-9-axe-mpu9250.html" >IMU MPU9250</a> și 3 senzori ultrasonici de distanță <a href = "https://www.optimusdigital.ro/ro/senzori-senzori-ultrasonici/2943-modul-senzor-ultrasonic-rezistent-la-apa-jsn-sr04t-cu-sonda-pt-masurare-la-distana.html" >JSN-SR04T</a>. |


## Unități

<p align = "justify">
În momentul actual proiectul are scop experimental și se urmărește dezvoltarea doar unei singure unități.
</p>

| # | Nume | Versiune | Lansare | Începerea construcției | Dezvoltator | Status |
|:----|:--------|:---------|:----------------------|:----------------|:----------------------------|:----------------------------------------------------|
| ME-212 | Danubius | 0.2 | 3 Ianuarie 2019 | 30 Martie 2020 | Bălescu Ovidiu-Gheorghe | În construcție. Inițial a fost început pentru versiunea 0.1. Din cauza problemelor mecanice ale versiunii 0.1, construcția a fost reluată pentru versiunea 0.2. |


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
