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

int mySqrt(int x) {

    double lo = 1, hi = x;

    while (hi-lo > 0.000000000000001)
    {
        double mid = (hi+lo)/2;
        if(mid*mid < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    return hi;
}

int main(){
    
    
    cout << mySqrt(0);
    
    return 0;
}