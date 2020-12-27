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

    switch(input){
        case 1: BaseConvert object = BaseConvert();
                object.takeInput();
                cout<<endl<<object.decimalToBinary2();
                break;
    }
    return 0;
}
