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

vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    unordered_set<int> s;
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0;i<aliceSizes.size();i++){
        sum1 += aliceSizes[i];
    }
    for(int i=0;i<bobSizes.size();i++){
        s.insert(bobSizes[i]);
        sum2 += bobSizes[i];
    }

    // cout << sum1 << " " << sum2 << endl;

    int diff = (sum2 - sum1)/2;

    for(int i=0;i<aliceSizes.size();i++){
        int t = diff + aliceSizes[i];
        if(s.find(t) != s.end()){
            return {aliceSizes[i],t};
        }
    }

    return {-1,-1};

}

int main(){
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);

        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<m;i++){
            cin >> b[i];
        }

        vector<int> temp = fairCandySwap(a,b);

        cout << temp[0] << " " << temp[1] << endl;
    
    
    
    return 0;
}