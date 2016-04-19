// Test for Executor class

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <map>
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

TEST_F(testExecutor, run_withEmptyParameters_callsExecvpWithRawCli) {
	map<string, string> params;
	const char* expectedCli[] = {SIMPLECOMMAND, NULL};
	char* const* actualCli = NULL;

	EXPECT_CALL(mockSystem, execvp(StrEq(SIMPLECOMMAND), NotNull()))
		.WillOnce(
			DoAll(
				SaveArg<1>(&actualCli),
				Return(0)
			)
		);
	sut->setCli(simplecli);
	sut->run(params);
	ASSERT_THAT(actualCli, NotNull());
}
