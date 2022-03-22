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

string longestCommonPrefix(vector<string> strs) {
    
    map<int,vector<char>> mp;
    for(auto &x:strs){
        for(int i=0;i<x.size();i++){
            if(mp[i].size() == 0){
                mp[i].push_back(x[i]);
            }else if(mp[i][mp[i].size()-1] == x[i]){
                mp[i].push_back(x[i]);
            }
        }
    }

    string ans = "";

    for(auto &x:mp){
        if(x.second.size() == strs.size())
            ans.push_back(x.second[0]);
        else
            break;
    }

    return ans;

}

int main(){
    

    cout << longestCommonPrefix({"flower","flow","flight"});
    
    return 0;
}