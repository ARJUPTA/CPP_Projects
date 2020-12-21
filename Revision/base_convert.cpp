
#include <iostream>

using namespace std;

int reverseInt(int n){
    int temp = n;
    n = 0;
    while(temp>0){
        int remainder = temp%10;
        n = n*10 + remainder;
        temp/=10;
    }
    return n;
}

int decimalToBinary2(int num){
    int ans = 0;
    int n = 1;
    long int multiply = 1;

    while(n<=num){
        n = n*2;
    }
    n/=2;

    while(n>0){
        int temp = num/n;
        if(ans == 0 && temp==0)
            multiply*=10;
        ans = ans*10 + temp;
        num = num - n*temp;
        n/=2;
    }

    return ans*multiply;
}

int decimalToBinary(int n){
    int ans = 0;
    long int multiply = 1;
    while(n>0){
        int remainder = n%2;
        int quotient = n/2;
        if(ans == 0 && remainder ==0)
            multiply*=10;
        ans = ans*10+remainder;
        n = quotient;
    }
    ans = reverseInt(ans);
    return ans*multiply;
}
