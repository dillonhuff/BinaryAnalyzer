CC         := g++
LINKER     := $(CC)
CFLAGS	   := -O3 -g -Wall -std=c++11 -Isrc/

SOURCES :=  $(shell find src -type f -name '*.cpp')
OBJS := $(patsubst %.cpp, %.o, $(SOURCES))

binary_analyzer: $(notdir $(OBJS))
	$(LINKER) $(CFLAGS) $(notdir $(OBJS)) -o $@

include $(OBJS:.o=.d)

%.d: %.cpp
	bash depends.sh $(CFLAGS) src/ $*.cpp > $@

clean:
	find . -type f -name '*~' -delete
	find . -type f -name '*.d' -delete
	find . -type f -name '*.o' -delete
	rm -f binary_analyzer
