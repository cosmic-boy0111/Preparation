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


int main(){
    

    int n;
    cin >> n;

    int a[n+1];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    a[n] = INT_MIN;

    int pre_max = INT_MIN;
    int ans = 0;

    for(int i=0;i<n;i++){
        if(a[i] > pre_max and a[i] > a[i+1]){
            pre_max = a[i];
            ans +=1;
        }   
    }

    cout << ans ;
    
    
    
    return 0;
}