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

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.first != p2.first)
        return (p1.first < p2.first);
    return p2.second > p1.first;
}

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    
    
    return 0;
}