#ifndef __CONNECTORS_TEST_HPP__
#define __CONNECTORS_TEST_HPP__

#include "gtest/gtest.h"

#include <string>
#include "../connectors.hpp"

TEST(ConnectorsTest, CheckFirsCommands ) {

    std::string command = "echo hi && ls -a && cat main.cpp || echo bye && echo bye again";
    Connectors* connectors = new Connectors(command);
    conncetors.set_status(1);
    EXPECT_EQ(connectos->get_status(), 1);
    EXPECT_EQ(connectors->get_run(), true);
}


#endif //__CONNECTORS_TEST_HPP__
