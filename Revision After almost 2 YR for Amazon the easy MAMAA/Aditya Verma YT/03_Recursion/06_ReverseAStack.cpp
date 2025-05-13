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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

/*
1

2 ---> 
3
*/

void insertBottom(stack<int>& st, int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int top = st.top();
    st.pop();
    insertBottom(st, ele);
    st.push(top);
}

void reverseStack(stack<int>& st){

    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertBottom(st, top);
}

int32_t main(){

    int n;
    cin >> n;
    stack<int> st;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);
    }
    reverseStack(st); // just to get actual stack as we input
    reverseStack(st);
    
    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    

}