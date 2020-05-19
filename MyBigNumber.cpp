#include "MyBigNumber.h"
#include <iostream>
#include <string>
using namespace std;

MyBigNumber::MyBigNumber(int8_t * pStart, int8_t * pEnd) {
    short length = pEnd - pStart + 1;
    cout << length << endl;
    numArray = new int8_t[length];
    int j = 0;
    for (int8_t * i = pStart; i != (pEnd + 1); ++i) {
        numArray[j] = *i;
        ++j;
    }
    numOfDigits = length;
    this->sign = true;
}
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
    sum.sign = (num1.sign == num2.sign);
    return sum;
}

MyBigNumber MyBigNumber::power(const MyBigNumber& num1, unsigned num2) {
    MyBigNumber powered(1);
    for (size_t i = 0; i < num2; i++){
        powered = powered * num1;
    }
    return powered;
}

MyBigNumber MyBigNumber::operator()(unsigned startDigit,unsigned steps) {
    int8_t * start = 0;
    int8_t * end = 0;
    if(startDigit > numOfDigits) {
        end = numArray + numOfDigits - 1;
    }
    else {
        end  = numArray + startDigit - 1;
    }
    auto dif =(int) (startDigit - steps);
    if((dif) < 0) {
        start = numArray;
    }
    else {
        start = numArray + dif;
    }
    return MyBigNumber(start,end);
}