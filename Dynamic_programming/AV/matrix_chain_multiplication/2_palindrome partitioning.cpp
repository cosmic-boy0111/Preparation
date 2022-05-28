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

int dp[1000][1000];

bool isPalindrome(string s,int i,int j){
    string x = "";
    for(int k=i;k<=j;k++){
        x.push_back(s[k]);
    }

    string y = x;
    reverse(y.begin(),y.end());

    return x == y;
}



int minimumPartition(string s, int i,int j){

    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(isPalindrome(s,i,j)){
        dp[i][j] = 0;
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left ;
        int right ;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else{
            left = minimumPartition(s,i,k);
            dp[i][k] = left;
        }
        if (dp[k+1][j] != -1)
            right = dp[k+1][j];
        else{
            right = minimumPartition(s,k+1,j);
            dp[k+1][j] = right;
        }
        int temp  = 1 + left + right;
        ans = min(ans,temp);
    }

    return dp[i][j] = ans;

}

int32_t main(){

    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            dp[i][j] = -1;
        }
    }

    string s;
    cin >> s;

    cout << minimumPartition(s,0,s.size()-1) << endl;

    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            if( dp[i][j] == -1){
                cout << 0 << " ";
                continue;
            }
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    
    return 0;
}