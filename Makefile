CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)
LDFLAGS  =
CXX      = c++

all: clean main
	@/bin/true

main: main.o sensor.o cmdline.o
	$(CXX) $(LDFLAGS) -o main sensor.o main.o cmdline.o

main.o: main.h array.h cmdline.h sensor.h
	$(CXX) $(CXXFLAGS) -c main.cc

cmdline.o: cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cc
	
sensor.o: sensor.cc sensor.h
	$(CXX) $(CXXFLAGS) -c sensor.cc



test: main
	@set -e; for t in test?; do              \
	  echo testing: $$t.;                    \
	  ./$$t <$$t.in >$$t.t;                  \
	  diff -b $$t.ref $$t.t >/dev/null 2>&1; \
	done
	@echo test ok.

test-valgrind: main
	@set -e; for t in test?; do                                  \
	  echo testing: $$t.;                                        \
	  valgrind --tool=memcheck ./$$t <$$t.in >$$t.t 2>/dev/null; \
	  diff -b $$t.ref $$t.t >/dev/null 2>&1;                     \
	done
	@echo test ok.

clean:
	rm -f *.o *.t core test?
