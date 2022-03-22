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


int findKthPositive(vector<int>& arr, int k) {
    for(int x : arr) if (x <= k) k++;
        return k;
}


int main(){
    
    int n,k;
    cin >> n >> k ;
    vector<int> arr(n+1);
    arr[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    cout << findKthPositive(arr,k);
    
    
    return 0;
}