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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e5+10, MOD = 1e9+7;

int hsh[N][26];

int main(){
    
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<N;i++){
            for(int j=0;j<26;j++){
                hsh[i][j] = 0;
            }
        }
        int n,q;
        cin>> n >> q;
        string s;
        cin>> s;
        for(int i=0;i<n;i++){
            hsh[i+1][s[i]-'a'] ++;
        }
        
        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                hsh[j][i] += hsh[j-1][i];
            }
        }
        while(q--){
            int l,r;
            cin>> l >> r;
            int oddct = 0;
            for(int i=0;i<26;i++){
                int charct = hsh[r][i] - hsh[l-1][i];
                if(charct%2 != 0) oddct++;
            }
            if(oddct>1) cout<< "NO" << endl;
            else cout<< "YES" << endl;
        }
    }

    
    
    
    return 0;
}