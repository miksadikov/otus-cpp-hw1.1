#include <cassert>

#include "filters.hpp"

int main() {
  pool_int ip_pool_int;
  stream_to_pool(std::cin, ip_pool_int);

  try {
    // reverse lexicographic sort
    reverse_lex_sort(ip_pool_int);
    std::cout << ip_int_to_str(ip_pool_int);

    // filter by first byte and output
    auto sorted1 = first_one_sort(ip_pool_int);
    std::cout << ip_int_to_str(sorted1);

    // filter by first and second bytes and output
    auto sorted2 = first_46_sec_70(ip_pool_int);
    std::cout << ip_int_to_str(sorted2);

    // filter by any byte and output
    auto sorted3 = any_46(ip_pool_int);
    std::cout << ip_int_to_str(sorted3);

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
