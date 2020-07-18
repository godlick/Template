#顶层路径
ROOT = $(firstword $(subst template, template ,$(PWD)))template

#$(firstword NAMES…) 
#函数名称：取首单词函数—firstword。(空格为分隔符) 
#函数功能：取字串“NAMES…”中的第一个单词。 
#返回值：字串“NAMES…”的第一个单词。 
#函数说明：“NAMES”被认为是使用空格分割的多个单词（名字）的序列。函数忽
#略“NAMES…”中除第一个单词以外的所有的单词。 
#示例： 
#$(firstword foo bar) 
#返回值为“foo”。函数“firstword”实现的功能等效于“$(word 1, NAMES…)”

#$(subst FROM,TO, TEXT)  (TO与逗号之间的空格会原样替换犹为关注)
#函数名称：字符串替换-subst
#函数说明：将字符串TEXT中的子串FROM变为TO。（注意其中的空格符）



#包含编译规则
include $(ROOT)/Rules.make

CSOURCES = $(wildcard *.c)

#“$(wildcard *.c)”
#由于在makefile规则中，通配符会被自动展开，但在变量的定义和函数的引用中，通配符会失效
#函数名称：使通配符有效 -wildcard
#函数功能：获取工作目录下的所有的.c文件列表
#返回值：包含*.c的文件列表

#  %.c和 *.c的区别
#  %.c：匹配其中一个（变量定义的时候无效）
#  *.c：匹配全部	

#src1=$(wildcard *.c)
#src2=%.c
#src3=*.c

targets = $(CSOURCES:.c=)
#将CSOURCES列表中的%.c 替换成 %（如果=后面是.txt,那么就是替换成%.txt）

all:$(targets)

#%:%.c 
#	@echo $(targets)
#	@echo  111111
#       @echo  $(src1)
#       @echo  222222
#       @echo  $(src2)  #通配符在定义变量时失效，原样输出“%.c”  
#       @echo  333333
#       @echo  *.c
#       @echo $(TEST)
#       @echo $(subst template, template ,$(PWD))
#       @echo $(ROOT)
#       @echo $(firstword $(subst template, template ,$(PWD)))

%:%.c
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS)

clean:
	rm -f $(targets) $(TEMPFILES) *.o

