
CSOURCES = $(wildcard *.c)
CPPSOURCES = $(wildcard *.cpp)

targets = $(CSOURCES:.c=)
targets += $(CPPSOURCES:.cpp=)

Targets = $(targets:Main=)  #Main除外

#structLink:main.o structLink.o
#	gcc -o structLink main.o structLink.o

all:$(targets)
	gcc -o S.out $(targets)
	rm -f $(targets) $(TEMPFILES) *.o *.i *.s  #清除中间产生文件
## 链接的过程

%:%.c
#	echo $(Targets) 
#	gcc $@.c $@.h Main.c -o $@ 
	gcc -E $@.c -o $@.i 
	gcc -S $@.i -o $@.s 
	gcc -c $@.s -o $@
## -E:这个选项的作用是让gcc在预处理结束后停止编译过程
## -S进行查看，这个选项只进行编译而不进行汇编，生成.s文件
## -C进行汇编

#structLink:Main.o structLink.o
#	gcc -o structLink Main.o structLink.o	

%:%.cpp
	g++ $@.cpp -o $@ 

clean:
	rm -f $(targets) $(TEMPFILES) *.o *.i *.s *.out

