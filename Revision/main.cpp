#include <iostream>
#include "base_convert.cpp"

using namespace std;

int main()
{
    int num;
    cout << "Enter Decimal Number" << endl;
    cin>>num;
    cout<<endl<<decimalToBinary2(num);
    return 0;
}
