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
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.
Refer : https://www.geeksforgeeks.org/largest... . 

7
6 2 5 4 5 1 6
*/

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> previousMini;
    stack<int> st;

    for(int i=0; i<n; i++){
        if(st.empty()){
            previousMini.push_back(-1);
            st.push(i);
            continue;
        }

        while ( !st.empty() && arr[st.top()] >= arr[i] ){
            st.pop();
        }

        if(st.empty()){
            previousMini.push_back(-1);
        }else{
            previousMini.push_back(st.top());
        }
        
        st.push(i);
    }

    vector<int> nextMini;
    while (!st.empty()){
        st.pop();
    }

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            nextMini.push_back(n);
            st.push(i);
            continue;
        }

        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            nextMini.push_back(n);
        }else{
            nextMini.push_back(st.top());
        }

        st.push(i);
    }
    
    reverse(nextMini.begin(), nextMini.end());

    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        ans = max(ans, (nextMini[i] - previousMini[i] - 1)*arr[i]);
    }

    cout << ans << endl;

}