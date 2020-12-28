
#include <iostream>

using namespace std;

class BaseConvert{

private:
    long long num;

public:
    BaseConvert(){

    }

    void takeInput(){
        cout<<"\nEnter a decimal number"<<endl;
        long int number;
        cin>>number;
        this->num = number;
    }

    void takeBinaryInput(){
        cout<<"\nEnter a binary number"<<endl;
        long int number;
        cin>>number;
        this->num = number;
    }

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

    long long binaryTodecimal(){
        long long result = 0;
        long long power = 1;
        long n = this->num;
        while(n>0){
            result = result + power*(n%10);
            power*=2;
            n/=10;
        }
        return result;
    }

    int decimalToBinary2(){
        int num = this->num;
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

    int decimalToBinary(){
        int n = this->num;
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
};
