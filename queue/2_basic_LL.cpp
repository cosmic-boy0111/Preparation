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
        node* next;

        node(int data = 0){
            val = data;
            next = NULL;
        }
};


class Queue{
    node* front;
    node* back;

    public:
        Queue(){
            front = NULL;
            back = NULL;
        }

        void push(int x){
            node* n = new node(x);
            if(front == NULL){
                front = n;
                back = n;
                return;
            }
            back->next = n;
            back = n;
        }

        void pop(){
            if(front == NULL){
                cout << "queue undefine" << endl;
                return;
            }

            node* todelete = front;
            front = front->next;
            delete todelete;
        }

        int peek(){
            if(front == NULL){
                cout << "queue undefine" << endl;
                return -1;
            }

            return front->val;            
        }

        bool empty(){
            if(front == NULL){
                return true;
            }

            return false;
        }

};


int main(){
    
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.empty() << endl;
    
    
    return 0;
}