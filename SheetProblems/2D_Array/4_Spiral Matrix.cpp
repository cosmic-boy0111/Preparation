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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>  ans;
    int startCol = 0;
    int startRow = 0;
    int endCol = matrix[0].size()-1;
    int endRow = matrix.size()-1;
    while (startCol <= endCol and startRow <= endRow){
        for(int i=startCol;i<=endCol;i++){
            ans.push_back(matrix[startRow][i]);
        }
        startRow++;
        for(int i=startRow;i<=endRow;i++){
            ans.push_back(matrix[i][endCol]);
        }
        endCol--;
        if(startRow <= endRow){
            for(int i=endCol;i>=startCol;i--){
                ans.push_back(matrix[endRow][i]);
            }
            endRow--;
        }
        if(startCol <= endCol){
            for(int i=endRow;i>=startRow;i--){
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
        }

    }


    return ans;
    
}

int32_t main(){
    
    int n , m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    for(auto &x : spiralOrder(mat))
        cout << x << " ";
    
    return 0;
}