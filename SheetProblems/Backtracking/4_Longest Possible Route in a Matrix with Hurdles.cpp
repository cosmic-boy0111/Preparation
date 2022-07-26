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

vector<vector<int>> visited;
vector<pair<int,int>> dir = {
    {-1,0},{0,1},{1,0},{0,-1}
};
int ans = 0;

bool isSafe(vector<vector<int>>& mat,int i,int j){
    return i>=0 and i<mat.size() and j>=0 and j<mat[0].size() and mat[i][j] == 1 and visited[i][j];
}

void path(vector<vector<int>>& mat,int i,int j,int x,int y,int size){
    if(i==x and j==y){
        ans = max(ans,size);
        return;
    }

    if(isSafe(mat,i,j)){
        visited[i][j] = 0;
        for(auto &t : dir){
            if(isSafe(mat,i+t.first,j+t.second)){
                size++;
                path(mat,i+t.first,j+t.second,x,y,size);
                size--;
            }
        }
        visited[i][j] = 1;
    }

    return;

}

int longestPath(vector<vector<int>>& mat,int i,int j,int x,int y) {
    for(int i=0;i<mat.size();i++){
        vector<int> temp(mat[0].size(),1);
        visited.push_back(temp);
    }
    path(mat,i,j,x,y,0);
    return ans;

}

int32_t main(){
    
    int n ,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(auto &x : mat)
        for(auto &y : x)
            cin >> y;

    int i , j;
    cin >> i >> j;
    int x , y;
    cin >> x >> y;

    cout << longestPath(mat,i,j,x,y) << endl;
    
    
    return 0;
}