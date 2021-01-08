#include <iostream>

class knapsack{
private:
    int val[];
    int wt[];
    int W;

    void takeInput(){
        cout<<endl<<"What is the capacity of bag :";
        cin>>this->W;
        cout<<endl<<"What is the count of elements :";
        int n;
        cin>>n;
        cout<<endl<<"Enter the value of elements :"<<endl;
        for(int i=0; i<n; i++)
        cin>>this->val[i];
        cout<<endl<<"Enter the weight of elements :"<<endl;
        for(int i=0; i<n; i++)
        cin>>this->wt[i];
    }
};
