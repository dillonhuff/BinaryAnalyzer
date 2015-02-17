CC         := g++
LINKER     := $(CC)
CFLAGS	   := -O3 -g -Wall -std=c++0x -Isrc/

HEADERS :=  $(shell find src -type f -name '*.h')
SOURCES :=  $(shell find src -type f -name '*.cpp')
OBJS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))

all: binary_analyzer


obj/%.o: src/%.cpp $(HEADERS)
	@mkdir -p obj
	@mkdir -p obj/arm
	@mkdir -p obj/elfio
	@mkdir -p obj/utils
	$(CC) $(CFLAGS) -c $< -o $@

binary_analyzer: $(OBJS) $(HEADERS)
	$(LINKER) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf obj
	rm -rf src/*~
	rm -f binary_analyzer
