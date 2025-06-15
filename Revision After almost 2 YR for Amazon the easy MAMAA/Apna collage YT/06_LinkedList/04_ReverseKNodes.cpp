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
// 1 2 3 4 

node* reverse(node* head){

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    node* revHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return revHead;

}

node* reverseKGroup(node* head, int k){

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    
    node* tempHead = head;
    int tempK = k - 1;
    while (head != nullptr && tempK--){
        head = head->next;
    }
    
    if(!head) return tempHead;

    node* revKNode = reverseKGroup(head->next, k);
    head->next = nullptr;
    node* revHead = reverse(tempHead);

    tempHead->next = revKNode;

    return revHead;


}

int32_t main(){

    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int k = 2;

    node* newHead = reverseKGroup(head, k);
    // node* newHead = reverse(head);
    node* revHead = newHead;
    while (revHead){
        cout << revHead->val << " ";
        revHead = revHead->next;
    }
    

}