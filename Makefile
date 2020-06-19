#list of files for compilation
OBJS = Main.cpp Sprite.cpp View.cpp Board.cpp GameManager.cpp KeyBoardInputs.cpp

#compiler
CC = g++

#linker flags
LDFLAGS = -lSDL2 -lSDL2_gfx -lSDL2_ttf

#obj name
OBJ_NAME = Tetris

all : $(OBJS)
	$(CC) $(OBJS) -o $(OBJ_NAME) $(LDFLAGS)
