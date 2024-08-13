# Target to build the final executable
all: enigma
# Rule to build the 'enigma' executable
enigma: main.o Keyboard.o Plugboard.o Rotor.o Reflector.o Enigma.o
	g++ -o enigma main.o Keyboard.o Plugboard.o Rotor.o Reflector.o Enigma.o
# Rule to compile main.o from main.cpp
main.o: main.cpp
	g++ -c main.cpp
# Rule to compile Keyboard.o from Keyboard.cpp and Keyboard.h
Keyboard.o: Keyboard.cpp Keyboard.h
	g++ -c Keyboard.cpp
# Rule to compile Plugboard.o from Plugboard.cpp and Plugboard.h
Plugboard.o: Plugboard.cpp Plugboard.h
	g++ -c Plugboard.cpp
# Rule to compile Rotor.o from Rotor.cpp and Rotor.h
Rotor.o: Rotor.cpp Rotor.h
	g++ -c Rotor.cpp
# Rule to compile Reflector.o from Reflector.cpp and Reflector.h
Reflector.o: Reflector.cpp Reflector.h
	g++ -c Reflector.cpp
# Rule to compile Enigma.o from Enigma.cpp and Enigma.h
Enigma.o: Enigma.cpp Enigma.h
	g++ -c Enigma.cpp
# Rule to clean up build artifacts
clean:
	rm -f *.o enigma