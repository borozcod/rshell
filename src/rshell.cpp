#include <iostream>
#include <string>
#include "../header/base.hpp"
#include "../header/command_group.hpp"
#include "../header/connectors.hpp"

int main(int argv, char** argc) {
 
    std::string command = argc[1];
    Connectors* start_connectors = new Connectors();
    CommandGroup* command_group = new CommandGroup(start_connectors, command);
    command_group->execute();

    return 0;
}
