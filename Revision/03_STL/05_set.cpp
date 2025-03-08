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

template<typename T>
void print(T& s){
    cout << s.size() << endl;
    for(auto& x : s){
        cout << x << endl;
    }
}

int32_t main(){

    // maps without values

    // set<string> s;
    // s.insert("abc"); // O(log(n))
    // s.insert("zsdf");
    // s.insert("bcd");

    // auto it = s.find("abc"); // O(log(n))

    // if(it != s.end()){
    //     s.erase(it);
    //     // cout << (*it) << endl;
    // }

    // print(s);


    multiset<string> s1;
    s1.insert("abc"); // O(log(n))
    s1.insert("zsdf");
    s1.insert("bcd");
    s1.insert("abc");

    auto it = s1.find("abc");
    if(it != s1.end()){
        s1.erase(it);
    }
    s1.erase("abc");
    print(s1);



}