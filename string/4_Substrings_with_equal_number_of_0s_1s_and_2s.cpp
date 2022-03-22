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



int main(){
    
    string str = "102100211";

    int z = 0;
    int o = 0;
    int t = 0;

    int d1 = o-z;
    int d2 = t-o;
    
    map<pair<int,int>,int> mp;
    mp[{d1,d2}] = 1;

    int ans = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0') z++;
        else if(str[i]=='1') o++;
        else t++;

        int d1 = o-z;
        int d2 = t-o;

        if(mp.find({d1,d2}) != mp.end()){
            ans += mp[{d1,d2}];
            mp[{d1,d2}] ++;
        }else{
            mp[{d1,d2}]  = 1;
        }

        cout << d1 << " " << d2 << " : " << mp[{d1,d2}] << endl;
    }

    cout << ans << endl;

    

    return 0;
}