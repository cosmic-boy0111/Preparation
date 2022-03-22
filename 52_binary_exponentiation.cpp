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

int binExpRecur(int a,int b){

    if(b==0) return 1;

    int res = binExpRecur(a,b/2);

    if(b&1){
        return (a*(res*1LL*res)%MOD)%MOD;
    }

    return (res*1LL*res)%MOD;

}

int binExpIter(int a,int b){
    int ans = 1;
    while (b)
    {
        if(b&1){
            ans = (ans*1LL*a)%MOD;
        }
        a = (a*1LL*a)%MOD;

        b>>=1;
    }

    return ans;
    
}

int main(){
    
    
    int a = 2 , b = 13;
    
    cout << binExpRecur(a,b) << endl;
    cout << binExpIter(a,b) << endl;

    return 0;
}