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

int isValid(vector<vector<int>> mat){

    map<string,int>mp;
       
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int box = (i/3)*3+(j/3);
            if(mat[i][j]!=0)
            {
                string s1 ="row" + to_string(i) +                 to_string(mat[i][j]);
                string s2 ="col" + to_string(j) + to_string(mat[i][j]);
                string s3 ="box" + to_string(box) + to_string(mat[i][j]);
                mp[s1]++;
                mp[s2]++;
                mp[s3]++;
                if(mp[s1]>1 || mp[s2]>1 || mp[s3]>1)
                {
                    return 0;
                }
            }
            
        }
    
    }
    
    return 1;

}

int32_t main(){
    
    int n = 9;
    vector<vector<int>> mat(9,vector<int>(9));
    for(auto &x : mat)
        for(auto &y : x)
            cin >> y;


    cout << isValid(mat);


    return 0;
}