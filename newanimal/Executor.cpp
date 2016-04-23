//
// Created by clay on 4/9/16.
//

#include <algorithm>
#include <cstring>
#include "Executor.h"

Executor::Executor() {
	sys = new System();
}

Executor::Executor(SystemInterface *s) : sys(s) {

}

void Executor::setCli(vector<string>& cli)
{
    command = cli;
}

int Executor::run(map<string, string>& parameters)
{
	int size = command.size() + 1;
	char** cli = new char* [size];
    for(int i=0; i < command.size(); ++i) {
        cli[i] = strdup(command[i].c_str());
    }

    pid_t pid = fork();
    if (pid == 0) {
        // We're in the child process
        sys->execvp(command[0].c_str(), cli);
    } else {
        // We're waiting for our child, and probably late for work
        int status;
        waitpid(pid, &status, 0);

        for(int i=0; i < command.size(); ++i) {
            free(cli[i]);
        }
        delete cli;

        return status;
    }
}
