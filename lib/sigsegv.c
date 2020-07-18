#ifndef _GNU_SOURCE
	#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <ucontext.h>

# define sigsegv_outp(x, ...) 	fprintf(stderr, x"\n", ##__VA_ARGS__)

#if (defined (__x86_64__))
# define REGFORMAT   "%016lx"	
#elif (defined (__i386__))
# define REGFORMAT   "%08x"
#elif (defined (__arm__))
# define REGFORMAT   "%lx"
#endif

/*栈回溯*/
static void print_call_link(const ucontext_t *uc) 
{
	int i = 0;
	Dl_info	dl_info;

#if (defined (__i386__))
	const void **frame_pointer = (const void **)uc->uc_mcontext.gregs[REG_EBP];
	const void *return_address = (const void *)uc->uc_mcontext.gregs[REG_EIP];
#elif (defined (__x86_64__))
	const void **frame_pointer = (const void **)uc->uc_mcontext.gregs[REG_RBP];
	const void *return_address = (const void *)uc->uc_mcontext.gregs[REG_RIP];
#elif (defined (__arm__))
/* sigcontext_t on ARM:
        unsigned long trap_no;
        unsigned long error_code;
        unsigned long oldmask;
        unsigned long arm_r0;
        ...
        unsigned long arm_r10;
        unsigned long arm_fp;
        unsigned long arm_ip;
        unsigned long arm_sp;
        unsigned long arm_lr;
        unsigned long arm_pc;
        unsigned long arm_cpsr;
        unsigned long fault_address;
*/
	const void **frame_pointer = (const void **)uc->uc_mcontext.arm_fp;
	const void *return_address = (const void *)uc->uc_mcontext.arm_pc;
#endif

	sigsegv_outp("\nStack trace:");
	while (return_address) {
		memset(&dl_info, 0, sizeof(Dl_info));
		if (!dladdr((void *)return_address, &dl_info))	break;
		const char *sname = dl_info.dli_sname;	

		/* No: return address <sym-name + offset> (filename) */
		sigsegv_outp("%02d: %p <%s + %lu> (%s)", ++i, return_address, sname, 
			(unsigned long)return_address - (unsigned long)dl_info.dli_saddr, 
													dl_info.dli_fname);

		if (dl_info.dli_sname && !strcmp(dl_info.dli_sname, "main")) break;

		if (!frame_pointer)	break;
#if (defined (__x86_64__)) || (defined (__i386__))
		return_address = frame_pointer[1];
		frame_pointer = (const void **)frame_pointer[0];
#elif (defined (__arm__))
		return_address = frame_pointer[-1];	
		frame_pointer = (const void **)frame_pointer[-3];
#endif
	}
	sigsegv_outp("Stack trace end.");
}

static void sigsegv_handler(int signo, siginfo_t *info, void *context)
{
	sigsegv_outp("Segmentation Fault!");
	sigsegv_outp("info.si_signo = %d", signo);
	if (info) {
		sigsegv_outp("info.si_errno = %d", info->si_errno);
		sigsegv_outp("info.si_code  = %d (%s)", info->si_code, 
			(info->si_code == SEGV_MAPERR) ? "SEGV_MAPERR" : "SEGV_ACCERR");
		sigsegv_outp("info.si_addr  = %p\n", info->si_addr);
	}

	if (context) {
		const ucontext_t *uc = (const ucontext_t *)context;

		print_call_link(uc);
	}

	_exit(0);
}

void setup_sigsegv(void) 
{	
	struct sigaction sa;

	sa.sa_sigaction = sigsegv_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGSEGV, &sa, NULL);
}

