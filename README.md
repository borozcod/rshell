# CS 100 Programming Project

# Project Information
2019 Fall Quarter

Bryan Orozco SID: `862142700`  
Kevin Alvarez SID: `862131623`

# Introduction  
In this assignment we will be creating our own command shell called rshell. It will take commands and connectors as the input and then use `fork`, `execvp` and `waitpid` accordingly. A command input can be a single command or a group of command.  

### Example:  
Single command:  
```shell
echo "Single Command"
```

Group of commands:  
```shell
echo "First Command" && echo "Second Command" || ls -a
```

### Design Patter  
For this assignment we will be using a Composite Design Pattern. We will have a `CommandGroup` and a `Command` class which both inherit from a `Base` class that has an `execute()` pure virtual function. `CommandGroup` will hold a vector of `Command`'s and will act as the entry point of any input. `CommandGroup` will have a reference to a `Connectors` class in which we will store a queue of connectors represented as `int` values. The idea behind this is that we will treat the entire input as a `CommandGroup` and break it down to just single commands and store any connectors in an instance of `Connectors`. Whenever a `;` is found we will tret everything after that as a new `CommandGroup`. The `Connectors` class will provide the logic that will determine if we need to run a command or not.

# Diagram
## UML
![Image of UML](https://github.com/cs100/assignment-lakersboyz/blob/borozcod/readme/images/UML.jpeg?raw=true)

# Classes


## `Connectors` Class
This is the class that will handle if a command should run or not. It will hold a `status` integer that is either 0 or 1, a `run` boolean and a queue of connectors that are added with `add_connector` represented by either `1` for `&&` or `0` for `||`. The `set_status` function will take an `int` that is either `1` for pass or `0` for fail, then compare that with the bottom of the queue with an `&&` bitwise operation. If the result is `1` we set `run` to `true` else set it to `false`.

## Class Group  

### `Base` Class

The base is just a interface that has a pure virtual function called `execute`. 

### `Command` Class
This class will be where the shell command actually gets executed. The execute function will check `get_run()` from the `Connector` reference and decide if this command should run or not. If it runs it will call `set_status()` with the value of `1` if it passed and `0` if it failed. If it doesn't have to run it will just run `set_status()` with the value returned from `get_status()` we do this because `set_status()` actually pops connectors from the queue whenever it's called, and we don't want to alter the order of connectors.

### `CommandGroup` 

This class will have two private members. A vector of `Command`s and a reference of a `Connector` class. The connector member will be assigned in the constructor. There will be two functions, `execute` and `add_command`. When adding a command to a Command Group, the connectors will be stripped out and stored inside the connectors member. Each `Command` or `CommandGroup` will be stored inside the commands vector member. We will distinguish between a command or a command group by the `;`. The execute function will just loop through the vector of commands and call their individual execute function.

# Prototypes/Research

For our RSHELL we will be using three system calls, fork(), execvp(), and waitpid(). Each one of them have their own unique actions, the fork() system call creates two copies of the process being executed. The processes are the child process and the parent process. The moment when you call fork() is when it splits up, and you can run the same program twice at the same time. Depending on what commands are entered and what connectors are found, we can run two different processes at the same time. However, if we want one process to finish before we start the next one, we can use the system call wait(). Otherwise, if we don’t want to wait and just run the processes at the same time, then we should use the waitpid() system call. It takes in three arguments, which will give us the status information of the terminating process. Then depending on what the return value is, the process can run at the same time. Lastly, the execvp() system call is what is going to enable us to perform the commands that are entered in the input. For example, if the user types in “ls”, the execvp() call will display all the directories.

The parsing function that we are going to be using is one where whatever the user inputs will be stored into a string variable. Once the input is in the string variable, then we will run a while loop where it checks for any connectors in the input. Whenever it finds a connector it separates and inserts every word before the connector into a string vector, except the connector, that will be inserted into a queue. When we execute the commands it will grab the first two element from the vector and the connector from the queue. Depending on what the commands are and what the particularly connector is, the appropriate execution will be performed. Also, depending on how many commands were entered and how many connectors were found, the order in which they execute may change. Another thing that might change the execution order will be if any parenthesis or quotation marks are found.

# Development and Testing Roadmap

## Create Test

* Create test for `Connectors` class
    * Test when a connector is added.
    * Test `set_state()` and make sure the return in `get_sate()` is as expected.
    * Test `get_run()`
    * Test `add_connector()`
* Create test for `Command`
    * Test a command that should fail.
    * Test a command that should pass.
    * Test that it is referencing a `Connectors` class correctly.
    * Test when a command should not run
* Create test for `CommandGroup`
    * Test adding a long string of multiple commands separated by connectors.
    * Test adding two command groups separated by `;`.

## Create Classes

* Create `Connectors` class
    * Add `set_status()` function
    * Add `get_status()` function
    * Add `get_run()` function
    * Add `add_connector()` function
* Create `Command` class
    * Add `execute()` function
    * Add constructor
* Create `CommandGroup` class
    * Add `add_command()` function
    * Add `execute()` function
    * Add constructor

