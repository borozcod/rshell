#ifndef __TEST_COMMAND_HPP__
#define __TEST_COMMAND_HPP__

#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "connectors.hpp"
#include "base.hpp"

class TestCommand : public Base {
    
    std::string	command_string;
    Connectors* connectors;	
    bool exist;
    // This is made possible because of stat.h
    struct stat sb;

    public:
        TestCommand(Connectors* c, std::string command) { 
	    this->connectors = c;
	    this->command_string = command;
	};
	
        void execute() {

	    if(this->connectors->get_run()) {
	 	
		if (stat(this->command_string.c_str(), &sb) == -1) {
     		    perror("RSHELL failed");
		    this->connectors->set_status(0);
		    exit(2);
		}

		// Somehow this needs to be dynamic
		std::string command_type = "-e";
			
		if(command_type == "-e") {
		    if(  S_ISDIR(sb.st_mode) == 1 || S_ISREG(sb.st_mode) == 1 ) {
			this->exist = true;
		    } else {
			this->exist = false;
		    }
		} else if( command_type == "-f" ) {
		    if( S_ISREG(sb.st_mode) == 1 ) {
			this->exist = true;
		    } else {
			this->exist = false;
		    }

		} else if( command_type == "-d") {
		    if( S_ISDIR(sb.st_mode) == 1 ) {
			this->exist = true;
		    } else {
			this->exist = false;
		    }
		}
		
		if(this->exist) {
		    printf("(True)\n");
		} else {
		    printf("(False)\n");
		}

		this->connectors->set_status(1);	
	    }
	    else
	    {
		this->connectors->set_status(this->connectors->get_status());	
	    }

	}

	bool get_exist() {
	    return this->exist;
	}	
	
	int size() {
	    return 1;
	}
};

#endif //__TEST_COMMAND_HPP__
