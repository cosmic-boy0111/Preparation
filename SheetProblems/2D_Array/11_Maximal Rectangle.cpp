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

class Node{
    public:
        int val;
        Node* next;

        Node(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }
    Node* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(val); 
}

void display(Node* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> mat(n,vector<int>(m));
    for(int j=0;j<m;j++){
        if(matrix[0][j] == '0')
            mat[0][j] = 0;
        else
            mat[0][j] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == '0')
                mat[i][j] = 0;
            else
                mat[i][j] = 1 + mat[i-1][j];
        }
    }

    // for(auto &x : mat){

    //     for(auto &y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(mat[i][0],ans);
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){ 
            if(mat[i][j] == 0)  continue;
            ans = max(ans,mat[i][j]) ;
            int t = mat[i][j];
            for(int k=j-1;k>=0;k--){
                if(mat[i][k] == 0) break;
                t = min(t,mat[i][k]);
                ans = max(ans,t*(j-k+1));
            }
        }
    }

    return ans;
}

int32_t main(){
    
    int n, m ;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(auto &x : mat)
        for(auto &y : x)
            cin >> y;
    
    cout << maximalRectangle(mat);
    
    
    return 0;
}