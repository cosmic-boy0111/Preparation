// que 1


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
const int N = 2e5+10, MOD = 1e9+7;

int hsh[N];
int multiple_ct[N];


int main(){


    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        hsh[x]++;
    }

    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            multiple_ct[i] += hsh[j];
        }
    }

    long long T;
    cin >> T;
    while(T--){
        int p , q;
        cin >> p >> q;
        long long lcm = (p*1LL*q)/__gcd(p,q);
        long long ans = multiple_ct[p] + multiple_ct[q];
        if(lcm < N) ans -= multiple_ct[lcm];

        cout << ans << endl;
    }
    
    
    
    return 0;
}