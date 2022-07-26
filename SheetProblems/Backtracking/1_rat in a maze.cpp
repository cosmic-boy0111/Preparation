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

vector<string> paths;
unordered_map<char,pair<int,int>> mp;
vector<vector<int>> visited;

bool isSafe(vector<vector<int>> &m,int n,int i,int j){
    return (i>=0) and (i<n) and (j>=0) and (j<n) and (m[i][j] == 1) and visited[i][j];
}

void ratMaze(vector<vector<int>> &m,int n,int i,int j,string ans){
    if(i  == n-1 and j == n-1){
        if(ans.size() != 0)
            paths.push_back(ans);
        return;
    }

    
    if(isSafe(m,n,i,j)){
        visited[i][j] = 0;
        for(auto &x : mp){
            if(isSafe(m,n,i+x.second.first,j+x.second.second)){
                ans.push_back(x.first);
                ratMaze(m,n,i+x.second.first,j+x.second.second,ans);
                ans.pop_back();
            }
        }
        visited[i][j] = 1;
    }
    return;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> temp = {"-1"};
    mp['U'] = {-1,0};
    mp['R'] = {0,1};
    mp['D'] = {1,0};
    mp['L'] = {0,-1};
    for(int i=0;i<=n;i++){
        vector<int> temp(n+1,1);
        visited.push_back(temp);
    }
    ratMaze(m,n,0,0,"");
    return paths.size() == 0 ? temp : paths;
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<vector<int>> maze(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> maze[i][j];
        }
    }
    for(auto &x : findPath(maze,n))
        cout << x << endl;
    
    
    return 0;
}