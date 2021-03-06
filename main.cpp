#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"
using namespace std;

int main() {
    cout << boolalpha;

//    for(unsigned char i{0}; i <= 127; ++i){
//        std::cout << (int) i << '\t' << i << std::endl;
//    }
    //std::cout << x << std::endl;
//    BigNumber x{-37};
//    string str = "-0000";
//    BigNumber y{str};
//    cout << y << endl;
//    cout << "Enter a number: ";
//    cin >> x;
//    x = -y;
//    BigNumber z = -y;
//    cout << (x != y) << endl;
    BigNumber myBig1 = -17319;
    BigNumber myBig2 = "0000173";
    //cout << BigNumber::unsignedLessOrEqual(myBig1, myBig2) << endl;
    //BigNumber a = BigNumber::unsignedSubtract(myBig1, myBig2);
    cout << (myBig1>>3) << "\t" << (myBig1>>3).getSign() << endl;
    try{
        cout << (myBig2 - myBig1) << endl;
    }
    catch( out_of_range e){
        cout << e.what() << endl;
    }

    try {
        cout << myBig1-- << endl << myBig1 << endl;
        cout << ++++myBig2 << endl;
    }
    catch ( out_of_range e ) {
        e.what();
    }
    MyBigNumber aNumber = "10000032431";
    cout << "aNumber:" << aNumber(6,6) << endl;
    MyBigNumber myNum1 = "0";
    MyBigNumber myNum2 = "1";
    cout << "myNum1 * myNum2:" << myNum1 * myNum2 << endl;
    cout << "MyBigNumber::power(myNum1,4):" << MyBigNumber::power(myNum1,4) << endl;
    MyBigNumber myNum3 = "-1000";
    MyBigNumber myNum4 = "99";
    cout << "myNum3:" << myNum3 << endl;
    cout << "myNum3 / myNum4:" << myNum3 / myNum4 << endl;
    cout << "myNum3 % myNum4:" << myNum3 % myNum4 << endl;
    return 0;
}

