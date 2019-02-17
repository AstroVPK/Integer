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

  Integer f = d;
  cout << "f" << endl;
  view(f);

  Integer g;
  g = f;
  cout << "g" << endl;
  view(g);

  Integer h = Integer("-7865");
  cout << "h" << endl;
  view(h);

  Integer i;
  i = "-4562867";
  cout << "i" << endl;
  view(i);

  /*
  Integer j = "-8672866"; // Fails because the compiler wants to try to convert "-8672866" -> int so that it can then call Integer::Integer(int).
  cout << "j" << endl;
  view(j);
  */

}
