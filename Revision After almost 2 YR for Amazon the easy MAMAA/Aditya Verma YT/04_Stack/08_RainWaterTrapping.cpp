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
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

Refer : https://www.geeksforgeeks.org/trappin... . 
*/

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // int maxL[n];
    // maxL[0] = arr[0];
    // for(int i=1; i<n; i++){
    //     maxL[i] = max(maxL[i-1], arr[i]);
    // }

    // int maxR[n];
    // maxR[n-1] = arr[n-1];
    // for(int i=n-2; i>=0; i--){
    //     maxR[i] = max(maxR[i+1], arr[i]);
    // }

    // int ans = 0;
    // for(int i=0; i<n; i++){
    //     ans += min(maxL[i], maxR[i]) - arr[i];
    // }

    // cout << ans << endl;

    stack<int> st;
    int ans = 0;

    for(int i = 0; i<n; i++){
        if(st.empty()){
            st.push(i);
            continue;
        }

        while (!st.empty() && arr[st.top()] < arr[i]){
            int top = st.top();
            st.pop();
            if(!st.empty() and arr[st.top()] > arr[top]){
                cout << arr[st.top()] << " " << arr[i] << " " <<  (min(arr[st.top()], arr[i]) - arr[top])*(i-top) << " " << endl;
                ans += (min(arr[st.top()], arr[i]) - arr[top])*(i-st.top()-1);
            }
        }
        
        st.push(i);

    }

    cout << ans << endl;
}