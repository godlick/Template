#顶层路径
ROOT = $(firstword $(subst template, template ,$(PWD)))/template

#包含编译规则
include $(ROOT)/Rules.make

CSOURCES = $(wildcard *.c)

targets = $(CSOURCES:.c=)

all:$(targets)

%:%.c
	$(CC) $@.c -o $@ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(targets) $(TEMPFILES) *.o

