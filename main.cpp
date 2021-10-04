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
    first_one_sort(ip_pool_int);

    // filter by first and second bytes and output
    first_46_sec_70(ip_pool_int);

    // filter by any byte and output
    any_46(ip_pool_int);

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
