# A simple mario sokoban game written in c using sdl library
## Linux user 
###   -before run the game you must install sdl 1.2 version(version is important)  library first with command : "apt-get install libsdl1.2-dev"
###   - you can start the game by execute the  compiled file main in "Sources" folder, just tap "./main"
        -when you get on menu press 1 button and the game will start
###   - for compile just use the make command or  gcc main.c game.c file.c custom.c  -o main -lSDL_image   `sdl-config --libs --cflags --static-libs  `
#i used sdl 1.2 version library , if you dont install it won't compile
#
#if you're on linux for debian distribution  just tap in command "apt-get install libsdl1.2-dev"
#
#for other platform google it, its really easy to install it
#
#if you're on linux just  compile the file by using the makefile or you tap :
# gcc main.c game.c file.c custom.c  -o main -lSDL_image   `sdl-config --libs --cflags --static-libs  `
