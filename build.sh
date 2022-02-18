gcc -o build/out.exe main.c -O1 -Wall -std=c99 -Wno-missing-braces -I libs/ -L build/ -lraylib -lopengl32 -lwinmm -lgdi32 -ldiscord_game_sdk
cd build
start out.exe

