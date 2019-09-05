CC=g++
FLAG=-pipe -Wall -Werror
OBJ=tools.o guest.o hotel.o hotel_manage.o main.o room.o
BIN=tyc

all:$(OBJ) 
	$(CC) $(FLAG) $(OBJ) -o $(BIN)

%.o:%.cpp
	$(CC) $(STD) $(FLAG) -c $< -o$@
clean:
	rm $(OBJ) $(BIN)
