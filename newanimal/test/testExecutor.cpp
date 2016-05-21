//
// Created by Clayton Dowling on 5/20/16.
//

#include <gmock/gmock.h>
#include "../Executor.h"
#include "MockSystem.h"

#include <vector>
#include <string>

using namespace ::testing;
using namespace std;

class testExecutor : public testing::Test {
public:
    unique_ptr<Executor> exe;
    NiceMock<MockSystem> sys;

    virtual void SetUp() {
        exe = make_unique<Executor>(&sys);
    }
};

TEST_F(testExecutor, run_withSingleArgCli_execvpCalledWithSingleArg)
{
    vector<string> cli;
    cli.push_back("ls");
    map<string, string> params;

    EXPECT_CALL(sys, fork())
                .WillOnce(Return(0));
    EXPECT_CALL(sys, execvp(StrEq("ls"), _));
    exe->setCli(cli);
    exe->run(params);

}

