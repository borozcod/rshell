#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <string>
#include <iostream>
#include "connectors.hpp"
#include "base.hpp"

class Command : public Base {
    
    std::string	command_string;
    Connectors* connectors;	

    public:
        Command(Connectors* c, std::string command) { 
	    this->connectors = c;
	    this->add_command(command);
	};
	
	void add_command(std::string command) {
	    this->command_string = command;
	}
	
        void execute() {
	    std::cout << this->command_string << std::endl;
	    // This is where the magic happens. I don't know how
	    //if(this->connectors->get_run()) {
	    	// here we should call this->connectors->set_status() to 1 if it passed or 0 if failed;
	    //} else {
	    //	this->connectors->set_status(this->connectors->get_status());
	    //}
	}
	
	int size() {
	    return 1;
	}
};

#endif //__COMMAND_HPP__
