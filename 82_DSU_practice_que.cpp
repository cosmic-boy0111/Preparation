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


/*
    1 . has three function
        -> make
        -> find
        -> union
*/


int parent[N];
int size[N];
multiset<int> sizes;

void make( int v ){
    parent[v] = v;
    size[v] = 1;
    sizes.insert(1);
}

int find(int v){
    if(v == parent[v]){
        return v;
    }

    
    return find(parent[v]);
}

void merge(int a,int b){
    sizes.erase( sizes.find(size[a]));
    sizes.erase( sizes.find(size[b]));

    sizes.insert(size[a]+size[b]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b) {
        // union by size
        // complexity = O(alpha(n)) <= 4
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        merge(a,b);
        size[a] += size[b];
    }

}

int32_t main(){
    
    // int n,k;
    // cin >> n >> k;

    // for(int i=1;i<=n;i++){
    //     make(i);
    // }

    // for(int i=1;i<=k;i++){
    //     int u,v;
    //     cin >> u >> v;
    //     Union(u,v);
    // }

    // int c = 0;
    // for(int i=1;i<=n;i++){
    //     if(i == find(i))
    //         c++;
    // }

    // cout << c << endl;


    int n,k;
    cin >> n >> k;

    for(int i=1;i<=n;i++){
        make(i);
    }

    for(int i=1;i<=k;i++){
        int u,v;
        cin >> u >> v;
        Union(u,v);
        if(sizes.size() == 1){
            cout << 0 << endl;
        }else{
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());

            cout << mx-mn << endl;
        }
    }



    return 0;
}