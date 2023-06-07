#include "osfixes.h"
#ifdef _WIN32
#include <config.h>
#include "term.h"
#include "general.h"

HandleExec* GetNewExec() {
	HandleExec* exec = malloc(sizeof(HandleExec));
	exec->actions = malloc(sizeof(posix_spawn_file_actions_t));
	exec->attrp = malloc(sizeof(posix_spawnattr_t));
	posix_spawn_file_actions_init(exec->actions);
	posix_spawnattr_init(exec->attrp);
	exec->am_child = FALSE;
	exec->child_pid = 0;
	exec->envp = NULL;
	exec->___env_max = 0;
	exec->___env_cur = 0;
	return exec;
}
#define ENV_ALLOC_CNT 1025

void DupeEnvVar(HandleExec* exec, const char* varLine) {
	if (exec->___env_cur == exec->___env_max) {
		dlog("IN DUMPENVVAR");
		int newMax = exec->___env_max + ENV_ALLOC_CNT;
		char** old = exec->envp;
		exec->envp = malloc(sizeof(char*) * (newMax + 1));
		memcpy(exec->envp, old, sizeof(char*) * exec->___env_max);
		exec->___env_max = newMax;
	}
	exec->envp[exec->___env_cur++] = savestring(varLine);
	exec->envp[exec->___env_cur] = 0;
}

static void __DupeOrUpdateEnvVarPair(HandleExec* exec, BOOL CHECK_EXISTING, const char* varName, const char* value) {
	int sz = 1 + strlen(varName) + strlen(value) + 1;
	char* tmp = strcpy(malloc(sz), varName);
	strcat_s(tmp, sz, "=");

	if (CHECK_EXISTING) {
		char* findStr = tmp;
		for (int x = 0; x < exec->___env_cur; x++) {
			if (strcmp(exec->envp[x], findStr) == 0) {
				strcat_s(tmp, sz, value);
				free(exec->envp[x]);
				exec->envp[x] = tmp;
				return;
			}
		}

	}
	strcat_s(tmp, sz, value);
	DupeEnvVar(exec, tmp);
	free(tmp);
}
void DupeEnvVarPair(HandleExec* exec, const char* varName, const char* value) {
	__DupeOrUpdateEnvVarPair(exec, FALSE, varName, value);
}
void DupeOrUpdateEnvVarPair(HandleExec* exec, const char* varName, const char* value) {
	__DupeOrUpdateEnvVarPair(exec, TRUE, varName, value);
}
void DestroyExec(HandleExec* exec) {
	posix_spawnattr_destroy(exec->attrp);
	posix_spawn_file_actions_destroy(exec->actions);
	for (int x = 0; x < exec->___env_cur; x++)
		free(exec->envp[x]);
	if (exec->envp)
		free(exec->envp);

	free(exec);
}

int kill(pid_t pid, int sig) {
	if (sig == SIGINT)
		return GenerateConsoleCtrlEvent(CTRL_C_EVENT, pid);//as long as we have created the process with CREATE_NEW_PROCESS_GROUP  it should
	else
		return dcalledint(-1, "kill for pid: %i and sig: %i", pid, sig);
}

int fchmod(int fd, mode_t mode) {
	return 0;
}
unsigned int alarm(unsigned int seconds) {
	return -1;
}
pid_t getpgrp(pid_t pid) {
	return -1;
}
pid_t getppid() {
	return -1;
}
pid_t wait(int* wstatus) {
	return -1;
}



#endif
