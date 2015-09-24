#include <vector>

struct Interface {
  virtual ~Interface() {}
  virtual int get() const = 0;
};

struct Implementation : public Interface {
  Implementation(int value) : value(new int(value)) {}
  virtual int get() const { return *value; }

private:
  std::auto_ptr<int> value;
};

int sum1(const std::vector<int> &values) {
  int result = 0;
  for (size_t i = 0; i < values.size(); ++i) {
    result += values[i];
  }
  return result;
}

int sum2(const std::vector<int> &values) {
  int result = 0;
  for (auto i = values.begin(), e = values.end(); i != e; ++i) {
    result += *i;
  }
  return result;
}

int sum3(const std::vector<std::auto_ptr<Interface>> &interfaces) {
  int result = 0;
  for (auto I = interfaces.begin(); I != interfaces.end(); ++I) {
    result += (*I)->get();
  }
  return result;
}

void add1(std::vector<int> *frobbles, int d) {
  for (size_t i = 0; i < frobbles->size(); ++i) {
    (*frobbles)[i] += d;
  }
}

