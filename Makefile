CXXC = g++

STD = -std=c++17

LDFLAGS = -lm

OPT = -D NDEBUG -ffast-math -O3 -march=native

DBG = -D DEBUG -Og -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
                      -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op          \
                      -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept             \
                      -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow     \
                      -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel                \
                      -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused     \

INCL = -I ./src/headers

run: ./src/main.cpp
	$(CXXC) $(STD) $(OPT) $(INCL) ./src/main.cpp $(LDFLAGS) -o run

dbg: ./src/main.cpp
	$(CXXC) $(STD) $(DBG) $(INCL) ./src/main.cpp $(LDFLAGS) -o dbg

test1: ./test/test.cpp
	$(CXXC) $(STD) $(OPT) $(INCL) ./test/test.cpp $(LDFLAGS) -o runtest

dbgtest1: ./test/test.cpp
	$(CXXC) $(STD) $(DBG) $(INCL) ./test/test.cpp $(LDFLAGS) -o dbgtest

measure: ./test/measure.cpp
	$(CXXC) $(STD) $(OPT) $(INCL) ./test/measure.cpp $(LDFLAGS) -o runmeasure

dbgmeasure: ./test/measure.cpp
	$(CXXC) $(STD) $(DBG) $(INCL) ./test/measure.cpp $(LDFLAGS) -o dbgmeasure


clear:
	rm -f run dbg runtest dbgtest runmeasure dbgmeasure
