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
bool vis[N];


int32_t main(){

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int arr1[n1][n2];
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            cin >> arr1[i][j];
        }
    }

    int arr2[n2][n3];
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < n3; j++){
            cin >> arr2[i][j];
        }
    }

    int ans[n1][n3];
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n3; j++){
            ans[i][j] = 0;
        }
    }

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n3; j++){
            for(int k = 0; k < n2; k++){
                ans[i][j] += arr1[i][k] * arr2[k][j]; 
            }
        }
    }

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n3; j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }

}

