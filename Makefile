build:
	g++ src/*.cpp -Iinclude -o pinf -lsfml-graphics -lsfml-window -lsfml-system -Wall -Wextra

run: build
	cls
	pinf.exe

report:
	cls
	loc --include cpp hpp