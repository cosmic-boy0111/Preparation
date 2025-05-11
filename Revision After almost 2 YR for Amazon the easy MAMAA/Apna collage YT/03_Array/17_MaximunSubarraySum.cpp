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


int32_t main(){

    // pre-computation
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // int presum[n + 1] = {0};
    // for(int i = 1; i <= n; i++){
    //     presum[i] = presum[i-1] + arr[i - 1];
    // }
    
    // /*
    // 1 2 3 4
    // 1     -> [1]
    // 1 2   -> [1, 2] [2]
    // 1 2 3  -> [1, 2, 3] [2, 3] [3]
    // 1 2 3 4 -> [1, 2, 3, 4] [ 2, 3, 4] [3, 4] [4]
    // */
    // int ans = INT_MIN;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < i; j++){
    //         int sum = presum[i] - presum[j];
    //         ans = max(ans, sum);
    //     }
    // }

    // cout << ans << endl;

    int currSum = 0;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum < 0) currSum = 0;
        ans = max(ans, currSum);
    }

    cout << ans << endl;
    

}
