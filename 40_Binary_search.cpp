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
    vector<int> v(n);
    inc(i,0,n){
        cin >> v[i];
    }
    int to_find;
    cin >> to_find;

    int lo = 0, hi = n-1;
    int mid;

    while (hi-lo>1)
    {
        mid = (hi+lo)/2;
        if(to_find<v[mid]){
            hi = mid-1;
        }else{
            lo = mid;
        }
    }

    if(v[lo]==to_find){
        cout << lo << endl;
    }else if(v[hi]==to_find){
        cout << hi << endl;
    }else{
        cout << "Not found" << endl;
    }
    
    
    
    return 0;
}