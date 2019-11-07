#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <queue>
#include <string>

class Parser {
        private:
	    std::queue<int> connectors;
	    std::vector<std::string> single_command_list;

	    void parse_string( std::string &enter, int &counter, std::queue<int> &connectors ) {
		if (enter.at(counter) == '&' && enter.at(counter + 1) == '&')
		{
		    // Check for &&
		    this->single_command_list.push_back(enter.substr(0, counter -1));
		    enter.erase(0, counter + 3);
		    counter = 0;
		    connectors.push(1);

		}
		else if (enter.at(counter) == '|' && enter.at(counter + 1) == '|')
		{
		    // Check for ||
                    this->single_command_list.push_back(enter.substr(0, counter -1));
		    enter.erase(0, counter + 3);
		    counter = 0;

		    connectors.push(0);

		}
		else if (enter.at(counter) == '#')
		{
		if(counter != 0)
		{
		this->single_command_list.push_back(enter.substr(0,counter-1));
		enter.erase(0,counter);
		counter = 0;
		}
		else
		{
		enter.erase(0,enter.size());
		counter = 0;
		connectors.push(0);
		}
		}
		else
		{
		    counter++;
		}
	    }
	    
	    void parse_string_commands(std::string &enter, int &counter, std::vector<std::string> &list) {
		if (enter.at(counter) == ';')
		{
		    list.push_back(enter.substr(0, counter -1));

		    enter.erase(0, counter + 2);
		    counter = 0;
		}
		else
		{
		    counter++;
		}
	}

        public:
            Parser() {}
	
	    void parse(std::string command_string) {

		int counter = 0;

		while (counter < command_string.size())
		{
		    this->parse_string(command_string, counter, connectors);
		}
		if (!command_string.empty()) // so it doesn't add a blank string
		{
		single_command_list.push_back(command_string);
 		}
	    }    
	    
	    // Overload for when passing a vector that will hold command gorups
	    void parse(std::string command_string, std::vector<std::string> &command_g) {

		int counter = 0;

		while (counter < command_string.size())
		{
		    this->parse_string_commands(command_string, counter, command_g);
		}
		command_g.push_back(command_string);
	    }

	    int get_front() {
		return connectors.front();
	    }
	    
	    int get_back() {
		return connectors.back();
	    }
	    
	    int get_size() {
	    	return connectors.size();
	    }
	    
	    void pop() {
	    	this->connectors.pop();
	    }

	    std::vector<std::string> get_individual_commands() {
		return this->single_command_list;
	    }
};

#endif // _PARSER_HPP_

