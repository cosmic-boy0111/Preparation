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

int32_t main(){
    

    int n,m;
    cin >> n >> m;
 
    // vvi adj(n+1,vi(m+1,0));

    // inc(i,0,m){
    //     int x,y;
    //     cin >> x >> y;
    //     adj[x][y] = 1;
    //     adj[y][x] = 1;
    // }

    // for(auto x:adj){
    //     for(auto y:x){
    //         cout << y << " ";
    //     }cout << endl;
    // }


    inc(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    inc(i,1,n+1){
        cout << i << " : " ;
        for(auto x:adj[i])
            cout << x << " ";
        cout << endl;
    }
    
    return 0;
}