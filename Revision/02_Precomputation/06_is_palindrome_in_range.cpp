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

int pf[N][26];

int32_t main(){

    int t;
    cin >> t;

    while(t--){

        for(int i=0;i<N;i++){
            for(int j=0;j<26;j++){
                pf[i][j] = 0;
            }
        }

        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        for(int i = 0; i < n; i++){
            pf[i+1][s[i]-'a'] ++;
        }

        for(int i = 0; i < 26; i++){
            for(int j = 1; j <= n; j++){
                pf[j][i] += pf[j-1][i];
            }
        }

        while(q--){  
            int l,r;
            cin>> l >> r;
            int oddct = 0;
            for(int i=0;i<26;i++){
                int charct = pf[r][i] - pf[l-1][i];
                if(charct%2 != 0) oddct++;
            }
            if(oddct>1) cout<< "NO" << endl;
            else cout<< "YES" << endl;
        }


    }

}