#include <iostream>
#include <string>
#include "./header/base.hpp"
#include "./header/command_group.hpp"
#include "./header/connectors.hpp"

int main() {
 
   std::string command = "echo hi || ls -a && cat main.cpp ; echo bye && echo bye again";

    Connectors* start_connectors = new Connectors();
    CommandGroup* command_group = new CommandGroup(start_connectors, command);
    command_group->execute();

    std::cout << "SIZE: " << command_group->size() << std::endl;

    return 0;
}
