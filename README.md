# Submarin

## Proiect la cursul de Robotică
#### Universitatea București - Facultatea de Matematică și Informatică

**Profesor coordonator**: Bardezi Andrei  
**Laborant**: Ivona Octavia  
**Student**: Bălescu Ovidiu-Gheorghe  


<table>
  <tr>
    <td valign="top" width="50%">
      Proiect la cursul de Robotică, reprezentat de un submarin controlabil printr-o telecomandă, încă în dezvoltare. Acesta are ca scop de a încuraja reciclarea și explorarea oceanelor.
      Oceanele ocupă aproximativ 71% din suprafața planetei și cea mai mare parte a lor e neexplorată.
      Carcasa submarinul este construită din 4 sticle de PET susținută de un schelet metalic și acoperită cu lac de lemn. Aripile și cârmele sunt construite din tabla de la conserve, acoperite cu PET. Toate acestea sunt înfășurate în bandă adezivă și acoperite cu lac de lemn.
      <a href="https://www.youtube.com/watch?v=reCAACpi1qQ">Video</a>
    </td>
    <td valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/BalescuOvidiu/Submarin/master/img/onWater.jpg"/>
    </td>
  </tr>
</table>

## Caracteristici generale

| Caracteristici generale  |                                                                                                                        |
|-------------------------------|-------------------------------------------------------------------------------------|
| Nume                             | UB-FMI-212                                                                                                              |
| Deplasament                      | 2.5 kg                                                                                                                  |
| Lungime                          | 95.0 cm                                                                                                                 |
| Lățime                           | 9 cm                                                                                                                    |
| Pescaj                           | 5 cm                                                                                                                    |
| Propulsie                        | 1 Motor HPCB 6 V 1 Elice cu 7 lame                                                                                      |
| Viteză                           | 5.2 noduri (9.7 km / h)                                                                                                 |
| Automonie                        | 5 ore                                                                                                                   |
| Adâncime operațională            | 5 metri                                                                                                                 |
| Sensori și <br> sisteme de procesare | 1 placă de dezvoltare Arduino Nano <br>1 receptor infra-roșu pentru telecomandă <br> 1 senzor de umiditate pentru detectarea scurgeriilor |
| Alimentare                       | 4 acumulatori 1.2 V, 2100 mAh <br> 8 acumulatori 1.6 V, 1500 mAh                                                                     |


<table><tr>
<td valign="top" width="35%"></td>
<td valign="top" width="65%"><table>
  <tr>
      <td>Nume</td>
      <td>Cantitate</td>
      <td>Preț unitar</td>
      <td>Preț total</td>
  </tr>
  <tr>
      <td>Arduino Nano V3</td>
      <td>1</td>
      <td>20 RON</td>
      <td>20 RON</td>
  </tr>
  <tr>
      <td>Breadboard alb</td>
      <td>1</td>
      <td>8 RON</td>
      <td>8 RON</td>
  </tr>
  <tr>
      <td>Servomotor</td>
      <td>3</td>
      <td>20 RON</td>
      <td>60 RON</td>
  </tr>
  <tr>
      <td>Motor DC Pololu 250:1 6 V</td>
      <td>1</td>
      <td>77 RON</td>
      <td>77 RON</td>
  </tr>
  <tr>
      <td>Driver de motoare Dual L9110S</td>
      <td>1</td>
      <td>8 RON</td>
      <td>8 RON</td>
  </tr>
  <tr>
      <td>LED RGB</td>
      <td>1</td>
      <td>1 RON</td>
      <td>1 RON</td>
  </tr>
  <tr>
      <td>Receptor infraroșu</td>
      <td>1</td>
      <td>8 RON</td>
      <td>8 RON</td>
  </tr>
  <tr>
      <td>Set fire</td>
      <td>4</td>
      <td>10 RON</td>
      <td>40 RON</td>
  </tr>
  <tr>
      <td>Baterie externă de 5 V, 2200 mAh</td>
      <td>1</td>
      <td>20 RON</td>
      <td>20 RON</td>
  </tr>
  <tr>
      <td>Suport baterii pătrat 4 x 1.5 V</td>
      <td>2</td>
      <td>10 RON</td>
      <td>20 RON</td>
  </tr>
  <tr>
      <td>Colțar metalic</td>
      <td>24</td>
      <td>1 RON</td>
      <td>24 RON</td>
  </tr>
  <tr>
      <td>Placă îmbinare</td>
      <td>12</td>
      <td>3 RON</td>
      <td>36 RON</td>
  </tr>
  <tr>
      <td>Bandă reparații gri 50 m x 50 mm</td>
      <td>1</td>
      <td>50 RON</td>
      <td>50 RON</td>
  </tr>
  <tr>
      <td>Lac protector</td>
      <td>0.2</td>
      <td>29 RON</td>
      <td>5.4 RON</td>
  </tr>
  <tr>
      <td>Vopsea</td>
      <td>0.5</td>
      <td>19 RON</td>
      <td>9.5 RON</td>
  </tr>
  <tr>
      <td>Inel de strângere</td>
      <td>1</td>
      <td>19 RON</td>
      <td>19 RON</td>
  </tr>
</table></td>
</tr></table>

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
