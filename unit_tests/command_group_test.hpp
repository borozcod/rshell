#ifndef __COMMAND_GROUP_TEST_HPP__
#define __COMMAND_GROUP_TEST_HPP__

#include "gtest/gtest.h"

#include <string>
#include "../base.hpp"
#include "../command_group.hpp"
#include "../connectors.hpp"

TEST(CommandGroupTest, SingleCommandGroup) {

    Base* command_group = new CommandGroup();

    std::string command = "echo hi || ls -a && cat main.cpp || echo bye && echo bye again";

    command_group->add_command(command);

    // Just a simple check to ensure commands are being added to the vector member    
    EXPECT_EQ(command_group->size(), 5);
}

TEST(CommandGroupTest, MultipleCommandsGroup) {

    Base* command_group = new CommandGroup();

    // The difference here is that we add a ;
    // This should actually add everything after the ; as a CommandGroup and therefor reducing the size of the vector to 3
    std::string command = "echo hi || ls -a && cat main.cpp ; echo bye && echo bye again";

    command_group->add_command(command);

    // Just a simple check to ensure commands are being added to the vector member    
    EXPECT_EQ(command_group->size(), 3);
}



#endif //___COMMAND_GROUP_TEST_HPP__
