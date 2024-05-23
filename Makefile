BIN = sentinel
SRC = ./src/*.cpp ./src/Champion/Champion.cpp ./src/Player/Player.cpp ./src/Map/Map.cpp ./src/Map/Obstacle/Obstacle.cpp
INC = -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system
all: ${BIN}

${BIN} : ${SRC}
	g++ ${SRC} ${INC} -o $@

clean:
	rm -f ${BIN}

.PHONY: all clean
