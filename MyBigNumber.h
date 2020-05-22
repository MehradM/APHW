#ifndef T14_MYBIGNUMBER_H
#define T14_MYBIGNUMBER_H
#include "BigNumber.h"

class MyBigNumber : public BigNumber {
    friend MyBigNumber operator * (const MyBigNumber& num1, const MyBigNumber& num2);
    friend MyBigNumber operator / (const MyBigNumber& num1, const MyBigNumber& num2);
    friend MyBigNumber operator % (const MyBigNumber& num1, const MyBigNumber& num2);
private:
    static MyBigNumber multByOneDigit(const MyBigNumber& num,int8_t a);
    void operator<<(unsigned shift);
public:
    static MyBigNumber utilityDiv( const MyBigNumber& num1, const MyBigNumber& num2 );
    static MyBigNumber utilityMod( const MyBigNumber& num1, const MyBigNumber& num2 );
    static MyBigNumber attach( const MyBigNumber& num1, const MyBigNumber& num2 );
    MyBigNumber(int8_t * pStart,int8_t * pEnd);
    MyBigNumber();
    MyBigNumber(const MyBigNumber& num): BigNumber(num) {}
    MyBigNumber(const BigNumber& num) : BigNumber(num) {}
    MyBigNumber(const std::string& num) : BigNumber(num) {}
    MyBigNumber( const char * myCharArray ) : BigNumber(myCharArray) {}
    MyBigNumber(const long num) : BigNumber(num) {}
    static MyBigNumber power(const MyBigNumber& num1, unsigned num2);
    MyBigNumber operator()(unsigned startDigit,unsigned steps) const;
    MyBigNumber operator()(unsigned digit) const { if(numArray[digit - 1] == 0) { return "0";} else {return numArray[digit - 1];}}
};

#endif //T14_MYBIGNUMBER_H