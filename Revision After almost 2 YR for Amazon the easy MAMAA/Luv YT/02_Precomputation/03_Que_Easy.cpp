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


// int32_t main(){

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, q;
//         cin >> n >> q;
//         int a[n+10];
//         for(int i=1; i<=n; i++){
//             cin >> a[i];
//         }
//         while (q--)
//         {
//             int l, r;
//             cin >> l >> r;
//             int gc = 0;
//             for(int i=1; i<=l-1; i++){
//                 gc = __gcd(gc, a[i]);
//             }
//             for(int i=r+1; i<=n; i++){
//                 gc = __gcd(gc, a[i]);
//             }
//             cout << gc << endl;
//         }   
//     }
// }


int32_t main(){

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n+10];
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        int forward[n+10];
        int backward[n+10];
        for(int i=1; i<=n; i++){
            forward[i] = __gcd(forward[i-1], a[i]);
        }
        for(int i=n; i>=0; i--){
            backward[i] = __gcd(backward[i+1], a[i]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(forward[l-1], backward[r+1]) << endl;
        }   
    }
}