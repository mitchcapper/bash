#pragma once
#ifdef _WIN32
#include <config.h>






#define	TIOCHPCL	_IO('t', 2)		/* hang up on last close */
#define	TIOCGETP	_IOR('t', 8,TTYSTRUCT)/* get parameters -- gtty */
#define	TIOCSETP	_IOW('t', 9,TTYSTRUCT)/* set parameters -- stty */
#define	TIOCSETN	_IOW('t',10,TTYSTRUCT)/* as above, but no flushtty*/
#define	TIOCSETC	_IOW('t',17,struct tchars)/* set special characters */
#define	TIOCGETC	_IOR('t',18,struct tchars)/* get special characters */
#define		TANDEM		0x00000001	/* send stopc on out q full */
#define		CBREAK		0x00000002	/* half-cooked mode */
#define		LCASE		0x00000004	/* simulate lower case */
#define		ECHO		0x00000008	/* enable echoing */
#define		CRMOD		0x00000010	/* map \r to \r\n on output */
#define		RAW		0x00000020	/* no i/o processing */
#define		ODDP		0x00000040	/* get/send odd parity */
#define		EVENP		0x00000080	/* get/send even parity */
#define		ANYP		0x000000c0	/* get any parity/send none */
#define		NLDELAY		0x00000300	/* \n delay */
#define			NL0	0x00000000
#define			NL1	0x00000100	/* tty 37 */
#define			NL2	0x00000200	/* vt05 */
#define			NL3	0x00000300
#define		TBDELAY		0x00000c00	/* horizontal tab delay */
#define			TAB0	0x00000000
#define			TAB1	0x00000400	/* tty 37 */
#define			TAB2	0x00000800
#define		XTABS		0x00000c00	/* expand tabs on output */
#define		CRDELAY		0x00003000	/* \r delay */
#define			CR0	0x00000000
#define			CR1	0x00001000	/* tn 300 */
#define			CR2	0x00002000	/* tty 37 */
#define			CR3	0x00003000	/* concept 100 */
#define		VTDELAY		0x00004000	/* vertical tab delay */
#define			FF0	0x00000000
#define			FF1	0x00004000	/* tty 37 */
#define		BSDELAY		0x00008000	/* \b delay */
#define			BS0	0x00000000
#define			BS1	0x00008000
#define		ALLDELAY	(NLDELAY|TBDELAY|CRDELAY|VTDELAY|BSDELAY)
#define		CRTBS		0x00010000	/* do backspacing for crt */
#define		PRTERA		0x00020000	/* \ ... / erase */
#define		CRTERA		0x00040000	/* " \b " to wipe out char */
#define		TILDE		0x00080000	/* hazeltine tilde kludge */
#define		MDMBUF		0x00100000	/* DTR/DCD hardware flow control */
#define		LITOUT		0x00200000	/* literal output */
#define		TOSTOP		0x00400000	/* stop background jobs on output */
#define		FLUSHO		0x00800000	/* output being flushed (state) */
#define		NOHANG		0x01000000	/* (no-op) was no SIGHUP on carrier drop */
#define		L001000		0x02000000
#define		CRTKIL		0x04000000	/* kill line with " \b " */
#define		PASS8		0x08000000
#define		CTLECH		0x10000000	/* echo control chars as ^X */
#define		PENDIN		0x20000000	/* re-echo input buffer at next read */
#define		DECCTQ		0x40000000	/* only ^Q starts after ^S */
#define		NOFLSH		0x80000000
#include "term.h"

/*

pdcurses provides these now 

static int tgetflag (const char *name){
  return -1;
}

static int tgetnum (){
  return -1;
}
static char *tgetstr (){
  return NULL;
}

static int tgetent(char *bp, const char *name){
  return -1;
}
static int tputs(const char *str, int affcnt, int (*putc)(int)){
  return -1;
}
static char *tgoto(const char *cap, int col, int row){
  return NULL;
}
*/
#define SIGALRM 14

#include <spawn.h>

typedef struct HandleExec {
	BOOL am_child;
	BOOL was_async;
	pid_t child_pid;
	char* cmd;
	char** args;
	posix_spawn_file_actions_t * actions;
	posix_spawnattr_t* attrp;
	char** envp;
	int ___env_cur;
	int ___env_max;

} HandleExec;

HandleExec* GetNewExec(void);
static char* signal_names[36] = {
	"EXIT",
	"SIGHUP",
	"SIGINT",
	"SIGQUIT",
	"SIGILL",
	"SIGTRAP",
	"SIGABRT",
	"SIGEMT",
	"SIGFPE",
	"SIGKILL",
	"SIGBUS",
	"SIGSEGV",
	"SIGSYS",
	"SIGPIPE",
	"SIGALRM",
	"SIGTERM",
	"SIGURG",
	"SIGSTOP",
	"SIGTSTP",
	"SIGCONT",
	"SIGCHLD",
	"SIGTTIN",
	"SIGTTOU",
	"SIGIO",
	"SIGXCPU",
	"SIGXFSZ",
	"SIGVTALRM",
	"SIGPROF",
	"SIGWINCH",
	"SIGINFO",
	"SIGUSR1",
	"SIGUSR2",
	"DEBUG",
	"ERR",
	"RETURN",
	(char*)0x0
};
void DupeEnvVar(HandleExec* exec, const char* varLine);
static void __DupeOrUpdateEnvVarPair(HandleExec* exec, BOOL CHECK_EXISTING, const char* varName, const char* value);
void DupeEnvVarPair(HandleExec* exec, const char* varName, const char* value);
void DupeOrUpdateEnvVarPair(HandleExec* exec, const char* varName, const char* value);
void DestroyExec(HandleExec* exec);
int kill(pid_t pid, int sig);
int fchmod(int fd, mode_t mode);
unsigned int alarm(unsigned int seconds);
pid_t getpgrp(pid_t pid);
pid_t getppid(void);
pid_t wait(int* wstatus);

#endif