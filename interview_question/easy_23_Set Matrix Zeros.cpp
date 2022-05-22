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

void setZeros(vector<vector<int>> &matrix){
    vector<pair<int,int>> pos;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j] == 0)
                pos.push_back({i,j});
        }
    }

    vector<int> visitedRow;
    vector<int> visitedCol;
    visitedRow.assign (1000,1);
    visitedCol.assign (1000,1);

    for(auto &x : pos){
        int row = x.first;
        int col = x.second;
        if(visitedRow[row]){
            for(int i=0;i<matrix[0].size();i++){
                matrix[row][i] = 0;
            }
            visitedRow[row] = 0;
        }
        if(visitedCol[col]){
            for(int i=0;i<matrix.size();i++){
                matrix[i][col] = 0;
            }
            visitedCol[col] = 0;
        }
    }

    

}

int32_t main(){

    int T;
    cin >> T;
    while (T--){
    
        
        int n,m;
        cin >> n >> m;

        vector<vector<int>> matrix;
        for(int i=0;i<n;i++){
            vector<int> temp(m);
            for(auto &x:temp)
                cin >> x;
            matrix.push_back(temp);
        }
        setZeros(matrix);
        for(auto &x:matrix){
            for(auto &y : x)
                cout << y << " ";
            cout << endl;
        }
    
    
    
    }
    return 0;
}