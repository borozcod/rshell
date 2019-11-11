#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <string>
#include <iostream>
#include "connectors.hpp"
#include "base.hpp"
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

class Command : public Base {
    
    std::string	command_string;
    Connectors* connectors;	
    std::vector<std::string> execs;
    int counter = 1;

    public:
        Command(Connectors* c, std::string command) { 
	    this->connectors = c;
	    this->add_command(command);
	};
	
	void add_command(std::string command) {
	    this->command_string = command;
	}
	
        void execute() {

	    int status;
	    char* args[50];

  	    for (int i = 0; i < this->command_string.size(); i++)
  	    {
      		if (this->command_string.at(i) == ' ')
      		{
          	    execs.push_back(this->command_string.substr(0,i));

          	    this->command_string.erase(0,i +1);
          	    i = 0;
          	    counter++;
      		}
     		else if (i == (this->command_string.size() -1))
      	    	{
          	    execs.push_back(this->command_string);
      	    	}

  	    }

	    pid_t child = fork();
	    pid_t child2;

            if (child == 0)
	    {
	
	    	if (this->connectors->get_run())
	    	{
	  	    for (int i = 0; i < counter; i++)
  		    {
     		    args[i] = (char*)(execs.at(i).c_str());
 	 	    }
 	 	    args[counter] = NULL;	

	    	    if ( execvp (args[0], args) == -1)
            	    {
              	    	perror ("exec");
	    	    }

	        } 
	        else
	        {
	     	    exit(1);
	        }

	    }
	    else if (child > 0)
	    {
		child2 = waitpid(child, &status, 0);
		if (child2 == child)
		{
		    this->connectors->set_status(this->connectors->get_status());
		}

	    }
	}
	
	int size() {
	    return 1;
	}
};

#endif //__COMMAND_HPP__