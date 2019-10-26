#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <sstream>
#include <queue>
#include <iomanip>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
vector<string> lis;
queue<string> connectors;


int semiColon = 0;
int andAND = 0;
int orOR = 0;
int hashTag = 0;

void parsingS(string &enter, int &counter, vector<string> &list, queue<string> &connectors)
{
 

     if (enter.at(counter) == ';')
     {
                   
                lis.push_back(enter.substr(0, counter));
                
                enter.erase(0, counter + 2);
                counter = 0;
                semiColon++;
           
                   connectors.push(";");
                   
     }
    
       else if (enter.at(counter) == '&' && enter.at(counter +1) == '&')
       {
                    
                 lis.push_back(enter.substr(0, counter -1));
                    
                 enter.erase(0, counter + 3);
                 counter = 0;
                 andAND++;
                   
                    connectors.push("&&");
           
       }
    
      else if (enter.at(counter) == '|' && enter.at(counter +1) == '|')
      {
                    
                 lis.push_back(enter.substr(0, counter -1));
                    
                 enter.erase(0, counter + 3);
                 counter = 0;
                 orOR++;
                    
                    connectors.push("||");
          
      }
    
       else if (enter.at(counter) == '#')
       {
                    if (counter != 0)
                    {
                    lis.push_back(enter.substr(0, counter));
                        enter.erase(0, counter );
                        counter = 0;
                    }
                    else
                    {
                    lis.push_back(enter);
                    enter = "";
                    }
                    connectors.push("#");
           
       }
    

       else
       {
              counter++;
              
       }
    

    
}

int main(int argv, char** argc)
{
    string enter = argc[1];
    int counter = 0;

    cout << "enter: ";
    cout << endl;
   // getline(cin,enter);



    while (counter < enter.size()) //(count < enter.size())
    {

            parsingS(enter, counter, lis, connectors);
        
    }
    lis.push_back(enter);
    
    
    cout << "OUTPUT OF STRINGS SEPARATED BY CONNECTORS: ";
    cout << endl;
    for (auto one : lis)
    {
        cout << one << endl;
        
    }
    
    cout << endl;

    cout << "CONNECTORS IN ORDER THEY APPEARED: ";
    cout << endl;   
    while (!connectors.empty())
    {
        cout << connectors.front() << endl;
        connectors.pop();
    }
    

    

    cout << endl;
    cout << "semicolom: " << semiColon << endl;
    cout << "&&: " << andAND << endl;
    cout << "||: " << orOR << endl;
    cout << "#: " << hashTag << endl;
    
    return 0;
}


