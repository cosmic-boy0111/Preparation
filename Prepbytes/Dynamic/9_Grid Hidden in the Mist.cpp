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
vector<bool> visited(N,false);

long long dp[500][500];

long long minimumTime(vector<vector<int>> &v,int i,int j,int X,int Y){

    if(i== X and Y==j) return v[i][j];

    if(i > X) return INT_MAX;
    if(j > Y) return INT_MAX;

    if(dp[i][j] != 0) return dp[i][j];

    return dp[i][j] = min(v[i][j] + minimumTime(v,i+1,j+1,X,Y),min(
                            v[i][j] + minimumTime(v,i+1,j,X,Y),
                            v[i][j] + minimumTime(v,i,j+1,X,Y)));

}

int32_t main(){
    
    int n,m;
    cin >> n >> m;

    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp(m);
        for(auto &x:temp)   
            cin >> x;
        v.push_back(temp);
    }

    int X,Y;
    cin >> X >> Y;

    cout << minimumTime(v,0,0,X,Y) << endl;


    
    
    return 0;
}