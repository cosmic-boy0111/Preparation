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
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

Refer: https://www.geeksforgeeks.org/the-sto... . 
*/

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // stack<pair<int, int>> st;
    // vector<int> ans;

    // for(int i = 0; i < n; i++){
    //     if(st.empty()){
    //         ans.push_back(1);
    //         st.push({arr[i], 1});
    //         continue;
    //     }

    //     int totalSmallCountFromCurrent = 1;
    //     while (!st.empty() && st.top().first <= arr[i]){
    //         totalSmallCountFromCurrent += st.top().second;
    //         st.pop();
    //     }

    //     ans.push_back(totalSmallCountFromCurrent);
    //     st.push({arr[i], totalSmallCountFromCurrent});
    // }

    // or

    stack<int> st;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        if(st.empty()){
            ans.push_back(-1);
            st.push(i);
            continue;
        }

        while (!st.empty() and arr[st.top()] <= arr[i]){
            st.pop();
        }
        /*
         0  1  2  3  4  5  6   
        100 80 60 70 60 75 85
        */
        if(st.empty()){
            ans.push_back(i + 1);
        }else{
            ans.push_back(i-st.top());
        }

        st.push(i);

    }

    for(auto& x : ans){
        cout << x << " ";
    }

}