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
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
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

node* ArrayToLinkedList(vector<int> &v){
    if(v.size() == 0) return nullptr;
    node* head = new node(v[0]);
    node* mover = head;
    for(int i = 1; i < v.size(); i++){
        node* n = new node(v[i]);
        mover->next = n;
        mover = n;
    }
    return head;
}

void display(node* head){
    while(head != nullptr){
        cout << head->val << "->";
        head = head->next;
    }cout << "null" << endl;
}

node* MergeTwoSortedLinkedList(node* &l1, node* &l2){
    node* dummy = new node(-1);
    node* dummyHead = dummy;
    while (l1 && l2){
        if(l1->val < l2->val){
            dummyHead->next = l1;
            l1 = l1->next;
        }else{
            dummyHead->next = l2;
            l2 = l2->next;
        }
        dummyHead = dummyHead->next;
    }
    while(l1){
        dummyHead->next = l1;
        l1 = l1->next;
        dummyHead = dummyHead->next;
    }
    while(l2){
        dummyHead->next = l2;
        l2 = l2->next;
        dummyHead = dummyHead->next;
    }
    return dummy->next;
}

node* mergeSort(node* &head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* head2 = slow->next;
    slow->next = nullptr;
    node* merge1 = mergeSort(head);
    node* merge2 = mergeSort(head2);

    return MergeTwoSortedLinkedList(merge1, merge2);
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v){
        cin >> x;
    }
    node* head = ArrayToLinkedList(v);
    display(head);
    head = mergeSort(head);
    display(head);
}