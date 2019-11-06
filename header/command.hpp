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
	std::vector<std::string> execs;
	int counter = 1;
	


  for (int i = 0; i < command_string.size(); i++)
  {
      if (command_string.at(i) == ' ')
      {
          execs.push_back(command_string.substr(0,i));

          command_string.erase(0,i +1);
          i = 0;
          counter++;
      }
      else if (i == (command_string.size() -1))
      {
          execs.push_back(command_string);
      }

  }
       


//	

		    
	char* args[50];
	
	  for (int i = 0; i < counter; i++)
  	{
     		 args[i] = (char*)(execs.at(i).c_str());
 	 }
 	 args[counter] = NULL;	

	 if ( execvp (args[0], args) == -1)
          {
              perror ("exec");
          }

	execs.clear();
	counter = 1;

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
