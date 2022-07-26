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

ListNode* merge(ListNode* l1, ListNode* l2){
    if(!l1)return l2;
    if(!l2)return l1; 
    
    ListNode* ans = new ListNode();
    ListNode* answer = ans;
    while(l1 && l2){
        if(l1 -> val < l2 -> val){
            ans -> next = l1;
            l1 = l1 -> next;
            ans = ans -> next;
        }
        else{
            ans -> next = l2;
            l2 = l2 -> next;
            ans = ans -> next;
        }
    }
    if(l1)ans -> next = l1;
    else ans -> next = l2;
    return answer -> next;
    // return temp->next;

}

// ListNode* solve(int k,vector<ListNode*> temp){
//     if(k == 0) return NULL;
//     if(k == 1) return temp[0];
//     if(k == 2) return merge(temp[0],temp[1]);
//     vector<ListNode*> temp1;
//     vector<ListNode*> temp2;
//     int mid = k/2;
//     for(int i=0;i<mid;i++){
//         temp1.push_back(temp[i]);
//     }
//     for(int i=mid;i<k;i++){
//         temp2.push_back(temp[i]);
//     }
//     return merge(solve(mid,temp1),solve(k-mid,temp2));
// }

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())return NULL;
    int n = lists.size();
    while(n > 1){
        for(int i = 0; i < n/2; i++){
            lists[i] = merge(lists[i],lists[n-i-1]);
        }
        n = (n+1)/2;
    }
    return lists.front();
}

int32_t main(){
    
    int k;
    cin >> k;
    vector<ListNode*> v;
    while (k--){
        int n;
        cin >> n;
        ListNode* root = NULL;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            insertAtTail(root,x);
        }
        v.push_back(root);
    }

    display(mergeKLists(v));
    
    
    return 0;
}