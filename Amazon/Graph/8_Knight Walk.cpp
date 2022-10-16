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



vector<pair<int,int>> Kpos = {
    {-2,1},{-1,2},{1,2},{2,1},
    {-2,-1},{-1,-2},{1,-2},{2,-1}
};

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
    int x1=KnightPos[0] ;
    int y1=KnightPos[1] ;
    
    int x2=TargetPos[0] ;
    int y2=TargetPos[1] ;
    
    int count=0 ;
    if(x1==x2 and y1==y2) return 0 ;
    queue<pair<int,int>> q ;
    q.push({x1,y1}) ;
    
    vector<vector<int>> vis(N,vector<int>(N,0)) ;
    while(!q.empty()){
        int n=q.size() ;
        count++ ;
        while(n--){
            auto temp=q.front() ;
            q.pop() ;
            for(int i=0 ; i<Kpos.size() ; i++){
                int X=Kpos[i].first+temp.first ;
                int Y=Kpos[i].second+temp.second ;
                if(X==x2 and Y==y2) return count ;
                if(X>=1 and Y>=1 and X<=N and Y<=N and !vis[X-1][Y-1]){
                    vis[X-1][Y-1]=1 ;
                    q.push({X,Y}) ;
                }
            }
        }
    }
    
    return -1 ;

}


int32_t main(){
    
    int n = 8;
    vector<int> v1= {4,5};
    vector<int> v2= {1,1};

    cout << minStepToReachTarget(v1,v2,n);


    return 0;
}