# Oled-W-Click-board

![20220427_154016](https://user-images.githubusercontent.com/30090189/165735767-21bac92e-7097-426b-8313-cb906070b536.jpg)

Oled W click is a click board for interfacing MikroElektronika mikroBUS sockets. It is based on an OLED SSD1306 128x64 display. It use I2C interface and 3.3V power supply.

There are few additional pins that Oled W click use. RST pin is for Reset function. CS pin enables communication to the MCU and in that matter it had to be pulled LOW. Otherwise, Oled W click is inactive. SDA and SCL are pins of I2C interface.

![20220427_154021](https://user-images.githubusercontent.com/30090189/165739596-6fef81d0-0b96-4491-9646-10576d6a1459.jpg)

Here you will find schematic, and an example. 

Example is tested on Flip&Click SAM3X. Besides Flip&Click SAM3X, and Oled W click, I used a Pressure 4 click. Oled W in C socket, and Pressure 4 in D socket.

![20220427_154046](https://user-images.githubusercontent.com/30090189/165739829-0b12b31e-420b-4f44-abb6-4418a8fb765c.jpg)
