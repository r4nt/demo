#include <vector>
#include <iostream>

using std::cout;
double f(const double *p);
void x(const std::vector<double> &v) {
  for (int i = 0; i < v.size(); ++i) // bad
    cout << v[i] << '\n';

  for (auto p = v.begin(); p != v.end(); ++p) // bad
    cout << *p << '\n';

  for (auto &x : v) // OK
    cout << x << '\n';

  for (int i = 1; i < v.size();
       ++i) // touches two elements: can't be a range-for
    cout << v[i] + v[-1] << '\n';

  for (int i = 1; i < v.size();
       ++i) // possible side-effect: can't be a range-for
    cout << f(&v[i]) << '\n';

  for (int i = 1; i < v.size();
       ++i) { // body messes with loop variable: can't be a range-for
    if (i % 2)
      ++i; // skip even elements
    else
      cout << v[i] << '\n';
  }
}

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

int sum(const std::vector<std::auto_ptr<Interface>> &interfaces) {
  int result = 0;
  for (auto I = interfaces.begin(); I != interfaces.end(); ++I) {
    result += (*I)->get();
  }
  return result;
}

void add(std::vector<int> *frobbles, int d) {
  for (size_t i = 0; i < frobbles->size(); ++i) {
    (*frobbles)[i] += d;
  }
}


