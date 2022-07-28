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

int find( stack<int> s){
    if(s.empty()) return -1;
    if(s.size() == 1) return s.top();
    if(s.size() >= 2){
        int t1 = s.top();
        s.pop();
        int t2 = s.top();
        s.pop();
        if(t2 < t1){
            s.push(t1);
            s.push(t2);


            string t3 = "";
            while (!s.empty()){
                t3.push_back(s.top()+'0');
                s.pop();
            }
            
            return stoi(t3);
        }
    }

    int top = s.top();
    s.pop();
    int t = find(s);
    if(t == -1) return -1;
    return t*10 + top;

}

int nextGreaterElement(int n) {
    string temp = to_string(n);
    stack<int> st;
    for(auto & x: temp)
        st.push(x-'0');
    return find(st);
}

int32_t main(){
    
    int n;
    cin >> n;

    cout << nextGreaterElement(n);
    
    
    return 0;
}