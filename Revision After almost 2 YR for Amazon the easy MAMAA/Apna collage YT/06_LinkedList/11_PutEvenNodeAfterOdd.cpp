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

void display(node* head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

void putEvenNodeAfterOdd(node* &head){

    node* odd = head;
    node* even = head->next;

    node* evenStart = even;

    while(odd->next != nullptr and even->next != nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        if(even->next){
            even = even->next;
        }
    }

    odd->next = evenStart;
    
}

int32_t main(){

    node* head = nullptr;  
    vector<int> v = {1, 2, 3, 4, 5, 6};

    for(auto& x : v){
        insertAtTail(head, x);
    }

    display(head);

    putEvenNodeAfterOdd(head);

    display(head);

}