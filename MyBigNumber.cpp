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


