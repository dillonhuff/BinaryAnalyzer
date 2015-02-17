UNAME := $(shell uname)
DEP_CFLAGS := -O3 -g -Wall -Isrc/
CFLAGS := $(DEP_CFLAGS)
CFLAGS += -std=c++11

ifeq ($(UNAME), Linux)
CC := g++-4.9
endif

ifeq ($(UNAME), Darwin)
CC := clang
endif

LINKER := $(CC)

SOURCES :=  $(shell find src -type f -name '*.cpp')
OBJS := $(patsubst %.cpp, %.o, $(SOURCES))

binary_analyzer: $(notdir $(OBJS))
	$(LINKER) $(CFLAGS) $(notdir $(OBJS)) -o $@

include $(OBJS:.o=.d)

%.d: %.cpp
	bash depends.sh $(DEP_CFLAGS) src/ $*.cpp > $@

clean:
	find . -type f -name '*~' -delete
	find . -type f -name '*.d' -delete
	find . -type f -name '*.o' -delete
	rm -f binary_analyzer
