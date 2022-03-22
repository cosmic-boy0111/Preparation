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


long long binExpIter(int a,long long b,int m){
    int ans = 1;
    while (b){
        if(b&1){
            ans = (ans*1LL*a)%m;
        }
        a = (a*1LL*a)%m;

        b>>=1;
    }

    return ans;
    
}

int superPow(int a, vector<int>& b) {
    int pre = 0;
    int sum = 0;
    for(int i=b.size()-1;i>=0;i--){
        sum = (sum + b[i]*binExpIter(10,pre,1140));
        pre++;
    }


    return binExpIter(a,sum,1337);
}

int main(){

    // 50 ^ 64 ^ 32
    // cout << binExpIter(50,binExpIter(64,32,MOD-1),MOD);
    int a,n;
    cin >> a >> n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin >> b[i];
    }



    cout << superPow(a,b);
    
    
    return 0;
}