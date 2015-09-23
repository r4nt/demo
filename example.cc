#include <vector>

int sum1(const std::vector<int> &v) {
  int result = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    result += v[i];
  }
  return result;
}

int sum2(const std::vector<int> &v) {
  int result = 0;
  for (std::vector<int>::const_iterator i = v.begin(), e = v.end(); i != e;
       ++i) {
    result += *i;
  }
  return result;
}
