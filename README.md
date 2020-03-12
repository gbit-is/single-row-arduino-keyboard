# SRAK
## Single Row Arduino Keyboard

# What is it ?
a code snipped to create a small, cheap keyboard without resistors, diodes or a matrix configuration. Simple solution for a small macropad for example. This supports a maximum of 16 keys.

Why not use a teensy or QMK or [insert your preference] ?

If you wanna use that, use that. I don´t claim this is the best method, this is just the one I am using with my stockpile of arduinos

# Example
I use the UHK60 keyboard, I wanted a few extra keys so I created the macro pad on the right and the arrow keys in the middle there. Both of these keyboards are built with an arduino pro micro, this codebase and "amoeba" PCB's from keeb.io

![alt text](https://raw.githubusercontent.com/gbit-is/single-row-arduino-keyboard/master/img/example.jpg "Image of split keyboard and 2 small macro pads")


# How to use

This design uses a single common line, not a matrix and therefor there is no need for diodes, the common line is ground and the internal arduino pull-ups are used so there is no need for resistors.

First you have to decide if you want to use strings or ascii codes

### Strings 

##### Pros 
- easily readable in the code
- each key is capable of printing out a string, not just a single character
##### Cons
- cannot use special keys

### Ascii codes

##### Pros 
- special keys are avaivable (ctrl, alt, up_arrow, etc)

##### Cons 
- Not as easily readable in the code 
- each key can only press one key


##### Can I mix and match ?      
Not without modifying this code      
or use another implementation     
or wait until I make that code pretty enough to put on git without feeling ashamed           


### Config

- Connect one side of all switches to ground
- Connect the other side of each switch to a pin on the arduino
- List all pins used in the myPins array on line 14
- depending on if you are using the Strings or Ascii method, add your keys to line 24 or 31
- Edit lines 73-77 to either ouput schar (ascii) or scharS (strings)


# Example diagram



![alt text](https://raw.githubusercontent.com/gbit-is/single-row-arduino-keyboard/master/img/connection_diagram.png "connection diagram image")

