#include <iostream>
#include <string>
#include "../header/base.hpp"
#include "../header/command_group.hpp"
#include "../header/connectors.hpp"

int main(int argv, char** argc) {
 
    std::string command = argc[1];
    //std::string command = "echo multiple || ls -a ; ech false && echo bye";
    Connectors* start_connectors = new Connectors();
    CommandGroup* command_group = new CommandGroup(start_connectors, command);
    command_group->execute();

    std::cout << "SIZE: " << command_group->size() << std::endl;

    return 0;
}
