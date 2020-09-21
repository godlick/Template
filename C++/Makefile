#顶层路径
ROOT = $(firstword $(subst template, template ,$(PWD)))template

#包含编译规则
include $(ROOT)/Rules.make

CSOURCES = $(wildcard *.c)
CPPSOURCES = $(wildcard *.cpp)

targets = $(CSOURCES:.c=)
targets += $(CPPSOURCES:.cpp=)

all:$(targets)

%:%.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS)

%:%.cpp
	g++ $@.cpp -o $@ -lpthread
clean:
	rm -f $(targets) $(TEMPFILES) *.o

