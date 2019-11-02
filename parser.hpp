#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <queue>
#include <string>

class Parser {
        private:
	    std::queue<int> connectors;

        public:
            Parser(std::string command) {
		this->connectors.push(1);
		this->connectors.push(1);
		this->connectors.push(0);			    
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

