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

vector<vector<char>> convert(int n,int m){
    vector<vector<char>> ans(n,vector<char>(m));
    int startRow = 0;
    int startCol = 0;
    int endRow = n-1;
    int endCol = m-1;
    
    while (startRow <= endRow and startCol <= endCol){
        char c = startRow%2 == 0 ? 'X' : 'O';
        for(int i=startCol;i<=endCol;i++){
            ans[startRow][i] = c;
        }
        startRow++;
        for(int i=startRow;i<=endRow;i++){
            ans[i][endCol] = c;
        }
        endCol--;
        if(startRow <= endRow){
            for(int i=endCol;i>=startCol;i--){
                ans[endRow][i] = c;
            }
            endRow--;
        }
        if(startCol <= endCol){
            for(int i=endRow;i>=startRow;i--){
                ans[i][startCol] = c;
            }
            startCol++;
        }
    }

    return ans;
    
}

int32_t main(){
    
    int n,m;
    cin >> n >> m;

    for(auto &x : convert(n,m)){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}