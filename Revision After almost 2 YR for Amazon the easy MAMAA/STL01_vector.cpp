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

    // collection 
    // special classes : to strore special way data

    // 1. vector
    // 2. pair
    // 3. map
    // 4. unordered_map
    // 5. set 
    // 6. unordered_set

    // array fiixed size
    // vector dynamic memory

    /// staring vector

    // dec 1
    // vector<int> vec;

    // int n;
    // cin >> n;

    // // dec 2
    // vector<int> vec2(n);

    // assi 1
    // vector<int> vec = {1, 2, 3};

    vector<int> vec; // 10
    // -> 11 -> 20

    // [1][2][3][4][5][][][][][][]

    cout << vec.size() << endl;

    vec.push_back(1); // always back push
    vec.push_back(2); // always back push
    vec.push_back(3); // always back push
    vec.push_back(4); // always back push
    vec.push_back(5); // always back push

    cout << vec.size() << " " << vec[0] << endl;

    // vec.pop_back(); // pop the last

    auto itr = vec.begin(); // [1]
    auto itr2 = vec.end();

    cout << (*itr) << endl; // 1
    // itr++;
    cout << (*itr) << endl; // 2
    
    // for(auto itr = vec.begin(); itr <= vec.end(); itr++){
    //     cout << (*itr) << " ";
    // }cout << endl;

    for(auto& x : vec){
        cout << x << " ";
    }cout << endl;
    
    
    // vec.clear();
    vec.erase(itr + 2);

    for(auto& x : vec){
        cout << x << " ";
    }cout << endl;

    // cout << vec.size() << endl;
    // 1 2 3 4 5

    auto start = vec.begin();
    auto edn = vec.end();

    sort(vec.begin()+2, vec.end()-1);

    vector<int>::iterator it;

    vector<pair<int,map<int,set<int>>>> vec34;
    
}