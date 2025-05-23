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
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Refer : https://www.geeksforgeeks.org/next-gr... . 
*/

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    stack<int> st;
    stack<int> ans;

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            ans.push(-1);
            st.push(arr[i]);
            continue;
        }
        
        while (!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push(-1);
        }else{
            ans.push(st.top());
        }
        st.push(arr[i]);
    }

    while (!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    

}