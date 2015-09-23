#include <vector>

int sum(const std::vector<int> &v) {
  int result = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    result += v[i];
  }
  return result;
}
