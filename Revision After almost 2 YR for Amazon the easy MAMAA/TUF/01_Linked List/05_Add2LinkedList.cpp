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

int getLength(node* head){
    int length = 0;
    while (head != nullptr){
        length++;
        head = head->next;
    }
    return length;
}

node* add2LinkedList(node* &head1, node* &head2){
    int length1 = getLength(head1);
    int length2 = getLength(head2);
    node* l1 = nullptr;
    node* l2 = nullptr;
    node* head = nullptr;
    if(length1 > length2){
        l1 = head1;
        l2 = head2;
        head = head1;
    }else{
        l1 = head2;
        l2 = head1;
        head = head2;
    }
    int extra = 0;
    while (l2 != nullptr){
        int val = l1->val + l2->val + extra;
        l1->val = val % 10;
        extra = val / 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1){
        while (l1->next != nullptr){
            int val = l1->val + extra;
            l1->val = val % 10;
            extra = val / 10;
            l1 = l1->next;
        }
        
        int val = l1->val + extra;
        l1->val = val % 10;
        extra = val / 10;
    }

    while (extra){
        node* n = new node(extra % 10);
        l1->next = n;
        l1 = n;
        extra = extra / 10;
    }
    
    return head;
}

int32_t main(){

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> p(m);
    for(auto& x : v){
        cin >> x;
    }
    for(auto& x : p){
        cin >> x;
    }

    node* head1 = ArrayToLinkedList(v);
    node* head2 = ArrayToLinkedList(p);

    display(head1);
    display(head2);

    node* head = add2LinkedList(head1, head2);
    display(head);

}