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

vector<pair<int,int>> posK = {
    {-2,-1},{-2,1},
    {-1, -2},{1, -2},
    {-1, 2},{1, 2},
    {2, -1},{2, 1}
};
bool safe(int i, int j, int N){
       if(i <=0 || j<=0 || i>N||j>N){
           return false;
       }
       return true;
   }
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    // Code here
    
    queue<pair<int,int>> q;
    q.push({KnightPos[0],KnightPos[1]});
    vector<vector<int>>vis(n+1,vector<int>(n+1,false));
    int ans=0;
    vis[KnightPos[0]][KnightPos[1]]=true;
    
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            pair<int,int> temp = q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            
            if(i==TargetPos[0] && j==TargetPos[1]){
                return ans;
            }
            for(auto &x : posK){
                if(safe(i+x.first,j+x.second,n) && vis[i+x.first][j+x.second] == false){
                   q.push({i+x.first,j+x.second});
                   vis[i+x.first][j+x.second] = true;
                }
            }
            
        }ans++;
        
    }
    return -1;
    
}
int32_t main(){
    

    
    
    return 0;
}