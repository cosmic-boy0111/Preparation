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
bool static comp(vector<int>&v1 , vector<int>&v2){
    if(v1[1]==v2[1]) return v1[2]<v2[2];
    return v1[1]<v2[1];
    
}


vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
    vector<vector<int>> v;
    
    for(int i=0 ;i<N ;i++){
        v.push_back({S[i],F[i],i+1});
    }
    
    sort(v.begin(),v.end(),comp);
    int j=0;
    vector<int> ans;
    ans.push_back(v[j][2]);
    
    for(int i=1; i<N ;i++){
        if(v[i][0]>v[j][1]){
            j=i;
            ans.push_back(v[i][2]);
        }
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }



    return 0;
}