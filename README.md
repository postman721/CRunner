CRunner (C++)

Here is one program that was born as a spin-off of Runner-QT. Meet CRunner: a program written with C++ and using Gtk+. The program is about 60 lines long and heavily commented -> you can easily follow the code.

![crunner](https://user-images.githubusercontent.com/29865797/28171255-79943c38-67f0-11e7-9fa5-2d5a8a7720c9.jpg)


/*CRunner v.1 Copyright (c) 2017 JJ Posti <techtimejourney.net>
#This program comes with ABSOLUTELY NO WARRANTY;
#for details see: http://www.gnu.org/copyleft/gpl.html.
#This is free software, and you are welcome to redistribute it under
#GPL Version 2, June 1991″)*/

You need something along the lines of libgtk-3-dev and build-essential
installed in  order to compile CRunner. Also make sure that you have pkg-config installed.
Compile with the command:
g++ crunner.cpp -o crunner `pkg-config --cflags --libs gtk+-3.0`

-o crunner is the output file.  Adjust cflags and libs to match your system – if needed.

Run the program with this command: ./crunner . If needed make the progam executable with: chmod +x crunner .
Considerations.
Runner-QT and CRunner offer similar features. If any problems appear with Python+QT5 (Runner-QT) then CRunner becomes the default launcher dialog when PostX Gnu/Linux reaches Debian Stretch base.

------
Original post is at:
http://www.techtimejourney.net/crunner-c-is-released/
