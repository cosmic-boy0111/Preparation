#include<bits/stdc++.h>
using namespace std;

class hacker { 

    public:
        virtual void print(){
            cout << "Alice love to code \n";
        }

        void show(){
            cout << "bob love to code \n";
        }

};

class hackerEarth : public hacker {

    public:

        void print(){
            cout << "Mike love to code \n";
        }

        void show(){
            cout << "jack love to code \n";
        }

};


int main(){
    
    hacker *hptr;
    hackerEarth obj;

    hptr = &obj;

    hptr->print();
    hptr->show();

}