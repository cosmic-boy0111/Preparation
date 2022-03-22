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

string convert(string s, int numRows) {
    map<int,vector<char>>  mp;
    int i = 0;
    int j = 0;
    while (i < s.size()){
        j = 0;
        while(j < numRows and i < s.size()){
            mp[j].push_back(s[i]);
            i++;
            j++;
        }
        j = numRows-2;
        while (j > 0 and i < s.size()){
            mp[j].push_back(s[i]);
            j--;
            i++;
        }
        
    }
    string ans = "";
    for(auto &x:mp){
        for(auto &y:x.second){
            ans.push_back(y);
        }
    }

    return ans;
    
}

int32_t main(){
    

    string s;  
    int n;
    cin >> s >> n;

    cout << convert(s,n);
    
    
    return 0;
}