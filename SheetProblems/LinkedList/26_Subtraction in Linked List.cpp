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
        int data;
        node* left;
        node* right;

        node(int val = 0){
            data = val;
            left = NULL;
            right = NULL;
        }
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new ListNode(val); 
}

void display(ListNode* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

int getLength(ListNode* l){
    ListNode* temp = l;
    int ans  = 0;
    while (temp){
        ans +=1;
        temp = temp->next;
    }
    return ans;
}

ListNode* reverseList(ListNode* l){
    if(l == NULL || l->next == NULL) return l;
    ListNode* newHead = reverseList(l->next);
    l->next->next = l;
    l->next = NULL;
    return newHead;
}

ListNode* subLinkedList(ListNode* l1, ListNode* l2){
    
    int len1 = getLength(l1);
    int len2 = getLength(l2);


    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;

    if(len1 < len2){
        swap(ptr1,ptr2);
    }

    for(int i=0;i<abs(len1-len2);i++){
        ListNode* n = new ListNode(0);
        n->next = ptr2;
        ptr2 = n;
    }


    while (ptr1->next and ptr2->next){
        if(ptr1->val < ptr2->val){
            swap(ptr1,ptr2);
            break;
        }
        if(ptr1->val == ptr2->val){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            continue;
        }

        break;
    }

    ListNode* revHead1 = reverseList(ptr1);
    ListNode* revHead2 = reverseList(ptr2);


    ListNode* start = revHead1;
    int carry = 0;

    while (revHead1 and revHead2){
        int d1 = revHead1->val;
        int d2 = revHead2->val;
        int result;
        if(d1-carry >= d2){
            result = d1-carry-d2;
            carry = 0;
        }else{
            result = 10 + d1 - carry - d2;
            carry = 1;
        }

        revHead1->val = result;
        revHead1 = revHead1->next;
        revHead2 = revHead2->next;
    }
    ListNode* ans = reverseList(start);

    while (ans and ans->val == 0){
        ans = ans->next;
    }

    if(ans == NULL) 
        return new ListNode(0);
    
    return ans;

}

int32_t main(){
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    int n , m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        insertAtTail(l1,x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        insertAtTail(l2,x);
    }

    display(subLinkedList(l1,l2));
    
    return 0;
}