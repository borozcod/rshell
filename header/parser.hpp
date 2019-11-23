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
		if (enter.size() >= 2 && enter.at(counter) == '&' && enter.at(counter + 1) == '&')
		{
		    
		    // Check for &&
		    this->single_command_list.push_back(enter.substr(0, counter -1));
		    enter.erase(0, counter + 3);
		    counter = 0;
		    connectors.push(1);
		    

		}
		else if (enter.size() >= 2 && enter.at(counter) == '|' && enter.at(counter + 1) == '|')
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
			
		int leftParen = 0;
		int rightParen = 0;
		int firstParen = counter;
		int lastParen = 0;
		bool checker = true;

		// will make sure that the parentheses match, ( )
		for (int i = 0; i < enter.size(); i++)
		{
			if(enter.at(i) == '(')
			{
			leftParen++;
			}
			else if (enter.at(i) == ')')
			{
			rightParen++;
			lastParen = i;
			}

		}


		int n = counter+1;
		while(enter.at(n) != ')' && enter.size()-1)
		{
			if (enter.at(n) == '(')
			{
			checker = false;
			break;
			}
			else
			{
			checker = true;
			}
		n++;
		}
	
		// if they do match, then continue
		if (rightParen == leftParen)
		{
	
		if (checker == false)
		{

		   if (lastParen == enter.size() -1)
			{
			single_command_list.push_back(enter.substr(counter, lastParen+1));
			enter.erase(counter, lastParen+1);
			}
		   else if (enter.at(lastParen+2) == '&' && enter.at(lastParen+3) == '&')
			{
			single_command_list.push_back(enter.substr(counter,lastParen+1));
			connectors.push(1);
			enter.erase(counter,lastParen+5);
			}
		  else if (enter.at(lastParen+2) == '|' && enter.at(lastParen+3) == '|')
			{
			single_command_list.push_back(enter.substr(counter, lastParen+1));
			connectors.push(0);
			enter.erase(counter,lastParen+5);
			}
		}
		else if (checker == true)
		{

		   for (int i = counter; i < enter.size(); i++)
                     {
                      if (enter.at(i) == ')')
                      {
                          
                          if (i == enter.size() -1)
                          {
                              single_command_list.push_back(enter.substr(counter,i+1));
                              enter.erase(0, i+1);
                          }
                          else if (enter.at(i+2) == '&' && enter.at(i+3) == '&')
                          {
                              connectors.push(1);
                              
                              single_command_list.push_back(enter.substr(counter,i+1));
                              enter.erase(0, i+5);
                          }
                          else if (enter.at(i+2) == '|' && enter.at(i+3) == '|')
                          {
                              connectors.push(0);
                              
                              single_command_list.push_back(enter.substr(counter, i+1));
                              enter.erase(0, i+5);
                          }
                          
                          
                          
                      }
                    
                     }



		}

		}
		else
		{
			cout << "ERROR: parentheses don't match" << endl;
			exit(1);
		}
		counter = 0;
		
	}

    else if (enter.at(counter) == '[' && enter.at(counter+1) == ' ')
    {
        for (int i = counter; i < enter.size(); i++)
        {
            if (enter.at(i) == ']' && enter.at(i -1) == ' ')
            {
                
                
               
                if(i == enter.size()-1)
                {
                    single_command_list.push_back(enter.substr(counter,i+1));
                    enter.erase(counter,i+2);
                    break;
                }
                else if (enter.at(i +2) == '&' && enter.at(i+3) == '&')
                {
                    
                    single_command_list.push_back(enter.substr(counter,i+1));
                    enter.erase(counter,i+5);
                    
                    connectors.push(1);
                    
                    break;
                    
                }
                
                else if (enter.at(i+2) == '|' && enter.at(i+3) == '|')
                {
                    
                    single_command_list.push_back(enter.substr(counter,i+1));
                    enter.erase(counter,i+5);
                    
                    connectors.push(0);
                    
                    break;
                    
                }

            }
            
        }
        
        counter = 0;
    }

// ------------
else if (enter.size() >= 4 && (enter.at(counter) == 't' && counter == 0) && (enter.at(counter+1) == 'e') && (enter.at(counter+2) == 's')
             && (enter.at(counter+3) == 't'))
    {


	// will push whatever is after the -f, -d, -e.
	// and before ||, && or ;
	// then erase
        for (int i = 0; i < enter.size(); i++)
        {

            if (i == enter.size() -1)
            {
                single_command_list.push_back(enter.substr(counter,i+1));
                enter.erase(0,i+1);
                break;
            }
            else if (enter.at(i) == '&' && enter.at(i+1) == '&')
            {
                single_command_list.push_back(enter.substr(counter,i-1));
                enter.erase(counter,i+3);
             	connectors.push(1);
                   break;
            }
            else if(enter.at(i) == '|' && enter.at(i+1) == '|')
            {
                single_command_list.push_back(enter.substr(counter,i-1));
                enter.erase(0,i+3);
                connectors.push(0);
                break;
            }
    
        }
        counter = 0;
    }

// -----

    else if (enter.size() >= 2 && (toupper(enter.at(counter)) == 'E' && counter == 0) && toupper(enter.at(counter+1)) == 'X' && toupper(enter.at(counter+2)) == 'I' && toupper(enter.at(counter+3)) == 'T')
    {
        for (int i = 0; i < enter.size(); i++)
        {
            
        if (i == enter.size()-1)
        {
        single_command_list.push_back(enter.substr(counter,4));
        enter.erase(counter, counter+4);
            break;
        }
            else if (enter.at(i) == '&' && enter.at(i+1) == '&')
            {
                single_command_list.push_back(enter.substr(counter,i-1));
                enter.erase(counter,i+3);
		connectors.push(1);
                break;
                
            }
            else if(enter.at(i) == '|' && enter.at(i+1) == '|')
            {
                single_command_list.push_back(enter.substr(counter,i-1));
                enter.erase(counter,i+3);
		connectors.push(0);
                break;
                
            }

            
        }
        counter = 0;
    }






// ------
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
	 
	void check_command(string &command, string &type)
	{
		for (int i = 0; i < command.size(); i++)
		{
			if (command.at(i) == '-' && command.at(i+1) == 'e')
			{
			    command.erase(0,3);
			    type = "-e";
			    break;
			}
			else if (command.at(i) == '-' && command.at(i+1) == 'f')
			{
			    command.erase(0,3);
			    type = "-f";
			    break;
			}
			else if (command.at(i) == '-' && command.at(i+1) == 'd')
			{
			    command.erase(0,3); // just remove the flag
			    type = "-d";
			    break;
			}
			else if (command.at(i) == 't' && command.at(i+1) == 'e' && command.at(i+2) == 's' && command.at(i+3) == 't') 
			{
			    command.erase(0,i+5);
			    type = "test";
			    break;
			}
			else if (command.at(i) == '[') 
			{
			    command.erase(0,2);
			    command.erase(command.find(']') - 1, 3);
			    
			    type = "test";
			    break;
			}

			else if (command.at(i) == '(')
			{
			    type = "paren";
			break;
			}
			else
			{
			type = "-e";
			break;
			}
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

