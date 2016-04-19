// Test for Executor class

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cstring>

#include "../Executor.h"
#include "MockSystem.h"

using namespace std;

class testExecutor : public ::testing::Test {

	public:

		const char *SIMPLECOMMAND = "/usr/local/bin/myprogram";

		vector<string> simplecli;
		MockSystem mockSystem;

		Executor *sut;

		virtual void SetUp() {
			sut = new Executor(&mockSystem);

			simplecli.push_back(SIMPLECOMMAND);
		}
};

//TEST_F(testExecutor, run_withEmptyParameters_callsExecvpWithRawCli) {
//	const char* cli[] = {SIMPLECOMMAND, NULL};
//
//	EXPECT_CALL(mockSystem, execvp(StrEq(SIMPLECOMMAND),
//			       ElementsAreArray({SIMPLECOMMAND, NULL})))
//		.WillOnceReturn(0);
//	sut->setCli(simplecli);
//}
