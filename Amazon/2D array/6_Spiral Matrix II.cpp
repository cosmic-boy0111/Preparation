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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

TreeNode(int data = 0){
val = data;
left = NULL;
right = NULL;
}
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new ListNode(val); 
}

void display(ListNode* root){
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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

vector<vector<int>> generateMatrix(int n) {
    int k = 1;
    vector<vector<int>> ans(n,vector<int>(n,0));
    int startRow = 0;
    int startCol = 0;
    int endRow = n-1;
    int endCol = n-1;

    while (startCol <= endCol and startRow <= endRow){
        for(int i=startCol;i<=endCol;i++){
            ans[startRow][i] = k++;
        }
        startRow++;
        for(int i=startRow;i<=endRow;i++){
            ans[i][endCol] = k++;
        }
        endCol--;
        if(startRow <= endRow){
            for(int i=endCol;i>=startCol;i--){
                ans[endRow][i] = k++;
            }
            endRow--;
        }
        if(startCol <= endCol){
            for(int i=endRow;i>=startRow;i--){
                ans[i][startCol] = k++;
            }
            startCol++;
        }

    }
    return ans;
    
}


int32_t main(){
    
    int n ;
    cin >> n;
    for(auto &x : generateMatrix(n)){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }



    return 0;
}