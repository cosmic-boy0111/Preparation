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

void solve(vector<int> v,int k,int index,int &ans){
    if(v.size()==1){
        ans = v[0];
        return;
    }

    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index,ans);
}
int main(){

    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }

    k--;

    int index = 0;
    int ans = -1;
    solve(v,k,index,ans);

    cout << ans << endl;

    
    return 0;
}