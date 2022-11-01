#ifndef MY_MATH_H
#define MY_MATH_H

class MyMath {
private:
  /* data */
public:
  MyMath(/* args */){};
  ~MyMath(){};
  virtual int add_numbers(const int f1, const int f2);
  virtual int subtract_numbers(const int f1, const int f2);
  virtual int multiply_numbers(const int f1, const int f2);
  virtual int my_calculate(int f1, int f2);
};

#endif // MY_MATH_H