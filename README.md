## Raise the terrain

### Description:
Learn how to use the SDL2 package in C to 
draw a simple grid using isometric projection.

###Installaion:
Prerequisite: You must have the gcc compiler and SDL2 package installed on your machine to run this code.
1) Clone this repo by typing this into your command line: git clone https://github.com/petehwu/Raise\_the\_terrain.git
2) change directory into the repo by typing: cd Raise\_the\_terrain
3) Compile this code by typing: ./compile\_this inside the Raise\_the\_terrain folder
4) Once compiled you can run the executable using either of the supplied z\_axis value files
terrain z\_axis  or terrain zeros   Alternatively you can create your own z\_axis file by copying the zeros file and changing the 0 values to a value you prefer. 


### Files
File|Description
---|---
compile\_this | bash script used to compile the program
header.h | header file containing prototypes of all functions and structs used
helper.c | helper functions
init.c | functions to initialize the SDL session and draw
main.c | main entry point into the program
z\_axis | files containing the z-axis values for the 8x8 grid
zeros | files containint all 0s for the z-axis values for the 8x8 grid 

### Author
Peter Wu
