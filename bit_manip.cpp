#include <iostream>

class BitManip{
    private:
    long num;
    
    public:
	void takeInput(){
	    long num; 
	    cin>>num;
	    this->num = num;
	}
	
	int setBit(int pos, int val){
	    this->num = (this->num)&&(~(val<<pos));
	    return this->num;
	}
	
	int getBit(int pos){
	    return (this->num)&&(1<<pos);
	}
}