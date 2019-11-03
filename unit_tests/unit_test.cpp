#include "gtest/gtest.h"

#include "parser_test.hpp"
#include "connectors_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
