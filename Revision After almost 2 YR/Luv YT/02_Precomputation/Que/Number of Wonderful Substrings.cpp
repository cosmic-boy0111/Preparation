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
  0 1 2 3
a  
b 
c 
d 
e 
f 
g 
h 
i 
j


*/
long long wonderfulSubstrings(string word) {
    long long ans = 0;
    int n = word.size();
    map<int, vector<long long>> mp;
    for(int i = 0; i <= n; i++) {
        mp[i] = vector<long long>(10, 0);
    }

    for(int i = 1; i <= n; i++) {
        mp[i][word[i - 1] - 'a']++;
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 1; j<=n; j++) {
            mp[j][i] += mp[j - 1][i];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            int oddCnt = 0;
            for(int k=0; k < 10; k++) {
                oddCnt += ((mp[j][k] - mp[i][k]) % 2 == 1);
            }
            if(oddCnt <= 1) ans++;
        }
    }
    
    return ans;

}

int32_t main(){

    string s;
    cin >> s;

    cout << wonderfulSubstrings(s) << endl;

}