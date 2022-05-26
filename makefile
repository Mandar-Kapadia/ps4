CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = StringSound.h CircularBuffer.h 
all:PS4a KSGuitarSim test2 style  
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -I/opt/homebrew/Cellar/boost/1.78.0_1/include -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<
PS4a: CircularBuffer.o test.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
KSGuitarSim: CircularBuffer.o KSGuitarSim.o StringSound.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
test2: CircularBuffer.o StringSound.o stringSoundTest.o
	$(CC) $(CFLAGS) -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)
clean:
	rm -f *.o 
	rm -f PS4a
	rm -f KSGuitarSim
	rm -f test2
style:
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h CircularBuffer.h
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h CircularBuffer.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h test.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h StringSound.h
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h StringSound.cpp
	cpplint --filter=-runtime/references,-build/header_guard --extensions=cpp,hpp,h KSGuitarSim.cpp