#pragma once
#ifdef _WIN32
#include <config.h>


static int kill(pid_t pid, int sig){
  return -1;
}
//#define killpg kill

static int chmod(const char *path, mode_t mode){
	return 0;
}
static int fchmod(int fd, mode_t mode){
	return 0;
}
static unsigned int alarm(unsigned int seconds){
	return -1;
}
static pid_t getpgrp(pid_t pid){
	return -1;
}
static pid_t getppid () {
	return -1;
}
static pid_t wait(int *wstatus){
	return -1;
}
#endif