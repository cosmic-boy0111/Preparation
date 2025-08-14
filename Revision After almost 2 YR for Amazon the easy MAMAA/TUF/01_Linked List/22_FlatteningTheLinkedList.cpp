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
        node* child;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            child = NULL;
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

node* makeFlattList(vector<vector<int>>& v){
    node* dummy = new node(-1);
    node* dummyHead = dummy;
    for(int i = 0; i < v.size(); i++){
        node* temp = new node(v[i][0]);
        dummyHead->next = temp;
        for(int j = 1; j < v[i].size(); j++){
            node* t2 = new node(v[i][j]);
            temp->child = t2;
            temp = temp->child;
        }
        dummyHead = dummyHead->next;
    }
    return dummy->next;
}

void printList(node* head){
    node* temp = head;
    while(temp != nullptr){
        node* t1 = temp;
        while (t1 != nullptr){
            cout << t1->val << " ";
            t1 = t1->child;
        }cout << endl;
        temp = temp->next;
    }
}

node* mergeSortList(node* l1, node* l2){
    node* dummy = new node(-1);
    node* dummyHead = dummy;
    while (l1 && l2){
        if(l1->val < l2->val){
            dummyHead->child = l1;
            l1 = l1->child;
        }else{
            dummyHead->child = l2;
            l2 = l2->child;
        }
        dummyHead = dummyHead->child;
    }
    while(l1){
        dummyHead->child = l1;
        l1 = l1->child;
        dummyHead = dummyHead->child;
    }
    while(l2){
        dummyHead->child = l2;
        l2 = l2->child;
        dummyHead = dummyHead->child;
    }
    return dummy->child;
}

node* makeFlat(node* &head){
    node* merge = nullptr;
    node* temp = head;
    while(temp){
        merge = mergeSortList(merge, temp);
        temp = temp->next;
    }
    return merge;
}

void display(node* head){
    while(head != nullptr){
        cout << head->val << "->";
        head = head->child;
    }cout << "null" << endl;
}

int32_t main(){
    vector<vector<int>> v = {
        {3},
        {2, 10},
        {1, 7, 11, 12},
        {4, 9},
        {5, 6, 8}
    };

    node* head = makeFlattList(v);
    printList(head);
    head = makeFlat(head);
    display(head);
}