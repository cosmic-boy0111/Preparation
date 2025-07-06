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

int length(node* l){
    int size = 0;
    while (l != nullptr){
        size++;
        l = l->next;
    }
    return size;
}

int intersection(node* head1, node* head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node* ptr1 = nullptr;
    node* ptr2 = nullptr;

    if(l1 > l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d-- && ptr1 != nullptr){
        ptr1 = ptr1->next;
    }

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if(ptr1 == ptr2){
            return ptr1->val;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;
}

int32_t main(){

    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = new node(4);

    node* head2 = new node(5);
    head2->next = head1->next->next;

    cout << intersection(head1, head2);

}