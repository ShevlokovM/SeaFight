# SeaFight
Учебная работа - симулятор игры в морской бой
![](https://github.com/ShevlokovM/SeaFight/blob/main/morskoi-boi1.png) 
<img src="[drawing.jpg](https://github.com/ShevlokovM/SeaFight/blob/main/morskoi-boi1.png)" alt="[drawing](https://github.com/ShevlokovM/SeaFight/blob/main/morskoi-boi1)" width="200"/>

## Технологии
- C++
- функции
- матрицы и алгоритмы над ними

## Описание
Программа симулирует известную игру "Морской бой" в командной строке. Это не полноценная игра, т.к. противникам будут видны поля друг друга, и играть можно только при пионерской честности противников.

## Описание процесса

## Заполнение полей
- копируете main.cpp, и вставляете в любую среду разработки, запускаете
- в командной строке появится два пустых поля, которые по-очереди должны заполнить соперники
- программа предложит ввести данные кораблей, конкретизируя корабль на сколько палуб нужно ввести в данный момент
- вводите координаты через Enter. Сначала вертикальную, потом горизонтальную.
- если корабль многопалубный, вводите координаты начала и конца. Если ошибетесь, программа сообщит, и предложит ввести еще раз
- корабли можно размещать как вертикально, так и горизонтально, а так же вплотную друг к другу. "Наезжать" одним кораблем на другой - нельзя!!!

## Сражение
- как только все поля будут заполнены, начинается битва, и одному из игроков будет предложено нанести удар
- для этого, вводятся координаты. Как и в случае с размещением кораблей, вводите координаты через Enter. Сначала вертикальную, потом горизонтальную.
- если ошибетесь, выйдете за пределы поля, или ударите по уже отработанным клеткам, программа сообщит, и предложит ввести еще раз.
- после каждого удара, Вам будет показано поле противника, с результатами ваших ударов.
- попадание в корабль будет отмечено буквой 'X', промах - значком '*';
- в случае попадания, вам будет предложено сделать еще один ход.
- в случае промаха, происходит переход хода к сопернику

# Наслаждайтесь)
![](https://github.com/ShevlokovM/SeaFight/blob/main/%D0%BC%D0%BE%D1%80%D1%81%D0%BA%D0%BE%D0%B9%20%D0%B1%D0%BE%D0%B9.jpg)
