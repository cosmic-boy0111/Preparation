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

vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    
    map<int,long long> mp;
    for(auto& x : segments) {
        mp[x[0]] += x[2];
        mp[x[1]] -= x[2];
    }

    int pre = INT_MIN;
    int col = 0;

    vector<vector<long long>> ans;
    for(auto& x : mp){
        if(col){
            ans.push_back({pre, x.first, col});
        }

        col += x.second;
        pre = x.first;
    }

    return ans;
}

int32_t main(){

    int n;
    cin >> n;
    vector<vector<int>> segments;
    
    for(int i=0; i<n; i++){
        int s, e, c;
        cin >> s >> e >> c;
        segments.push_back({s, e, c});
    }

    vector<vector<long long>> ans = splitPainting(segments);

    for(auto& x : ans){
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }

}