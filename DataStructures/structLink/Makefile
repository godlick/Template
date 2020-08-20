
CSOURCES = $(wildcard *.c)
CPPSOURCES = $(wildcard *.cpp)

targets = $(CSOURCES:.c=)
targets += $(CPPSOURCES:.cpp=)

Targets = $(targets:Main=)  #Main除外

all:$(Targets)

%:%.c
#	echo $(Targets) 
	gcc $@.c $@.h Main.c -o $@ 

%:%.cpp
	g++ $@.cpp -o $@ 

clean:
	rm -f $(targets) $(TEMPFILES) *.o

