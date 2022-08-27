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

int length(ListNode* root){
    int i = 0;
    while ( root != NULL ){
        i++;
        root = root->next;
    }

    return i;
    
}

ListNode *reverse (ListNode *head, int k){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
   
    int i = 0;
    while (curr and i < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    if(next != NULL){
        head->next = reverse(next,k);
    }

    return prev;
    
}

int32_t main(){
    
    int n , k;
    cin >> n >> k;
    ListNode* root = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insertAtTail(root,x);
    }

    display(root);
    display(reverse(root,k));
    
    
    
    return 0;
}