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

int findLength(node* &head){
    node* temp = head;
    int len = 0;
    while (temp != nullptr){
        len++;
        temp = temp->next;
    }
    return len;
}

bool isIntersect(node* &head1, node* &head2){
    int len1 = findLength(head1);
    int len2 = findLength(head2);

    node* l1 = head1;
    node* l2 = head2;

    if(len1 > len2){
        l1 = head2;
        l2 = head1;
    }

    int diff = abs(len1 - len2);
    while(l2 != nullptr && diff--){
        l2 = l2->next;
    }

    while(l1 != nullptr && l2 != nullptr){
        if(l1 == l2) return true;
        l1 = l1->next;
        l2 = l2->next;
    }

    return false;
}

void makeIntersect(node* &head1, node* &head2, int k){
    node* temp = head1;
    while(--k){
        temp = temp->next;
    }
    node* temp1 = head2;
    while (temp1->next != nullptr){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

node* isIntersectBest(node* &head1, node* &head2){
    node* temp1 = head1;
    node* temp2 = head2;

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;
        
        if(temp1 == nullptr) temp1 = head2;
        if(temp2 == nullptr) temp2 = head1;
    }
    return temp1;
}

int32_t main(){

    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for(auto& x : v1){
        cin >> x;
    }
    for(auto& x : v2){
        cin >> x;
    }

    node* head1 = ArrayToLinkedList(v1);
    node* head2 = ArrayToLinkedList(v2);
    makeIntersect(head1, head2, 3);

    display(head1);
    display(head2);

    cout << (isIntersectBest(head1, head2) ? true : false);
}