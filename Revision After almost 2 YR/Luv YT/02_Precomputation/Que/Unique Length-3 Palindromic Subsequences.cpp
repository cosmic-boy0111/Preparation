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

int countPalindromicSubsequence(string s) {
    map<char, vector<int>> mp;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]].push_back(i);
    }
    int ans = 0;
    for(auto& x : mp){
        int st = x.second[0];
        int ed = x.second[x.second.size() - 1];
        if(ed-st<=1) continue;
        unordered_map<char, int> mmp;
        for(int i = st+1; i<ed; i++){
            mmp[s[i]]++;
        }
        ans+=mmp.size();
    }
    return ans;
}

int32_t main(){

    string s;
    cin >> s;

    int count = countPalindromicSubsequence(s);

    cout << count << endl;

}