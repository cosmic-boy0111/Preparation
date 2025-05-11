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
Given array a of N integers Given Q queries and in each query 
given L and R print sum of array elements from inves L to R
(L, R included)


// int a[N];
// int32_t main(){
    
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }

//     int Q;
//     cin >> Q;
//     while(Q -- ) {
//         int l, r;
//         cin >> l >> r;
//         long long sum = 0;
//         for(int i = l; i <= r; i++) {
//             sum += a[i];
//         }
//         cout << sum << endl;
//     }

// }

int a[N];
int pf[N] = {0};
int32_t main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }

    int Q;
    cin >> Q;
    while(Q -- ) {
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << endl;
    }

}

*/

// const int Ne = 1e3 + 10;
// int ar[Ne][Ne];
// int main(){
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             cin >> ar[i][j];
//         }
//     }

//     int q;
//     cin >> q;
//     while (q--){
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         long long sum = 0;
//         for(int i = a; i <= c; i++){
//             for(int j = b; j <= d; j++){
//                 sum += ar[i][j];
//             }
//         }
//         cout << sum << endl;
//     }
    

// }

const int Ne = 1e3 + 10;
int ar[Ne][Ne];
int pf[Ne][Ne];
int main(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> ar[i][j];
            pf[i][j] = ar[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i -1][j -1];
        }
    }

    int q;
    cin >> q;
    while (q--){
        int a, b, c, d;
        cout << pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1] << endl;
    }

    
}