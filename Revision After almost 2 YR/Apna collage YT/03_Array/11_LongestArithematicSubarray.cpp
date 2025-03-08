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

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }

    // map<int, vector<int>> mp;
    // for(int i = 1; i <n; i++){
    //     int diff = arr[i] - arr[i-1];
    //     mp[diff].push_back(i);
    // }
    // int ans = INT_MIN;
    // for(auto& x : mp){
    //     int size = x.second.size() + 1;
    //     ans = max(ans, size);
    // }

    int ans = 2;
    int pd = arr[1] - arr[0];
    int j = 2;
    int curr = 2;

    while(j<n){
        if(arr[j] - arr[j-1] == pd){
            curr++;
        }else{
            curr = 2;
            pd = arr[j] - arr[j-1];
        }
        ans = max(ans, curr);
        j++;
    }

    cout << ans;

}