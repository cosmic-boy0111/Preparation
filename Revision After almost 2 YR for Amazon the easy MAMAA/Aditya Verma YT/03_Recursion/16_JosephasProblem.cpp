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


void solve(vector<int>& v, int k, int start){

    if(v.size() == 1){
        cout <<  v[0] << endl;
        return;
    }

    int idx = (start+k) % v.size();
    v.erase(v.begin() + idx);

    solve(v, k, idx);

}

int32_t main(){

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0 ; i < n; i++){
        v[i] = i+1;
    }

    solve(v, k-1, 0);
    
}

/*   0 1 2 3 4
     1 2 3 4 5

     0 1 2 3
     1 3 4 5

     1 1 1 1 1
     1 0 1 1 1
     1 0 1 0 1
     0 0 1 0 1

     
      

       3 



*/