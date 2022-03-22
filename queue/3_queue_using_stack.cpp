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

// two stack approach
class Queue{
    stack<int> s1;
    stack<int> s2;

    public:
        void push(int x){
            s1.push(x);
        }

        int pop(){
            if(s1.empty() and s2.empty()){
                cout << "queue is undefine" << endl;
                return -1;
            }

            if(s2.empty()){
                while (!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            int topval = s2.top();
            s2.pop();
            return topval;
        }

        bool empty(){
            if(s1.empty() and s2.empty()){
                return true;
            }

            return false;
        }
};


// one stack approach

class Queue2{
    stack<int> s1;
    public:
        void push(int x){
            s1.push(x);
        }

        int pop(){
            if(s1.empty()){
                cout << "queue is empty" << endl;
                return -1;
            }

            int x = s1.top();
            s1.pop();
            if(s1.empty()){
                return x;
            }
            int item = pop();
            s1.push(x);

            return item;
        }

        bool empty(){
            if(s1.empty()){
                return true;
            }

            return false;
        }

};



int main(){
    
    Queue2 q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.pop() << endl;
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << q.empty() << endl;
    
    return 0;
}