#ifndef T14_MYBIGNUMBER_H
#define T14_MYBIGNUMBER_H
#include "BigNumber.h"

class MyBigNumber : public BigNumber {
    friend MyBigNumber operator * (const MyBigNumber& num1, const MyBigNumber& num2);
private:
    MyBigNumber(int8_t * pStart,int8_t * pEnd);
    static MyBigNumber multByOneDigit(const MyBigNumber& num,int8_t a);
    void operator<<(unsigned shift);
public:
    MyBigNumber();
    MyBigNumber(const MyBigNumber& num): BigNumber(num) {}
    MyBigNumber(const BigNumber& num) : BigNumber(num) {}
    MyBigNumber(const std::string& num) : BigNumber(num) {}
    MyBigNumber(const long num) : BigNumber(num) {}
    static MyBigNumber power(const MyBigNumber& num1, unsigned num2);
    MyBigNumber operator()(unsigned startDigit,unsigned steps);
};

#endif //T14_MYBIGNUMBER_H