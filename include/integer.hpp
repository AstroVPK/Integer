#ifndef INTEGER_HPP
#define INTEGER_HPP
#include <vector>
#include <string>


using namespace std;

class Integer {
private:
  int digits;
  int sign;
  vector<int> digitArr;
public:
  explicit Integer();
  explicit Integer(int a);
  explicit Integer(string const & a);
  explicit Integer(Integer const & a);
  Integer & operator=(string const & a);
  Integer & operator=(Integer const & other);
  ~Integer() = default;
  int & operator[](int pos);
  int getDigits() const;
  int getSign() const;
};

Integer operator+(Integer const & x, Integer const & y);
Integer operator+(int x, Integer const & y);
Integer operator+(Integer const & y, int x);

Integer operator*(Integer const & x, Integer const & y);
Integer operator*(int x, Integer const & y);
Integer operator*(Integer const & y, int x);

Integer karatsuba_multiply(Integer const & a, Integer const & y);

#endif /* INTEGER_HPP */
