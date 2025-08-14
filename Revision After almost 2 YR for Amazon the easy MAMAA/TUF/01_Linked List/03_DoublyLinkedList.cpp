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


node* makeDll(vector<int>& v){
    if(v.size() == 0) return nullptr;
    node* head = new node(v[0]);
    node* temp = head;
    for(int i = 1; i < v.size(); i++){
        node* n = new node(v[i]);
        temp->next = n;
        n->prev = temp;
        temp = n;
    }
    return head;
}

void display(node* head){
    while ( head != nullptr ){
        cout << head->val << "<->";
        head = head->next;
    }cout << "null" << endl;
}

node* deleteHead(node* &head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    node* nextNode = head->next;
    head->next = nullptr;
    nextNode->prev = nullptr;
    delete head;
    return nextNode;
}

node* deleteTail(node* &head){
    if(head == nullptr) return nullptr;
    node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    if(tail->prev){
        tail->prev->next = nullptr;
    }
    tail->prev = nullptr;
    if(tail == head){
        delete head;
        return nullptr;
    }
    delete tail;
    return head;
}

node* deleteKthElement(node* &head, int k){
    if(head == nullptr) return nullptr;
    if(k == 1){
        node* nextNode = head->next;
        head->next = nullptr;
        if(nextNode){
            nextNode->prev = nullptr;
        }
        delete head;
        return nextNode;
    }
    node* temp = head;
    while (temp != nullptr && k > 1){
        temp = temp->next;
        k--;
    }

    node* prev = temp->prev;
    node* next = temp->next;
    prev->next = next;
    if(next){
        next->prev = prev;
    }
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

int32_t main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& x : v){
        cin >> x;
    }

    node* head = makeDll(v);
    display(head);
    head = deleteHead(head);
    display(head);
    head = deleteTail(head);
    display(head);
    head = deleteKthElement(head, 1);
    display(head);

}