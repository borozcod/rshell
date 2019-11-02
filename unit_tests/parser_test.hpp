#ifndef __PARSER_TEST_HPP__
#define __PARSER_TEST_HPP__

#include "gtest/gtest.h"

#include <string>
#include "../parser.hpp"

TEST(ParserTest, ParseConnectors ) {

    std::string command = "echo hi && ls -a && cat main.cpp || echo bye && echo bye again";
    Parser* parser = new Parser(command);

    EXPECT_EQ(parser->get_front(), 1);
    EXPECT_EQ(parser->get_back(), 1);
    EXPECT_EQ(parser->get_size(), 4);
    parser->pop();
    EXPECT_EQ(parser->get_size(), 3);
}

TEST(ParserTest, ParseSingleCommand ) {

    std::string command = "echo hi";
    Parser* parser = new Parser(command);

    EXPECT_EQ(parser->get_size(), 0);
}

#endif //__PARSER_TEST_HPP__
