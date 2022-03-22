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

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int ans = 2;
    int pd = a[1] - a[0];

    int j=2;
    int curr = 2;

    while (j<n)
    {
        if(pd == a[j] - a[j-1]){
            curr ++;
        }else{
            pd = a[j] - a[j-1];
            curr = 2;
        }

        ans = max(ans,curr);

        j++;
    }

    cout << ans << endl;
    

    
    return 0;
}