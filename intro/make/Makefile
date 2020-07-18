TARGET = target
#OBJS = main.o add.o
OBJS = main.o

OBJS += add.o
#OBJS := add.o
#OBJS ?=add.o

CFLAGS = -o


#target:main.o add.o
$(TARGET):$(OBJS)
#gcc main.o add.o -o target

	@echo hello

	gcc $^ $(CFLAGS) $@

main.o:main.c
	gcc main.c -c

add.o:add.c
	gcc add.c -c

clean:
	rm *.o target
