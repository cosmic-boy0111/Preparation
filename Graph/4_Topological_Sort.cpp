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


// directed acyclic graph have topological sort


int32_t main(){
    
    int n,m;
    cin >> n >> m;

    int cnt = 0;
    vector<vector<int>> adj_list(n);
    vector<int> inDegree(n,0);
    for( int i=0 ; i<m ; i++ ){
        int u,v;
        cin>> u >> v;
        // u --> v
        adj_list[u].push_back(v);
        inDegree[v]++;
    }
    
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(!inDegree[i]){
            pq.push(i);
        }
    }

    while (!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for(auto j:adj_list[x]){
            inDegree[j]--;
            if(!inDegree[j]){
                pq.push(j);
            }
        }
    }
    
    
    
    return 0;
}