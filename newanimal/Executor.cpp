//
// Created by clay on 4/9/16.
//

#include <algorithm>
#include "Executor.h"

Executor::Executor() {
	sys = new System();
}

Executor::Executor(SystemInterface *s) : sys(s) {

}

void Executor::setCli(vector<string>& cli)
{
	copy(cli.begin(), cli.end(), command.begin());
}

int Executor::run(map<string, string>& parameters)
{

}
