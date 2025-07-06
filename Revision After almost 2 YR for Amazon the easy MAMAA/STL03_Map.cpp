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
        node* next;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
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


int32_t main(){

    // map or ump store unique keys

    // map 
        // 1. data always in sorted order (lexografical sorted order)
        // 2. map complex data type handle krte
        // 3. insert complexity O(log(n))

    // init
    map< int , int > mp = { {1, 2} };

    // init 2
    map<int, int> mp2;
    // mp2[1] = 2; /// map mdhe janar key 1 value 2
    mp2[5] = 10;
    mp2[1] = 500; // already 1 ahe tychi override krnar

    cout << mp2[1] << endl;

    for(auto& x : mp2){
        cout << x.first << " " << x.second << endl;
    }

    map<string, int> mp;



    // unorderd_map
        // sorted nhi rahnar
        // complex nhi handle krnar
        // inset time complexity O(1)



}