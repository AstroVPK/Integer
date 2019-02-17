#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include "integer.hpp"
#define DEBUG


using namespace std;

Integer::Integer() {
#ifdef DEBUG
  printf("Integer::Integer()\n");
#endif
  digits = 0;
  digitArr.resize(0, 0);
  sign = +1;
}

Integer::Integer(int a) {
#ifdef DEBUG
  printf("Integer::Integer(int a)\n");
#endif
  digits = a;
  digitArr.resize(a, 0);
  sign = +1;
}

Integer::Integer(string const & a) {
#ifdef DEBUG
  printf("Integer::Integer(string const & a)\n");
#endif
  int aInt = stoi(a);
  int rem = 0;
  digits = 0;
  sign = 1;
  if (aInt < 0) {
    sign = -1;
    aInt *= -1;
  }
  if (aInt != 0) {
    while (rem != aInt) {
      rem = aInt%static_cast<int>(pow(10, digits+1));
      digitArr.push_back(static_cast<int>(floor(rem/pow(10, digits))));
      digits += 1;
    }
  } else {
    digits = 1;
    digitArr.push_back(0);
  }
}

Integer::Integer(Integer const & a) {
#ifdef DEBUG
  printf("Integer::Integer(Integer const & a)\n");
#endif
  digits = a.digits;
  sign = a.sign;
  digitArr = a.digitArr;
}

Integer & Integer::operator=(string const & a) {
#ifdef DEBUG
  printf("Integer & Integer::operator=(string const & a)\n");
#endif
  int aInt = stoi(a);
  int rem = 0;
  digits = 0;
  sign = 1;
  if (aInt < 0) {
    sign = -1;
    aInt *= -1;
  }
  if (aInt != 0) {
    while (rem != aInt) {
      rem = aInt%static_cast<int>(pow(10, digits+1));
      digitArr.push_back(static_cast<int>(floor(rem/pow(10, digits))));
      digits += 1;
    }
  } else {
    digits = 1;
    digitArr.push_back(0);
  }
  return *this;
}

Integer & Integer::operator=(Integer const & other) {
#ifdef DEBUG
  printf("Integer & Integer::operator=(Integer const & other)\n");
#endif
  if (&other == this) {
    return *this;
  } else {
    digits = other.digits;
    sign = other.sign;
    digitArr = other.digitArr;
    return *this;
  }
}

int & Integer::operator[](int pos) {
  if ((pos >= 0) and (pos < digits)) {
    return digitArr[pos];
  } else {
    throw invalid_argument("Invalid index");
  }
}

int Integer::getDigits() const {
  return digits;
}

int Integer::getSign() const {
  return sign;
}
/*
Integer operator+(Integer const & x, Integer const & y) {
  // Two cases ii. x and y both positive or negative; & ii. x or y negative
  if (x.getSign()*y.getSign() == 1) { // i. x & y both positive or negative
    int zDigits = max(x.getDigits(), y.getDigits()) + 1;
  } else { // ii. x or y negative

  }
  return Integer("0");
}

Integer operator+(Integer const & x, int y) {
  Integer const yInt{y};
  return x+yInt;
}

Integer operator+(int x, Integer const & y) {
  Integer const xInt{x};
  return xInt+y;
}

Integer operator*(Integer const & x, Integer const & y) {
  return karatsuba_multiply(x, y);
}

Integer operator*(Integer const & x, int y) {
  Integer const yInt{y};
  return x*yInt;
}

Integer operator*(int x, Integer const & y) {
  Integer const xInt{x};
  return xInt*y;
}

Integer karatsuba_multiply(Integer const & a, Integer const & y) {
  return Integer("0");
}
*/
