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

        node(int data = 0){
            val = data;
            next = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);


void insertAtTail(node* &head,int data){
    node* n = new node(data);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    
}

void display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
    
}

void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startNode;

    int count = 1;

    while (temp->next != NULL)
    {
        if(count == pos){
            startNode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startNode;
    

}


bool detectCycle(node* root){

    if(root == NULL or root->next == NULL)
        return false;

    set<node*> s;

    while (root != NULL){
        if(s.find(root) != s.end()) {
            return true;
        }
        s.insert(root);
        root = root->next;
    }

    return false;
    

}


int32_t main(){
     node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    makeCycle(head,3);

    cout << detectCycle(head) << endl;
    
    
    return 0;
}