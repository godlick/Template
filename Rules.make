#######################################################
#本文件用于指定编译规则，在每个Makefile中都会包含该文件
#######################################################

#是否支持段错误调试
support_sigdebug = y

#指定编译器
CC=gcc

#指定归档程序，用于制作静态库
AR=ar

#指定头文件路径
INCDIR=$(ROOT)/include

#指定库文件路径
LDDIR=-L$(ROOT)/lib

#指定库名
LIB=-lcommon 

#指定编译选项
CFLAGS=-Wall -g -I$(INCDIR) -lpthread

#如果支持段错误调试，则加上这两个编译选项
ifeq ($(support_sigdebug), y)
CFLAGS += -rdynamic -ldl
endif

#指定链接选项
LDFLAGS=$(LDDIR) $(LIB)

#编译生成的中间文件，用于make clean操作
TEMPFILES=core core.* *.o temp.* *.out
