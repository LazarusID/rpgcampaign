
include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/googletest/googlemock/include)

SET(TEST_SRC
	testConfig.cpp
	testFileFolder.cpp
	testHostname.cpp 
        testLinkFarm.cpp
	testSiteRequest.cpp
	testSiteResponse.cpp 
)

SET(UNIT_UNDER_TEST_SRC
        ../LinkFarm.cpp ../LinkFarm.h
	../Link.cpp ../Link.h
	../FileFolder.cpp ../FileFolder.h
	../Directory.cpp ../Directory.h
        ../SiteRequest.cpp ../SiteRequest.h
	../Hostname.cpp ../Hostname.h 
	../SiteController.cpp ../SiteController.h 
	../SiteResponse.cpp ../SiteResponse.h 
	../System.cpp ../System.h
	../Config.cpp ../Config.h
	MockSystem.h
)

SET(TEST_NAME ${PROJECT_NAME}-test)
ADD_EXECUTABLE(${TEST_NAME}
	${TEST_SRC}
	${UNIT_UNDER_TEST_SRC}
    ${JSON_SRC}
	)
SET_PROPERTY(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)
TARGET_LINK_LIBRARIES(${TEST_NAME}
    gmock
	gtest
	gtest_main
	)

TARGET_COMPILE_FEATURES(${TEST_NAME} PUBLIC cxx_override)
ADD_TEST(UnitTest ${TEST_NAME})

