# Документація по MINI YOYO
> Дисклеймер!
> 
> Оригінальна ідея та реалізація Йойо належить "Майстерні Незламності" 24 ОМБр. Нашим завданням було реалізувати цю ідею для DJI Matrice 4T. В ході розробки виявили, що отриманий результат можна використати не тільки для DJI Matrice 4T, а й адаптувати для 3 серії DJI Mavic.
> 
> Всі матеріали, конструкція та ідея ***цієї версії*** Йойо належать "Майстерні Потужності" (робоча назва) ББС 12 бригади спеціального призначення НГУ "Азов".
>
> Автори: Кроп, Азот, Годзі.

## Елементи
1. Arduino Pro Mini 5V
2. Micro-Servo GH-S037 або аналог ідентичного розміру TK-S037
3. Фоторезистор
4. Резистор 10К
5. USB Type-C OTG 
6. USBASP програматор AVR (https://www.rcscomponents.kiev.ua/product/usbasp-prohramator-avr-v2-0-draiver-i-pz-na-saiti-rcscomponents-kiev-ua_46535.html)

## Прошивка
#### ПЕРЕД БУДЬ-ЯКИМИ МАНІПУЛЯЦІЯМИ З ПЛАТОЮ, ЇЇ ТРЕБА ПРОШИТИ.
> Код прошивки можна знайти в репозиторії.

### Як прошивати?
Arduino Pro Mini with Atmega328P 
https://www.instructables.com/Uploading-Sketch-to-Arduino-Pro-Mini-using-usbASP/

Arduino Pro Mini with Atmega328PB
https://www.youtube.com/watch?v=LvKr8gG_WNg

## Cхема пайки
![image](https://github.com/user-attachments/assets/1329a920-41cf-42dc-94a5-5024647e8111)


## Реалізація кнопки відкривання/закривання важеля
Використовується оригінальна кнопки RESET на Arduino Pro Mini. Нам необхідно перерізати доріжки на платі, що відповідають за оригінальну функціональність кнопки. На фото позначено червоними стрілками.
![image](https://github.com/user-attachments/assets/d95cb9b0-bf25-4b54-972e-4f9de62121b9)
![image](https://github.com/user-attachments/assets/3a17b142-0ad7-484c-8fb8-0df016c1c152)
### Результат
Перевірити Мультиметром на продзвонці.
Контакт, що ближчий до 7-8 контактів (нижній на фото) не дзвониться на GND.
Контакт, що ближчий до 11-12 контактів (верхній на фото) не дзвониться на RST.
![signal-2025-07-03-205428_005](https://github.com/user-attachments/assets/1d2521e1-3942-4b28-9ce4-d2b3c4c31f04)
![signal-2025-07-03-205428_004](https://github.com/user-attachments/assets/33845182-f17e-414e-ad3e-4596a48332c4)

Таким чином ми від'єднали кнопку від її оригінальної функції. Вона більше не діє як RESET.
Далі нам треба буде припаяти провід Від верхнього контакту (ближчий до 11-12 контактів) до A0, на який в нас припаяно фоторезистор та резистор. 

Також припаяти провід від нижнього контакту (ближчий до 7-8 контактів) до `VCC`. Ми можемо припаяти проводок напряму до VCC з іншої сторони плати. Або ж використати коротший шлях, припаявшись до дальньої сторони резистора біля контакта 6 (див. фото). Цей контакт іде напряму на VCC.
![image](https://github.com/user-attachments/assets/f5ca3dd2-1051-47f8-b739-8d5595c533f1)

### Що ми цим зробили?
При натисканні кнопки, на контакт A0 будемо подано 5 вольт з VCC, що аналогічно сигналу з фоторезистора, коли на нього світить яскраве світло. По суті, ми імітуємо світіння ліхтариком на фоторезистор, тим самим відкриваючи важіль, що тримає саму йойошку.

## Фінальний вигляд плати
![signal-2025-07-03-205428_006](https://github.com/user-attachments/assets/c14f1f72-e8a4-492a-aa2f-a5e8a7647bb5)

### РОЗТАШУВАННЯ ФОТОРЕЗИСТОРА ЗАЛЕЖИТЬ ВІД МОДЕЛІ ДРОНА, НА ЯКИЙ ВСТАНОВЛЮЄТЬСЯ ЙОЙО. ДИВІТЬСЯ ВІДПОВІДНЕ КРІПЛЕНННЯ.
![signal-2025-07-03-205428_007](https://github.com/user-attachments/assets/14b34dd0-7231-4c41-bd97-fb3970f0a289)

# Покроковий процес збірки
![signal-2025-07-03-205428_010](https://github.com/user-attachments/assets/9c83e9c7-b115-49b3-88c5-e3cf0af5a00c)
![signal-2025-07-03-205428_011](https://github.com/user-attachments/assets/05d672a5-5f40-44e2-bfcf-e3b7c34c1c0a)
![signal-2025-07-03-205428_012](https://github.com/user-attachments/assets/7bb6c14d-0b4f-47e2-b3d4-6ad81c3ce62f)
![signal-2025-07-03-205428_013](https://github.com/user-attachments/assets/12599567-a2fe-445b-8613-03954e661833)
![signal-2025-07-03-205428_014](https://github.com/user-attachments/assets/f3ec567d-f0f9-4551-9af2-d42a6e2905ad)
![signal-2025-07-03-205428_015](https://github.com/user-attachments/assets/0f6545be-8e10-4a9d-8965-4770bde5f69c)
![signal-2025-07-03-205428_016](https://github.com/user-attachments/assets/020e21e2-93ba-49aa-9fa2-8f43d036560d)
![signal-2025-07-03-205428_017](https://github.com/user-attachments/assets/1c06aeba-2768-424d-bd2b-5cd2282a2dfc)
![signal-2025-07-03-205428_018](https://github.com/user-attachments/assets/fa3e20d3-9aca-49b1-95fd-cda0e33f3756)
![signal-2025-07-03-205428_019](https://github.com/user-attachments/assets/1f40a22b-bee8-4f6f-a411-8365a5923ac4)
![signal-2025-07-03-205428_020](https://github.com/user-attachments/assets/f74a021d-73ff-49f5-90a7-f67713916c06)
![signal-2025-07-03-205428_022](https://github.com/user-attachments/assets/26c63cf5-6937-4f79-bfc5-2e07048e3c5d)
![signal-2025-07-03-205428_023](https://github.com/user-attachments/assets/aca5ebdf-f61d-41a0-af8a-baf125292cb2)
![signal-2025-07-03-205428_024](https://github.com/user-attachments/assets/202f9d24-9655-40ce-ab62-6bd592e59387)
![signal-2025-07-03-205428_025](https://github.com/user-attachments/assets/150e567b-e147-4fbf-821e-1e2cd3d7cbef)
![signal-2025-07-03-205428_026](https://github.com/user-attachments/assets/666ba436-77de-443f-9119-9a742a0d01b4)
![signal-2025-07-03-205428_027](https://github.com/user-attachments/assets/9bcb1815-3a85-4ef2-854c-9d70e228f907)
## ПЕРЕД ВСТАНОВЛЕННЯМ ВАЖЕЛЯ, НЕОБХІДНО ПІД'ЄДНАТИ ЙОЙО ДО ЖИВЛЕННЯ, АБИ СЕРВОПРИВІД ВСТАВ У ПОЧАТКОВЕ НУЛЬОВЕ ПОЛОЖЕННЯ.
![signal-2025-07-03-205428_028](https://github.com/user-attachments/assets/087da7d9-67a9-4318-a04c-df33b1dfe8bb)
![signal-2025-07-03-205428_029](https://github.com/user-attachments/assets/eb0bc6ef-2030-44c9-826f-7f9ce37642c3)
## Гвинтик для важеля входить в комплект сервоприводу.
![signal-2025-07-03-205428_030](https://github.com/user-attachments/assets/2d8e1683-c6c4-4792-8a45-6d9340318f62)
![signal-2025-07-03-205428_031](https://github.com/user-attachments/assets/229f7335-23c8-4fd1-be20-851bf0fab271)
![signal-2025-07-03-205428_032](https://github.com/user-attachments/assets/69c0d6db-a624-48a8-9570-d25d9fc834a0)
![signal-2025-07-03-205443](https://github.com/user-attachments/assets/22089ae2-7cf9-4cd7-a0f8-bc9820376ff4)
![signal-2025-07-03-205443_002](https://github.com/user-attachments/assets/0090540f-dce9-48e1-a1cc-8c33dc56b48a)
![signal-2025-07-03-205443_003](https://github.com/user-attachments/assets/4f0f43fc-ec70-430c-a8e8-a1f644ce4114)
![signal-2025-07-03-205443_004](https://github.com/user-attachments/assets/b7b439ae-df01-418b-a1de-1f9e4c1a1a20)


