#include <iostream>

class BitManip{
    private:
    int num;

    public:
	void takeInput(){
	    int n;
	    cout<<"Enter the number :";
	    cin>>n;
	    this->num = n;
	}

	int setBit(){
	    cout<<"Give the position to set bit to 1 :";
	    int pos;
	    cin>>pos;
	    this->num = (this->num)|(1<<pos);
	    return this->num;
	}

	int getBit(){
	    cout<<"Give the position to check :";
	    int pos;
	    cin>>pos;
	    return ((this->num)&(1<<pos))!=0;
	}

	int clearBit(){
        cout<<"Give the position to clear bit at :";
	    int pos;
	    cin>>pos;
	    return (this->num)&(~(1<<pos));
	}

	int updateBit(){
        cout<<"Give the position to update bit at :";
	    int pos;
        cin>>pos;
	    cout<<"Give the value to be set here(0 or 1) :";
	    int value;
	    cin>>value;
	    this->num = (this->num)&(~(1<<pos));
	    this->num = (this->num)|(value<<pos);
	    return this->num;
	}
};
