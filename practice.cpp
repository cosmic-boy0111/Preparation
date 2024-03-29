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


int solve(int n,int arr1[],int arr2[]){

    int arrpS1[n];
    int arrpS2[n];
    arrpS1[0] = arr1[0];
    arrpS2[0] = arr2[0];
    for(int i=1;i<n;i++) arrpS1[i] = arr1[i] + arrpS1[i-1];
    for(int i=1;i<n;i++) arrpS2[i] = arr2[i] + arrpS2[i-1];

    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i == 0)
                ans = max(ans, arrpS2[j] - arrpS2[i] + arr2[i]  + arrpS1[n-1] - arrpS1[j]);
            else
                ans = max(ans, arrpS1[i-1] + arrpS2[j] - arrpS2[i] + arr2[i]  + arrpS1[n-1] - arrpS1[j]);
        }
    }


    return ans;

}


int32_t main(){
    
    int n;
    cin >> n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++) cin >> arr1[i];
    for(int i=0;i<n;i++) cin >> arr2[i];

    cout << solve(n,arr1,arr2);


    return 0;
}