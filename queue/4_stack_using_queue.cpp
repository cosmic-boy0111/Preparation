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

// making push costly
class Stack{
    int n;
    queue<int> q1;
    queue<int> q2;

    public:
        Stack(){
            n = 0;
        }

        void push(int x){
            q2.push(x);
            n++;
            while (!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1,q2);

        }

        void pop(){
            if(q1.empty()){
                cout << "stack empty" << endl;
                return;
            }
            q1.pop();
            n--;
        }

        int top(){
            if(q1.empty()){
                return -1;
            }
            return q1.front();
        }

        int size(){
            return n;
        }

        bool empty(){
            if(q1.empty()){
                return true;
            }

            return false;
        }

};


// making pop costly
class Stack2{
    int n;
    queue<int> q1;
    queue<int> q2;

    public:
        Stack2(){
            n = 0;
        }

        void pop(){
            if(q1.empty()){
                cout << "stack is empty" << endl;
                return;
            }

            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            q1.pop();
            n--;
            swap(q1,q2);
            
        }

        void push(int x){
            q1.push(x);
            n++;
        }

        int top(){
            if(q1.empty()){
                return -1;
            }

            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            int top = q1.front();
            q2.push(top);
            q1.pop();

            swap(q1,q2);

            return top;
        }

        int size(){
            return n;
        }
};


int main(){
    
    Stack2 st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    cout << st.size() << endl;
    // cout << st.empty() << endl;
    
    return 0;
}