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



// 1 --> make an 2d array 
// 2 --> think to store an optimal value in that array

// 3 --> here base condition is change into initialization
// 4 --> convert recursive call into equations
// 5 --> iterrate over all possibility and fill the matrix


int32_t main(){
    

    int T;
    cin >> T;
    while (T--){
    
        int N , C;
        cin >> N >> C; 
        vector<int> volume;
        vector<int> happiness;

            
        for(int i=0;i<N;i++){
            int x;
            cin >> x;
            volume.push_back(x);
        }
        for(int i=0;i<N;i++){
            int x;
            cin >> x;
            happiness.push_back(x);
        }

        int dp[N+1][C+1];
        for(int i=0;i<N+1;i++){
            for(int j=0;j<C+1;j++){
                if(i == 0 or j==0){
                    dp[i][j] = 0;
                }
            }
        }


        for(int i=1;i<=N;i++){
            for(int j=1;j<=C;j++){
                if(volume[i-1] <= j){
                    dp[i][j] = max(happiness[i-1] + dp[i-1][j-volume[i-1]], dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        cout << dp[N][C] << endl;

    }
    return 0;
}