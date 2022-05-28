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

long long findMinDiff(vector<long long> a, long long n, long long m){
    if(m== 0|| n==0) return 0;
    if(m > n) return  -1;
    sort(a.begin(),a.end());

    long long ans = INT_MAX;

    for(int i=0;i + m -1 < n; i++){
        ans = min(ans, a[i+m-1] - a[i]);
    }

    return ans;


} 

int32_t main(){
    
    long long n , m;
    cin >> n >> m;
    vector<long long> v(n);
    for(auto &x : v)
        cin >> x;

    cout << findMinDiff(v,n,m);
    
    return 0;
}