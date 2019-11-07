#include <iostream>
#include <string>
#include "../header/base.hpp"
#include "../header/command_group.hpp"
#include "../header/connectors.hpp"

int main() {
 
   std::string command = "cat testing.cpp || echo fail && echo pass fail || echo dont run";

    Connectors* start_connectors = new Connectors();
    CommandGroup* command_group = new CommandGroup(start_connectors, command);
    command_group->execute();

    std::cout << "SIZE: " << command_group->size() << std::endl;

    return 0;
}
