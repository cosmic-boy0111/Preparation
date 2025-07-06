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

int listLength(node* head){
    int size = 0;
    while(head != nullptr){
        size++;
        head = head->next;
    }
    return size;
}
// 1->2->3->4->5->6
void KAppend(node* &head, int k){
    if(k == 0 || head == nullptr){
        return;
    }
    int size = listLength(head);

    node* newTail = nullptr;
    node* newHead = nullptr;
    node* tail = nullptr;

    int idx = 1;
    node* temp = head;
    while (temp != nullptr)
    {
        if(idx == size - k){
            newTail = temp;
        }
        // idx + 1 == size - k - 1;
        if(idx == size - k + 1){
            newHead = temp;
        }
        if(temp->next == nullptr){
            tail = temp;
        }
        temp = temp->next;
        idx++;
    }

    // cout << head->val << endl;
    // cout << newHead->val << endl;
    // cout << newTail->val << endl;

    newTail->next = nullptr;
    tail->next = head;
    head = newHead;
    
}

void desplay(node* head){
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

int32_t main(){

    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    
    desplay(head);
    KAppend(head, 2);

    desplay(head);


}