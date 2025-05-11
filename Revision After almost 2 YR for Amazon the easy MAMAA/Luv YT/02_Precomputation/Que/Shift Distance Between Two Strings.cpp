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

long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
    
    vector<long long> next(26, 0);
    vector<long long> prev(26, 0);

    next[0] = nextCost[0];
    for(int i = 1; i < 26; i++) {
        next[i] = next[i-1] + nextCost[i];
    }

    prev[25] = previousCost[25];
    for(int i = 24; i >= 0; i--) {
        prev[i] = prev[i+1] + previousCost[i];
    }

    long long ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == t[i]) continue;
        int si = s[i] - 'a';
        int ti = t[i] - 'a';
        if(si < ti){
            long long nextCount = next[ti] - next[si];
            long long prevCount = prev[0] - prev[si] + prev[ti];
            ans += min(nextCount, prevCount);
        }else{
            long long nextCount = next[25] - next[si] + next[ti];
            long long prevCount = prev[ti] - prev[si];
            ans += min(nextCount, prevCount);
        }
    }

    return ans;

}

int32_t main(){

    string s ,t;
    cin >> s >> t;
    vector<int> nextCost(26);
    vector<int> previousCost(26);
    
    for(int i = 0; i < 26; i++) {
        cin >> nextCost[i];
    }

    for(int i = 0; i < 26; i++) {
        cin >> previousCost[i];
    }

    long long ans = shiftDistance(s, t, nextCost, previousCost);

    cout << ans << endl;

}