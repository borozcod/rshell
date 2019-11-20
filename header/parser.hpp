#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Parser {
        private:
	    std::queue<int> connectors;
	    vector<string> tester;
 	    vector<string> paren;
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
		    // Check for #
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
		else if (enter.at(counter) == '(')
		{
			
		int leftParen = 1;
		int rightParen = 0;

		for (int i = 1; i < enter.size(); i++)
		{
			if(enter.at(i) == '(')
			{
			leftParen++;
			}
			else if (enter.at(i) == ')')
			{
			rightParen++;
			}

		}

		if (rightParen == leftParen)
		{
			if (rightParen > 1 && leftParen > 1)
			{
			paren.push_back(enter.substr(counter+1, enter.size()-2));
			enter.erase(0,enter.size());
			}
			else
			{
			
			   for (int i = counter; i < enter.size(); i++)
          			 {
           				 if (enter.at(i) == ')')
            					{
										
							paren.push_back(enter.substr(counter+1, i -1));
                    
                   					 if (i == enter.size() -1)
                    					{
                    
                    					enter.erase(0, i+1);
                    					}
                    					else if (enter.at(i+2) == '&' && enter.at(i+3) == '&')
                    					{
                        				
                        				enter.erase(0, i+5);
							connectors.push(1);
                    					}
                    					else if (enter.at(i+2) == '|' && enter.at(i+3) == '|')
                    					{
                        				
                        				enter.erase(0, i+5);
							connectors.push(0);
                    					}
                    					

							break;
						}
				}
			}


		}
		else
		{
		cout << "ERROR: parentheses don't match" << endl;
		}
		counter = 0;
		
	}

		else if (enter.at(counter) == '[' && enter.at(counter +1) == ' ')
		{
		
			for (int i = counter; i < enter.size(); i++)
			{
				if (enter.at(i) == ']' && enter.at(i-1) == ' ')
				{
				
				if(i == enter.size()-1)
                		{
                   		 tester.push_back(enter.substr(2,i-3));
			
                    
                		}
                		else if (enter.at(i +2) == '&' && enter.at(i+3) == '&')
                		{
                    
                   		 tester.push_back(enter.substr(2,i-3));
				
				connectors.push(1);          			 
         		
                		}
                
                		else if (enter.at(i+2) == '|' && enter.at(i+3) == '|')
                		{
                    
                    		tester.push_back(enter.substr(2,i-3));
                    		
				connectors.push(0);
                		}
                
                
                		else if (enter.at(i+2) == ';')
                		{
                    
                    		tester.push_back(enter.substr(2,i-2));
         			
           
                		}

                if (i == enter.size()-1)
                {
                    enter.erase(0,enter.size()+1);
                }
                else if(enter.at(i+2) == ';')
                {
                    enter.erase(0, i+4);
                }
                else{
                enter.erase(0, i +5);
                }
                
                break;
            }
            
        }
        
        counter = 0;
    }


else if ((enter.at(counter) == 't') && (enter.at(counter+1) == 'e') && (enter.at(counter+2) == 's')
             && (enter.at(counter+3) == 't') && (enter.at(counter+5) == '-'))
    {
	
        for (int i = 0; i < enter.size(); i++)
        {
            if (i == enter.size() -1)
            {
                tester.push_back(enter.substr(0,i+1));
                enter.erase(0,i+1);
                break;
            }
            else if (enter.at(i) == '&' && enter.at(i+1) == '&')
            {
                tester.push_back(enter.substr(0,i-1));
                enter.erase(0,i+3);
             	connectors.push(1);   
                break;
            }
            else if(enter.at(i) == '|' && enter.at(i+1) == '|')
            {
                tester.push_back(enter.substr(0,i-1));
                enter.erase(0,i+3);
                connectors.push(0);
                break;
            }
            else if (enter.at(i) == ';')
            {
                tester.push_back(enter.substr(0,i-1));
                enter.erase(0,i+2);
                
                break;
                
            }
     
        }
        counter = 0;
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

