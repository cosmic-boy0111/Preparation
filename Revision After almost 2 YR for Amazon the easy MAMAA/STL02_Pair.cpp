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

class cus_data {
    public:
        int val;
        string name;

        cus_data(int val1, string name1){
            val = val1;
            name = name1;
        }
};


int32_t main(){

    // pair collection of two things

    // [[1],[2]]


    // inti 1
    pair<int,string> p1;

    // init 2
    pair<int,int> p2 = {1, 2};
    
    // init 2
    pair<int, int> p3 = make_pair(1, 2);

    // access
    cout << p3.first << " " << p3.second << endl;

    int first = 1;
    cus_data cd(1, "name");

    pair<  int  ,  cus_data  > p4 = {first, cd} ;

    cout << p4.second.name << endl;

    pair< pair<int,int> , vector<int> > p5;
    p5.first = {1, 2};
    p5.second = {1, 2, 3, 4, 5};

    cout << p5.first.second << endl;


    pair< pair<int,map<int, pair<set<pair<int,int>>,int>>> , vector<int> > p5;


}