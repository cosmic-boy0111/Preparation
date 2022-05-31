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

unordered_map<string,int> mp;

int waysToEvaluateTrue(string s,int i,int j,bool isTrue){

    if(i > j) return false;
    if(i == j){
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
            
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(mp.find(temp) != mp.end())
        return mp[temp];

    int ans = 0;
    for(int k=i+1;k<j;k+=2){
        
        int LT = waysToEvaluateTrue(s,i,k-1,true);
        int LF = waysToEvaluateTrue(s,i,k-1,false);
        int RT = waysToEvaluateTrue(s,k+1,j,true);
        int RF = waysToEvaluateTrue(s,k+1,j,false);

        if(s[k] == '&'){
            if(isTrue)
                ans += LT * RT;
            else
                ans += LF*RF + LF*RT + LT*RF;
        }else if(s[k] == '|'){
            if(isTrue)
                ans += LT * RT + LF*RT + LT*RF ;
            else
                ans += LF*RF;
        }else if(s[k] == '^'){
            if(isTrue)
                ans += LF * RT + LT * RF;
            else
                ans += LT*RT + LF*RF;
        }

    }

    mp[temp] = ans;
    return ans;


}

int32_t main(){
    

    
    string s;
    cin >> s;

    cout << waysToEvaluateTrue(s,0,s.size()-1,true);
    
    
    return 0;
}