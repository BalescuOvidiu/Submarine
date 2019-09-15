# Submarin

Oceanele ocupă cel puțin 71% din suprafața planetei și cea mai mare parte a lor e neexplorată. Ideologia pe care se bazează acest submarin este aceea de respecta oceanele și de a le explora. PET-ul este o masă plastică folosită de obicei la fabricarea diverselor ambalaje, care în cele din urmă ajung gunoi și contaminând apa cu microplastic. Totuși aceasta poate fi folosită pentru a proteja câteva circuite de apa rece a mării. Iar o structură metalică, poate oferi o rezistență deosebită.

Carcasa submarinul este construită din 4 sticle de PET lipite între ele și vopsită cu două straturi de lac de lemn. Structura interioară a submarinului se bazează pe un schelet metalic construit din plăcuțe de îmbinare, colțare și capace metalice. de asemnea fiecare compartiment a structurii are o carcasă proprie de PET Componentele electronice, motoarele și senzorii, sunt controlate cu o placă de dezvoltare Arduino Nano. Submarinul a fost testat de câteva ori în lacul Tineretului din București, un video [aici](https://www.youtube.com/watch?v=reCAACpi1qQ|alt=octocat).

![Pe apă](https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/onWater.jpg "În Parcul Tineretului pe lac")


## Proiect la cursul de Robotică

| Universitatea București | Facultatea de Matematică și Informatică |
|:------------------------|:----------------------------------------|
| Profesor coordonator    | Bardezi Andrei                          |  
| Laborant                | Ivona Octavia                           |
| Student                 | Bălescu Ovidiu-Gheorghe                 |


## Caracteristici generale

| Nume 	| UB-FMI-212 	|
|:-----------------|:-------------------------|
| Cost 	| 457.5 RON 	|
| Deplasament 	| 2.5 kg 	|
| Lungime 	| 95.0 cm 	|
| Lățime 	| 9 cm 	|
| Pescaj 	| 5 cm 	|
| Propulsie 	| 1 Motor HPCB 6 V 1 Elice cu 7 lame 	|
| Viteză 	| 5.2 noduri (9.7 km / h) 	|
| Automonie 	| 5 ore 	|
| Adâncime operațională 	| 5 metri 	|
| Sensori și  sisteme de procesare 	| 1 placă de dezvoltare Arduino Nano <br> 1 receptor infra-roșu pentru telecomandă <br> 1 senzor de umiditate pentru detectarea scurgeriilor 	|
| Alimentare 	| 4 acumulatori 1.2 V, 2100 mAh <br> 8 acumulatori 1.6 V, 1500 mAh 	|



<table>
   <tr>
     <td valign="top" width="70%">
      <img src="https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/parts.png"/>
     </td>
     <td valign="top" width="30%">
      Compartimente
      <ol>
        <li>Camera propulsiei</li>
        <li>Camera de control al motoarelor</li>
        <li>Camera circuitelor</li>
        <li>Corpul de navigare</li>
        <li>Camera bateriilor</li>
        <li>Pernă de aer</li>
      </ol>
     </td>
  </tr>
</table>

<img src="https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/schem.png"/>

<table>
  <tr>
    <td valign="top" width="40%">
      Dezvoltare
      Momentan s-au adunat 120 de ore de lucru la construirea acestui prototip: curățarea sticlelor și conservelor, modelarea carcasei și aripiilor,  construirea scheletului, asamblarea și conectarea componentelor electronice.
      Acesta este încă în dezvoltare, urmând să aibe implementări și îmbunătățiri ulterioare.
      Viitoare implementări
      <ol>
        <li>Îmbunătățirea scheletului</li>
        <li>Etanșarea și modularizarea carcasei</li>
        <li>Implementarea balastului</li>
        <li>Implementarea unei device de orientare</li>
        <li>Adăugarea unui generator din cupru și aluminiu care să încarce acumulatorii</li>
      </ol>  
    </td valign="top" width="60%">
    <td>
      <img src="https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/inside.jpg"/>
    </td>
  </tr>
</table>
