
#include <gtest/gtest.h>

#include <fstream>
#include <iostream>

#include "filters.hpp"

TEST(Test, test_lex_sort) {
  pool_int pool;
  stream_to_pool(std::cin, pool);

  reverse_lex_sort(pool);
  std::string result_str = ip_int_to_str(pool);
  std::string exp_str =
      "222.173.235.246\n"
      "222.130.177.64\n"
      "222.82.198.61\n"
      "222.42.146.225\n"
      "220.189.194.162\n"
      "220.180.121.6\n"
      "220.132.196.75\n"
      "219.102.120.135\n"
      "219.92.33.137\n"
      "218.185.237.250\n"
      "218.7.166.58\n";

  EXPECT_EQ(result_str, exp_str);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
