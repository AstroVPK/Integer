#include <cstddef>
#include <iostream>
#include "integer.hpp"

using namespace std;

void view(Integer & a) {
  cout << "digits: " << a.getDigits() << "; sign: " << a.getSign() << endl;
  if (a.getSign() == -1) {
    cout << "-";
  }
  for (size_t i = a.getDigits()-1; i < -1; --i) {
    cout << a[i];
  }
  cout << endl;
}

int main() {

  Integer a;
  cout << "a" << endl;
  view(a);

  Integer b{4};
  cout << "b" << endl;
  view(b);

  Integer c{"153"};
  cout << "c" << endl;
  view(c);

  Integer d{"-327"};
  cout << "d" << endl;
  view(d);

  Integer e{d};
  cout << "e" << endl;
  view(e);

  e[1] = 9;
  cout << "e" << endl;
  view(e);
  cout << "d" << endl;
  view(d);

  Integer f;
  f = d;
  cout << "f" << endl;
  view(f);

  Integer g = f;
  cout << "g" << endl;
  view(g);

}
