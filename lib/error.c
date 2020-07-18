/*
	File		:error.c
	Description	:错误处理函数实现
*/


#include "common.h"

#include <errno.h>
#include <stdarg.h>

/*底层接口，打印用户提示信息，由errnoflag确定是否打印error指定的系统提示信息*/
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char buf[MAXLINE];
	
	vsnprintf(buf, MAXLINE - 1, fmt, ap); /*将变参参数全部输出到buf缓冲区*/
	
	if(errnoflag)	/*根据errnoflag确定是否添加标准错误信息*/
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ":%s", strerror(error));
	
	strcat(buf, "\n");
	fflush(stdout); /*以防标准输出和标准错误输出是同一个的情况*/
	fputs(buf, stderr);
	fflush(NULL); /*flush所有的输出流*/
}

/*系统调用相关的非致命错误，打印用户提示信息和系统提示信息，然后返回*/
void err_ret(const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(1, errno, msg, ap);
	va_end(ap);
}

/*系统调用相关的致命错误，打印用户提示信息和系统提示信息，然后直接调用exit()终止程序*/
void err_sys(const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(1, errno, msg, ap);
	va_end(ap);
	exit(1);
}

/*系统调用相关的致命错误，打印用户提示信息和系统提示信息并产生核心转储文件，然后调用exit()终止程序*/
void err_dump(const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(1, errno, msg, ap);
	va_end(ap);
	abort();  /*产生核心转储文件CoreDump*/
	exit(1);
}

/*系统调用无关的非致命错误，打印用户提示信息，然后返回*/
void err_msg(const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(0, 0, msg, ap);
	va_end(ap);
}

/*系统调用无关的非致命错误，打印用户提示信息和error指定的系统提示信息，然后返回*/
void err_cont(int error, const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(1, error, msg, ap);
	va_end(ap);
}

/*系统调用无关的致命错误，打印用户提示信息，然后调用exit()终止程序*/
void err_quit(const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(0, 0, msg, ap);
	va_end(ap);
	exit(1);
}

/*系统调用无关的致命错误， 打印用户提示信息和error指定的系统提示信息，然后调用exit()终止程序*/
void err_exit(int error, const char *msg, ...)
{
	va_list ap;
	
	va_start(ap, msg);
	err_doit(1, error, msg, ap);
	va_end(ap);
	exit(1);
}




















