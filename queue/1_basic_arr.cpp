#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int,int>
#define mi map<int,int>
#define umi unordered_map<int,int>
#define qi queue<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second 
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;
void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}
class node{
    public:
        int val;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};


#define n 20

class Queue{

    int* arr;
    int front;
    int back;

    public:

        Queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void push(int x){
            if(back == n-1){
                cout << "queue overflow" << endl;
                return;
            }

            back++;
            arr[back] = x;

            if(front==-1)
                front++;
        }

        void pop(){
            if(front == -1 || front > back){
                cout << "No element present" << endl;
                return;
            }

            front++;
        }

        int peek(){
            if(front == -1 || front > back){
                cout << "No element present" << endl;
                return -1;
            }

            return arr[front];
        }

        bool empty(){
            if(front == -1 || front > back){
                return true;
            }

            return false;
        }


};

int main(){
    


    
    return 0;
}