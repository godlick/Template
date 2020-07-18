#
# 编译库文件的Makefile
#

#顶层路径
ROOT = $(firstword $(subst template, template ,$(PWD)))/template

#包含编译规则
include $(ROOT)/Rules.make

#编译最终目标
target = libcommon.a

#依赖的目标文件名
OBJS = error.o

#如果程序要支持段错误调试，则把sigsegv.c加入到库文件
ifeq ($(support_sigdebug), y)
OBJS += sigsegv.o
endif

all:$(OBJS)
	echo $(support_sigdebug)
	ar -cvrs libcommon.a $^

%.o:%.c
	gcc $< -c $(CFLAGS)
	
clean:
	rm -f *.o a.out core temp.* $(target)

