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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

unordered_map<string,bool> mp;

bool isScramble(string s1, string s2) {
    if (s1.size() <= 1) return s1[0] == s2[0];
		
    if (mp.find(s1 + s2) != mp.end()) return mp[s1 + s2];
    
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2) {
        mp[s1 + s2] = false;
        return false;
    }
    /*  
        first condition :  if not swap
                   --------------
                i |             |
            gr | eat        rg eat
            |               |
            ----------------
        
        second condition :  if swap
                   -----------
                i |          |
            gr | eat        rge at
            |                   |
            --------------------
    */


    for(int i=1;i<s1.size();i++){
        string x = s1.substr(0,i);
        string y = s1.substr(i,s1.size()-i);

        if(isScramble(s2.substr(0,x.size()),x) && isScramble(s2.substr(x.size(),y.size()),y) || 
            isScramble(s2.substr(0,y.size()),y) && isScramble(s2.substr(y.size(),x.size()),x)){
            mp[s1+s2] = true;
            return true;
        }
    }

    mp[s1+s2] = false;
    return false;

}

int32_t main(){
    
    string s1,s2;
    cin >> s1 >> s2;

    cout << isScramble(s1,s2) << endl;
    
    
    return 0;
}