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
        node* next;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == nullptr){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = n;
}

node* merge(node* &head1, node* &head2){
    node* dummy = new node(-1);
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* ptr3 = dummy;

    while ( ptr1 != nullptr && ptr2 != nullptr ){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    
    if(ptr1 == nullptr){
        ptr3->next = ptr2;
    }else{
        ptr3->next = ptr1;
    }

    return dummy->next;
}

node* mergeRecursive(node* &head1, node* &head2){

    if(head1 == nullptr || head2 == nullptr){
        return head1 ? head1 : head2; 
    }

    node* head = nullptr;
    if(head1->val < head2->val){
        head = head1;
        head1 = head1->next;
    }else{
        head = head2;
        head2 = head2->next;
    }

    head->next = mergeRecursive(head1, head2);

    return head;
}

void display(node* head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

int32_t main(){

    node* head1 = nullptr;
    node* head2 = nullptr;

    vector<int> v1 = {1, 4, 5, 7};
    vector<int> v2 = {2, 3, 6};

    for(auto& x : v1){
        insertAtTail(head1, x);
    }

    for(auto& x : v2){
        insertAtTail(head2, x);
    }

    display(head1);
    display(head2);

    // node* head = merge(head1, head2);
    node* head = mergeRecursive(head1, head2);

    display(head);

}