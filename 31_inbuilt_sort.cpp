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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;



int main(){

    int n;
    cin >> n;
    // int a[n];
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin()+2,a.end());
    // quick sort, heap sort, insertion sort

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

    
    
    
    return 0;
}