#include "MyBigNumber.h"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

MyBigNumber::MyBigNumber(int8_t * pStart, int8_t * pEnd) {
    
    short length = pEnd - pStart + 1;
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
    MyBigNumber sum = "0";
    MyBigNumber num = "0";
    
    if(num1 == "0" || num2 == "0") {
        return MyBigNumber(string("0"));
    }
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

MyBigNumber MyBigNumber::operator()(unsigned startDigit,unsigned steps) const {
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

MyBigNumber operator / (const MyBigNumber& num1, const MyBigNumber& num2) {
    if(!BigNumber::unsignedGreaterOrEqual(num1,num2)) {
        return "0";
    }
    MyBigNumber div = "0";
    MyBigNumber num = "0";
    MyBigNumber answer = "0";
    for (size_t i = num1.numOfDigits; i > 0; --i)
    {
        num = MyBigNumber::attach(num,num1(i));
        div = MyBigNumber::utilityDiv(num,num2);
        num = MyBigNumber::utilityMod(num,num2);
        answer = MyBigNumber::attach(answer, div);
    }
    answer.sign = (num1.sign == num2.sign);
    return answer;
}


MyBigNumber operator % (const MyBigNumber& num1, const MyBigNumber& num2) {
    auto div = num1 / num2;
    MyBigNumber numOne = num1;
    MyBigNumber numTwo = num2;
    numOne.sign = true;
    numTwo.sign = true;
    div.sign = true;
    MyBigNumber answer("0");
    if((numOne - (numTwo * div)) == "0") {
        return "0";
    }
    if(num1.sign) {
        if(num2.sign) {
            answer = numOne - (numTwo * div);
        }
        else {
            answer = -(numOne - (numTwo * div) - numTwo);
        }
    }
    else {
        if(num2.sign) {
            answer = (numOne - (numTwo * div) - numTwo);
        }
        else {
            answer = -(numOne - (numTwo * div));
        }
    }
    return answer;
}

MyBigNumber MyBigNumber::utilityDiv( const MyBigNumber& num1, const MyBigNumber& num2 ) {
    if(!unsignedGreaterOrEqual(num1,num2)) {
        return "0";
    }
    auto numOne = num1;
    numOne.sign = true;
    auto numTwo = num2;
    numTwo.sign = true;
    int answer = 0;
    MyBigNumber num = numTwo * answer;
    for(;unsignedLessOrEqual(num,num1) && answer < 11;) {
        ++answer;
        num = numTwo * answer;
    }
    if(answer == 10 && unsignedGreaterOrEqual(num1,num)) {
        return 10;
    }
    return --answer;
}



MyBigNumber MyBigNumber::attach( const MyBigNumber& num1, const MyBigNumber& num2 ) {
    if(num1 == "0") {
        return MyBigNumber(num2);
    }
    MyBigNumber numOne = num1;
    numOne << num2.numOfDigits;
    return numOne + num2;
}

MyBigNumber MyBigNumber::utilityMod( const MyBigNumber& num1, const MyBigNumber& num2 ) {
    auto numOne = num1;
    numOne.sign = true;
    auto numTwo = num2;
    numTwo.sign = true;
    auto divAnswer = utilityDiv(numOne,numTwo);
    divAnswer.sign = true;
    if(divAnswer < 10) {
        return numOne - (numTwo * divAnswer);
    }
    else {
        throw invalid_argument("division answer is not single digit");
    }
}
