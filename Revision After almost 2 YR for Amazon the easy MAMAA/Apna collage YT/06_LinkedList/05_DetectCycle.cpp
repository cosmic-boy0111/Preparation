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

void makeCycle(node* head, int pos){

    node* start;
    pos--;
    while (head->next != nullptr ){
        if(pos == 0){
            start = head;
        }
        head = head->next;
        pos--;
    }

    head->next = start;

}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
    
}

void removeCycle(node* head){
    node* slow = head;
    node* fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        cout << slow->val << " " << fast->val << endl;

        if(slow == fast){
            break;
        }
    }

    cout << slow->val << " " << fast->val << endl;

    node* temp = head;
    while (temp->next != slow->next){
        temp = temp->next;
        slow = slow->next;
    }

    slow->next = nullptr;
    
    
}

int32_t main(){

    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
   // head->next->next->next->next = new node(5);

    makeCycle(head, 3);
    // cout << head->next->next->next->next->next->val << endl;
    removeCycle(head);
    cout << detectCycle(head) << endl;

}