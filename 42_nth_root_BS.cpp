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

double eps  = 1e-6;

int main(){
    

    double  x;
    cin >> x;

    double lo = 1 , hi = x, mid;

    while (hi-lo > eps)
    {
        mid = (hi+lo)/2;
        if(mid*mid < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    cout << setprecision(10) << lo << endl;
    cout << setprecision(10) << hi << endl;
    
    
    return 0;
}