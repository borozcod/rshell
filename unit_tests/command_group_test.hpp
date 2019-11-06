#ifndef __COMMAND_GROUP_TEST_HPP__
#define __COMMAND_GROUP_TEST_HPP__

#include "gtest/gtest.h"

#include <string>
#include "../header/base.hpp"
#include "../header/command_group.hpp"
#include "../header/connectors.hpp"

TEST(CommandGroupTest, SingleCommandGroup) {

    std::string command = "echo hi || ls -a && cat main.cpp || echo bye && echo bye again";

    Connectors* start_connectors = new Connectors();
    CommandGroup* command_group = new CommandGroup(start_connectors, command);

    // Just a simple check to ensure commands are being added to the vector member    
    EXPECT_EQ(command_group->size(), 5);
}

TEST(CommandGroupTest, MultipleCommandsGroup) {


    //The difference here is that we add a ;
    // This should actually add everything after the ; as a CommandGroup and therefor reducing the size of the vector to 3
    std::string command = "echo hi || ls -a && cat main.cpp ; echo bye && echo bye again";

    Connectors* c = new Connectors();
    CommandGroup* command_group = new CommandGroup(c, command);


    // Just a simple check to ensure commands are being added to the vector member    
    EXPECT_EQ(command_group->size(), 2);
}



#endif //___COMMAND_GROUP_TEST_HPP__
