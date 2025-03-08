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

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> forward(n, 0);
    forward[0] = arr[0];
    for(int i = 1; i < n; i++){
        forward[i] = forward[i - 1] ^ arr[i];
    }
    for(auto& x : forward){
        cout << x << " ";
    }cout << endl;
    int ans = 0;
    for(int j = 1; j <= n - 2; j++){
        int t = arr[j];
        for(int k =j; k < n; k++){
            if(t == forward[j - 1]) ans++;
            t = t ^ arr[k];
        }
    }

    return ans;
}

int32_t main(){

    int n;
    cin >> n;
    
    vector<int> v(n);
    for(auto& x : v) cin >> x;

    cout << countTriplets(v);

}