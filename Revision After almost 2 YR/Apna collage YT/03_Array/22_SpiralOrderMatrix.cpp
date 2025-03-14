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

    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = m - 1;

    while (rowStart <= rowEnd && colStart <= colEnd){
        for(int i = colStart; i <= colEnd ; i++){
            cout << arr[rowStart][i] << " ";
        }
        rowStart++;
        for(int i = rowStart; i <= rowEnd ; i++){
            cout << arr[i][colEnd] << " ";
        }
        colEnd--;
        for(int i = colEnd; i >= colStart ; i--){
            cout << arr[rowEnd][i] << " ";
        }        
        rowEnd--;
        for(int i = rowEnd; i >= rowStart ; i--){
            cout << arr[i][colStart] << " ";
        }
        colStart++;
    }
    

}
/*
1 2 3 4
1 2 3 4
1 2 3 4

*/