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
const int N = 1e6, MOD = 1e9+7;



int main(){
    long long T;
    cin >> T;
    while(T--){
        int n,q;
        cin >> n >> q ;
        int a[n+10];
        inc(i,1,n+1){
            cin >> a[i];
        }
        int forward[n+10];
        int backward[n+10];
        forward[0] = backward[n+1] = 0;
        for(int i=1;i<=n;i++){
            forward[i] = __gcd(forward[i-1],a[i]);
        }
        for(int i=n;i>=1;i--){
            backward[i] = __gcd(backward[i+1],a[i]);
        }
        while (q--)
        {
            int l,r;
            cin >> l >> r;

            cout << __gcd(forward[l-1],backward[r+1]) << endl;
        }
        
    }
    

    // O(T*(N+Q*(N))) = O(T*Q*N) = 10^6
    // O(T*(N+Q*(N))) = O(T*Q*N) = 10^11

    // O(T*(N+N)) = O(T*N^2) = 10^6
    
    
    return 0;
}