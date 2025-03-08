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
Given T test cases and in each
test case a number N Print its factorial for each 
Test case % M
Where M = 10^9 + 7


long long fact[N];
int32_t main(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }    

}

*/

/*
Given array a of N integers. Given Q Queries
and in each query given a number X, print
count of that number in array.
*/

// int main(){

//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }

//     int Q;
//     cin >> Q;
//     while (Q--){
//         int n;
//         cin >> n;
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             if(n == a[i]) count++;
//         }
//         cout << n << " " << count << endl;
//     }

//     return 0;
// }

int hsh[N];
int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        hsh[a[i]]++;
    }

    int Q;
    cin >> Q;
    while (Q--){
        int n;
        cin >> n;
        cout << n << " " << hsh[n] << endl;
    }

    return 0;
}