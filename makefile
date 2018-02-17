CC		= g++
CFLAGS	= -Wall -std=c++17 
LDFLAGS	= -ljack -lportaudio -lpthread
SRC		= main.cpp synth.cpp sine.cpp oscillator.cpp audio_io.cpp
OBJ		= $(SRC:.cpp=.o)
TARGET	= synth 

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $^ $(CFLAGS)

clean: 
	rm $(OBJ) $(TARGET)
