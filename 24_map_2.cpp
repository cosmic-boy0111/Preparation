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

void print(unordered_map<int,string> mp){
    cout << mp.size() << endl;
    each(x,mp){
        cout << x.first << " " << x.second << endl;
    }
}

int main(){


    unordered_map<int,string> mp;
    mp[1] = "asd";
    mp[5] = "sdf";
    mp[3] = "xvc";
    mp[6] = "iyu";
    mp[5] = "asr";
    
    print(mp);
    
    return 0;
}