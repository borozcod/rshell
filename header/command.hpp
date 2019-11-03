#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <string>
#include "connectors.h"

class Command {
    
    std::string	command_string;
    Connectors* connectors;	

    public:
        Command(Connectors &c) { 
	    this->connectors = c;
	};
	
	void add_command(std::string command) {
	    this->command_string = command;
	}
	
        void execute() {
	    // This is where the magic happens. I don't know how
	    if(this->connectors->get_run()) {
	    	// here we should call this->connectors->set_status() to 1 if it passed or 0 if failed;
	    } else {
	    	this->connectors->set_status(this->connectors->get_status());
	    }
	}
};

#endif //__COMMAND_HPP__
