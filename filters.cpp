#include <algorithm>

#include "filters.hpp"

void stream_to_pool(std::istream& in, pool_int& pool) {
  std::string line;

  pool.clear();
  while (getline(in, line)) {
    std::vector<std::string> v = split(line, '\t');
    auto svec = split(v.at(0), '.');
    pool.push_back(strvec_to_intvec(svec));
  }
}

std::vector<std::string> split(const std::string& str, char d) {
  std::vector<std::string> r;

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(d);
  while (stop != std::string::npos) {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

std::vector<int> strvec_to_intvec(std::vector<std::string>& strvec) {
  std::vector<int> i;

  for (std::vector<std::string>::const_iterator s = strvec.cbegin();
       s != strvec.cend(); ++s) {
    i.push_back(std::stoi(*s));
  }

  return i;
}

std::string ip_int_to_str(pool_int& ip_int) {
  std::string res = "";
  for (auto& ip : ip_int) {
    std::string str = "";
    for (auto& ip_part : ip) {
      res += str + std::to_string(ip_part);
      str = ".";
    }
    res += "\n";
  }
  return res;
}

void reverse_lex_sort(pool_int& ip_int) {
  sort(ip_int.begin(), ip_int.end(), std::greater<std::vector<int>>());
}

void first_one_sort(pool_int& ip_int) {
  std::string res = "";
  for (auto& ip : ip_int) {
    if (ip[0] == 1) {
      std::string str = "";
      for (auto& ip_part : ip) {
        res += str + std::to_string(ip_part);
        str = ".";
      }
      res += "\n";
    }
  }
  std::cout << res;
}

void first_46_sec_70(pool_int& ip_int) {
  std::string res = "";
  for (auto& ip : ip_int) {
    if ((ip[0] == 46) && (ip[1] == 70)) {
      std::string str = "";
      for (auto& ip_part : ip) {
        res += str + std::to_string(ip_part);
        str = ".";
      }
      res += "\n";
    }
  }
  std::cout << res;
}

void any_46(pool_int& ip_int) {
  std::string res = "";
  for (auto& ip : ip_int) {
    if (find(ip.begin(), ip.end(), 46) != ip.end()) {
      std::string str = "";
      for (auto& ip_part : ip) {
        res += str + std::to_string(ip_part);
        str = ".";
      }
      res += "\n";
    }
  }
  std::cout << res;
}
