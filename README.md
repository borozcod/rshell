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
![Image of Yaktocat](images/UML.jpeg)

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

