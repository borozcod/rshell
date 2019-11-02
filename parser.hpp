#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <queue>
#include <string>

class Parser {
        private:
	    std::queue<int> connectors;
	    
	    void parse_string( std::string &enter, int &counter, std::queue<int> &connectors ) {
		if (enter.at(counter) == '&' && enter.at(counter + 1) == '&')
		{
		    // Check for &&
		    enter.erase(0, counter + 3);
		    counter = 0;
		    connectors.push(1);

		}
		else if (enter.at(counter) == '|' && enter.at(counter + 1) == '|')
		{
		    // Check for ||
		    enter.erase(0, counter + 3);
		    counter = 0;

		    connectors.push(0);

		}
		else
		{
		    counter++;
		}
	    }

        public:
            Parser(std::string command) {
		
		int counter = 0;

		while (counter < command.size())
		{
		    this->parse_string(command, counter, connectors);
		}
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

};

#endif // _PARSER_HPP_
