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
const int N = 1e6+10, MOD = 1e9+7;

int n;
long long m;
long long trees[N];

bool isSufficient(int h){
    long long wood = 0;
    for(int i=0;i<n;i++){
        if(trees[i]>=h){
            wood += (trees[i] - h);
        }
    }

    return wood >= m;
}

int main(){

    cin >> n >> m;
    inc(i,0,n){
        cin >> trees[i];
    }

    long long lo = 0, hi = 1e9, mid;
    // t t t t f f f f f f
    while (hi-lo> 1)
    {
        mid = (hi+lo)/2;
        if(isSufficient(mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }

    if(isSufficient(hi)){
        cout << hi << endl;
    }else{
        cout << lo << endl;
    }
    
    
    
    return 0;
}