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


void solve(int n,int s,int d,int h){

    if(n==1){
        cout << "moving " << n << " from " << s <<" to " << d << endl;
        return;
    }
    solve(n-1,s,h,d);

    cout << "moving " << n << " from " << s <<" to " << d << endl;

    solve(n-1,h,d,s);

    return;

}


int main(){


    int n;
    cin >> n;
    int s = 1;
    int h = 2;
    int d = 3;


    solve(n,s,d,h);

    
    
    
    return 0;
}