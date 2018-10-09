CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)
LDFLAGS  =
CXX      = c++

all: clean main
	@/bin/true

main: main.o sensor.o cmdline.o data.o
	$(CXX) $(LDFLAGS) -o tp0 sensor.o main.o cmdline.o data.o

main.o: main.h array.h cmdline.h sensor.h data.h
	$(CXX) $(CXXFLAGS) -c main.cc

cmdline.o: cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cc
	
sensor.o: sensor.cc sensor.h
	$(CXX) $(CXXFLAGS) -c sensor.cc

data.o: data.cc data.h
	$(CXX) $(CXXFLAGS) -c data.cc
	
clean:
	rm -f *.o *.t core test?
