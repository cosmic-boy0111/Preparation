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

void print(map<int,string> mp) {
    each(x,mp){
        cout << x.first << " " << x.second << endl;
    }
}

int main(){

    // map<int,string> mp;

    // mp[1] = "abc"; // O(log(n))
    // mp[5] = "ert";
    // mp[3] = "wrt";
    // mp.insert({4,"afg"});
    
    // auto it = mp.find(7); // log(n)

    // mp.erase(it);
    // // mp.clear();
    // // if(it == mp.end()){
    // //     cout << "NO VALUE" << endl;
    // // }else{
    // //     cout << it->first << " " << it->second << endl;
    // // }

    // print(mp);


    map<string,int> mp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        mp[s]++;
    }

    for(auto &x:mp){
        cout << x.first <<" "<< x.second << endl;
    }


    
    return 0;
}