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
const int N = 1e7+10, MOD = 1e9+7;
long long int ar[N];


int main(){
    
    int n,m;
    cin >> n >> m;
    while (m--)
    {
        int a,b,d;
        cin >> a >> b >> d;
        ar[a] += d;
        ar[b+1] += -d;
    }

    for(int i=1;i<=n;i++){
        ar[i] += ar[i-1];
    }

    long long mx = -1;
    for(int i=1;i<=n;i++){
        mx = max(mx,ar[i]);
    }

    cout << mx << endl;
    
    // O(m*n) = 2*10^5 * 10^7 = 10^12;
    // O(m+n) = 10^7
    
    
    return 0;
}