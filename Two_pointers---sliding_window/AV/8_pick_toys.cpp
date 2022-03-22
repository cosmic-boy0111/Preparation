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
void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}
class node{
    public:
        int val;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

int pickToys(string s){
    unordered_map<char,int> mp;
    int start = 0;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(mp.size() <= 2){
            mp[s[i]]++;
        }

        while (mp.size() > 2 and start < s.size()){
            mp[s[start]]--;
            if(mp[s[start]]==0)
                mp.erase(s[start]);
            start++;
        }

        if(mp.size() == 2)
            ans = max(ans,i-start+1);

    }

    return ans;
}

int32_t main(){
    
    cout << pickToys("aabacbebebe");
    
    return 0;
}