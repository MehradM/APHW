#ifndef T14_MYBIGNUMBER_H
#define T14_MYBIGNUMBER_H
#include "BigNumber.h"

class MyBigNumber : public BigNumber {
private:
    static MyBigNumber multByOneDigit(const MyBigNumber& num,int8_t a);
public:
    MyBigNumber();
    MyBigNumber(const MyBigNumber& num): BigNumber(num) {}
    MyBigNumber(const BigNumber& num) : BigNumber(num) {}
};

#endif //T14_MYBIGNUMBER_H