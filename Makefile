BIN = sentinel
SRC = ./src/*.cpp \
	  ./src/Player/Player.cpp \
	  ./src/Map/Map.cpp \
	  ./src/Map/Entity/Entity.cpp \
	  ./src/Map/Entity/Champion/Champion.cpp \
	  ./src/Map/Entity/Obstacle/Obstacle.cpp 
INC = -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system
all: ${BIN}

${BIN} : ${SRC}
	g++ ${SRC} ${INC} -o $@

clean:
	rm -f ${BIN}

re: clean all

.PHONY: all clean re
