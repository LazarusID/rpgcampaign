//
// Created by clay on 5/29/16.
//

#ifndef NEWANIMAL_MOCKEXECUTOR_H
#define NEWANIMAL_MOCKEXECUTOR_H

#include "../Executor.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;

class MockExecutor : public ExecutorInterface {
public:

    MOCK_METHOD1(setCli, void(vector<string>&));
    MOCK_METHOD1(run, int(map<string, string>&));

};
#endif //NEWANIMAL_MOCKEXECUTOR_H
