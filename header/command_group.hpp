#ifndef _COMMAND_GROUP_HPP_
#define _COMMAND_GROUP_HPP_

#include "base.hpp"
#include "connectors.hpp"
#include "command.hpp"
#include <vector>
#include <string>

class CommandGroup : public Base {
        private:
            std::vector<Base*> commands;
            Connectors* connectors;

        public:
	    CommandGroup(Connectors &c) {
		connectors = c;
	    }	

	    void execute() {
		for(unsigned i = 0; i < this->commands.size(); i++) {
		    commands.at(i)->execute();
		}
	    }

	    void add_commands(std::string command_string) {
	
		// The parser will return a vectror that should just be commands joined by connectors, no ;
	 	std::vector<std::string> command_g;
			
		// Add new Base*  Command or CommandGroup
		Parser* parser = new Parser();
	
		// Parser should add command groups by refference
		// It could be a vector of just one or more
		parser->parse(command_string, command_g);

		// If there is more than one command group then send that down to a new command group
		if(command_g.size() > 1) {
		
		    for(unsigned i = 0; i < command_g.size(); i++) {
			// For the CommandGroup I create new Connectors	
		    	Connectors* add_connectors = new Connectors():
		    	Base* add_command_group = new CommandGroup(add_connectors);
		    	this->commands.push_back(add_command_group);
		    }
   
		} else {
		
		    // For the command I pass the CommandGroup's Connectors
		    Base* add_command = new Command(this->connectors);
		    // Ran out of ideas for naming things, sorry haha
		    add_command->add_command(command_string);
		    this->commands.push_back(add_command);

		}
	    }

	    int size() {
	    	return commands.size();	
	    }

};

#endif // _COMMAND_GROUP_HPP_

