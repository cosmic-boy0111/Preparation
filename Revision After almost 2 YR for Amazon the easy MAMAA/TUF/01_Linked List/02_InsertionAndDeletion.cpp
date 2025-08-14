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

node* deleteHead(node* &head){
    if(head == nullptr){
        return nullptr;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

node* deleteTail(node* &head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    node* temp = head;
    while (temp->next->next != nullptr){
        temp = temp->next;
    }
    node* deleteNode = temp->next;
    temp->next = nullptr;
    delete deleteNode;
    return head;
}

void display(node* head){
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }cout << "null" << endl;
}
// 1 2 3 4 5

node* deleteKNode(node* &head, int k){
    if( k == 1){
        return deleteHead(head);
    }

    node* temp = head;
    while(temp->next != nullptr && k > 2){
        temp = temp->next;
        k--;
    }
    if(!temp->next) return head;
    node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
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
    head = deleteHead(head);
    display(head);
    head = deleteTail(head);
    display(head);
    head = deleteKNode(head, 3);
    display(head);

}