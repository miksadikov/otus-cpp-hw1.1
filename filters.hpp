
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using pool_int = std::vector<std::vector<int>>;

int file_to_pool(std::string file_name, pool_int& pool);
std::vector<std::string> split(const std::string& str, char d);
std::vector<int> strvec_to_intvec(std::vector<std::string>& strvec);
std::string ip_int_to_str(pool_int& ip_int);
void reverse_lex_sort(pool_int& ip_int);
pool_int first_one_sort(std::vector<std::vector<int>>& ip_int);
pool_int first_46_sec_70(std::vector<std::vector<int>>& ip_int);
pool_int any_46(std::vector<std::vector<int>>& ip_int);