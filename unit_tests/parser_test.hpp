#ifndef __PARSER_TEST_HPP__
#define __PARSER_TEST_HPP__

#include "gtest/gtest.h"

#include <string>
#include <vector>
#include "../header/parser.hpp"

TEST(ParserTest, ParseConnectors ) {

    std::string command = "echo hi || ls -a && cat main.cpp || echo bye && echo bye again";
    Parser* parser = new Parser();

    parser->parse(command);
    EXPECT_EQ(parser->get_front(), 0);
    EXPECT_EQ(parser->get_back(), 1);
    EXPECT_EQ(parser->get_size(), 4);
    parser->pop();
    EXPECT_EQ(parser->get_size(), 3);
	
    std::vector<std::string> test_commands = parser->get_individual_commands();
    
    EXPECT_EQ(test_commands.at(4), "echo bye again");


}

TEST(ParserTest, ParseSingleCommand ) {

    std::string command = "echo hi";
    Parser* parser = new Parser();
    parser->parse(command);

    EXPECT_EQ(parser->get_size(), 0);
}

TEST(ParserTest, ParseCommandGroups ) {

    std::string command_group = "echo hi ; ls -a || echo hola ; cat main.cpp && echo hello world";

    std::vector<std::string> command_g;

    Parser* parser = new Parser();
    // When a vector is passed as a second value, the parser will updated the vector via reference
    parser->parse(command_group, command_g);

    EXPECT_EQ(command_g.size(), 3);
}

TEST(ParserTest, ParenthesisTest ) {

    std::string command = "echo hi && ls -a || (echo hola && ls -a || (cat somefile.txt && echo here)) && echo bye";
    Parser* parser = new Parser();

    parser->parse(command);

    // Size of connectors
    EXPECT_EQ(parser->get_size(), 3);
	
    std::vector<std::string> test_commands = parser->get_individual_commands();
    
    EXPECT_EQ(test_commands.at(2), "(echo hola && ls -a || (cat somefile.txt && echo here))");
}


#endif //__PARSER_TEST_HPP__
