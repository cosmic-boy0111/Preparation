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
    int l = 0;
    while ( root != NULL ){
        l++;
        root = root->next;
    }

    return l;
    
}

ListNode *swapkthnode(ListNode* head, int num, int k){

    if(k  > num) return head;

    ListNode* ptr1 = NULL;
    ListNode* temp1 = head;
    ListNode* ptr2 = NULL;
    ListNode* temp2 = head;

    for(int i=0;i<k-1;i++){
        ptr1 = temp1;
        temp1 = temp1->next;
    }

    for(int i=0;i<num-k;i++){
        ptr2 = temp2;
        temp2 = temp2->next;
    }

    if(ptr1) ptr1->next = temp2;
    if(ptr2) ptr2->next = temp1;
    ListNode* t = temp1->next;
    temp1->next = temp2->next;
    temp2->next = t;

    if(k == 1) head = temp2;
    if(k == num) head = temp1;

    return head;    

}

int32_t main(){
    

    
    
    return 0;
}