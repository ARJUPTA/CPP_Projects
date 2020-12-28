#include <iostream>
#include "base_convert.cpp"

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
    choice(2,"Convert Binary to Decimal")
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
    switch(input){
        case 1: baseConvert = BaseConvert();
                baseConvert.takeInput();
                cout<<endl<<baseConvert.decimalToBinary2();
                break;
        case 2: baseConvert = BaseConvert();
                baseConvert.takeBinaryInput();
                cout<<endl<<baseConvert.binaryTodecimal();
                break;
    }
    return 0;
}
