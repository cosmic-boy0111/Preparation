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

node* reverseList(node* head){

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    node* revList = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return revList;

}

void reverseListItr(node* &head){

    if(head == nullptr) return;

    node* prev = nullptr;
    node* curr = head;
    node* next;

    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

}

int32_t main(){

    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);

    node* newHead = reverseList(head);
    node* revHead = newHead;
    while (revHead){
        cout << revHead->val << " ";
        revHead = revHead->next;
    }
    

}