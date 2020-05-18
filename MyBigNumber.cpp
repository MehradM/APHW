#include "MyBigNumber.h"

MyBigNumber MyBigNumber::multByOneDigit(const MyBigNumber& num,int8_t a) {
    int b = 0;
    BigNumber sum(b);
    for (size_t i = 0; i < a; i++){
        sum = sum + num;
    }
    return MyBigNumber(sum);
}

void MyBigNumber::operator<< (unsigned shift) {
    if(shift == 0)
        return;
    int8_t * pNewSerie = new int8_t[numOfDigits + shift];
    for (size_t i = 0; i < numOfDigits ; i++)
    {
        pNewSerie[i + shift] = numArray[i];
    }
    for (size_t i = 0; i < shift; i++)
    {
        pNewSerie[i] = 0;
    }
    delete[] numArray;
    numOfDigits += shift;
    numArray = pNewSerie;
}

MyBigNumber operator * (const MyBigNumber& num1, const MyBigNumber& num2) {
    MyBigNumber sum = 0;
    MyBigNumber num = 0;
    for (size_t i = 0; i < num2.numOfDigits; i++){
        num = MyBigNumber::multByOneDigit(num1,num2[i]);
        num<<i;
        sum = sum + num;   
    }
    return sum;
}

MyBigNumber power(const MyBigNumber& num1, unsigned num2) {
    MyBigNumber powered(1);
    for (size_t i = 0; i < num2; i++){
        powered = powered * num1;
    }
    return powered;
}