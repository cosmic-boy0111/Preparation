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



#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

class ListNode {
    public : 
        int val;
        ListNode* next;

        ListNode(int data){
            val = data;
            next = NULL;
        }
        ListNode(){
            val = 0;
            next = NULL;
        }
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* root = new ListNode();
    ListNode* temp = root;
    
    int c = 0;
    while (l1 != NULL || l2 != NULL || c){
        int sum = 0;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }

        sum += c;
        c = sum/10;

        ListNode* n = new ListNode(sum%10);
        temp->next = n;
        temp = temp->next;


    }

    return root->next;
    

}

void travel(ListNode* root){
    while (root != NULL){
        cout << root->val ;
        root = root->next;
    }
}

int32_t main(){
    
    ListNode* root1 = new ListNode(2);
    root1->next = new ListNode(4);
    root1->next->next = new ListNode(3);

    ListNode* root2 = new ListNode(5);
    root2->next = new ListNode(6);
    root2->next->next = new ListNode(4);


    ListNode* ans = addTwoNumbers(root1,root2);
    travel(ans);
    
    
    return 0;
}