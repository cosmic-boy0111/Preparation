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

node* sort012(node* &head){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    node* temp = head;
    while(temp != nullptr){
        if(temp->val == 0) count0++;
        else if(temp->val == 1) count1++;
        else count2++;
        temp = temp->next;
    }
    node* temp2 = head;
    while (temp2 != nullptr){
        if(count0){
            temp2->val = 0;
            count0--;
        }else if(count1){
            temp2->val = 1;
            count1--;
        }else temp2->val = 2;
        temp2 = temp2->next;
    }
    return head;
}

void checkMap(map<int, pair<node*, node*>> &mp, node* &temp, node* &pre){
    if(pre == nullptr){
        pre = temp;
        mp[temp->val] = {pre, pre};
    }else{
        pre->next = temp;
        pre = temp;
        mp[temp->val].second = pre;
    }
}

node* getHead(map<int, pair<node*, node*>> &mp){
    if(mp.find(0) != mp.end()) return mp[0].first;
    else if(mp.find(1) != mp.end()) return mp[1].first;
    else mp[2].first;
}

node* sort012Map(node* &head){
    map<int, pair<node*, node*>> mp;
    node* temp = head;
    node* pre0 = nullptr;
    node* pre1 = nullptr;
    node* pre2 = nullptr;
    while (temp != nullptr){
        checkMap(mp, temp, 
            temp->val == 0 ? 
            pre0 : temp->val == 1 ? 
            pre1 : pre2
        );
        temp = temp->next;
    }

    head = getHead(mp);
    if(mp.find(0) != mp.end()){
        mp[0].second->next = mp.find(1) != mp.end() ? mp[1].first 
        : mp.find(2) != mp.end() ? mp[2].first : nullptr;
    }
    if(mp.find(1) != mp.end()){
        mp[1].second->next = mp.find(2) != mp.end() ? mp[2].first : nullptr;
    }
    if(mp.find(2) != mp.end()){
        mp[2].second->next = nullptr;
    }
    return head;
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n);
    
    for(auto &x : v){
        cin >> x;
    }

    node* head = ArrayToLinkedList(v);
    display(head);
    head = sort012Map(head);
    display(head);

}