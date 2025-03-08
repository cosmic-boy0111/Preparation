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

int hsh[N][26];
int32_t main(){

    int t;
    cin >> t;
    while(t--){
        for(int j = 0; j < N; j++){
            for(int i = 1; i <= 26; i++){
                hsh[i][j] = 0;
            }
        }
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for(int i=0; i<n; i++){
            hsh[i+1][s[i] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            for(int i = 1; i <= n; i++){
                hsh[i][j] += hsh[i - 1][j] ;
            }
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            int oddCnt = 0;
            for(int i = 0; i < 26; i++){
                int charCt = hsh[r][i] - hsh[l-1][i];
                if(charCt % 2 != 0) oddCnt++;
            }
            if(oddCnt > 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

}