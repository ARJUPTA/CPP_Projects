#include <iostream>
#include "base_convert.cpp"
#include "bit_manip.cpp";

using namespace std;

class choice{
    private:
        int index;
        string description;
    public:
        choice(int i, string d){
            this->index = i;
            this->description = d;
        }
        string getDescription(){
            return this->description;
        }
};

choice Choices[]={
    choice(1,"Convert Decimal to Binary"),
    choice(2,"Convert Binary to Decimal"),
    choice(3,"Get Bit at a Position"),
    choice(4,"Set Bit at a Position"),
    choice(5,"Clear Bit at a Position"),
    choice(6,"Update Bit at a Position"),
    choice(7,"Maximum Subarray sum"),
    choice(8,"Print all Subarrays"),
    choice(9,"Path length to reach target in maze"),
    choice(10,"Maximum profit to keep in a bag"),
};

int main()
{
    int input = 1;
    int choiceLength = sizeof(Choices)/sizeof(Choices[0]);
    cout<<"Available revision topics"<<endl<<endl;

    do{
        for(int i=0; i<choiceLength; i++){
            cout<<i+1<<" "<<Choices[i].getDescription()<<endl;
        }
        cout<<"Give your choice: ";
        cin>>input;
        if(!(input>=1 && input<=choiceLength))
           cout<<" Wrong choice"<<endl;
    }while(!(input>=1 && input<=choiceLength));

    BaseConvert baseConvert;
    BitManip bitManip;
    switch(input){
        case 1: baseConvert = BaseConvert();
                baseConvert.takeInput();
                cout<<endl<<baseConvert.decimalToBinary2();
                break;
        case 2: baseConvert = BaseConvert();
                baseConvert.takeBinaryInput();
                cout<<endl<<baseConvert.binaryTodecimal();
                break;
        case 3: bitManip = BitManip();
                bitManip.takeInput();
                cout<<endl<<bitManip.getBit();
                break;
        case 4: bitManip = BitManip();
                bitManip.takeInput();
                cout<<endl<<bitManip.setBit();
                break;
        case 5: bitManip = BitManip();
                bitManip.takeInput();
                cout<<endl<<bitManip.clearBit();
                break;
        case 6: bitManip = BitManip();
                bitManip.takeInput();
                cout<<endl<<bitManip.updateBit();
                break;
    }
    return 0;
}
