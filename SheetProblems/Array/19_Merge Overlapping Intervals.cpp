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
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

class Node{
    public:
        int val;
        Node* next;

        Node(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }
    Node* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(val); 
}

void display(Node* root){
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

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
    for(int i=1;i<intervals.size();i++){
        vector<int> temp2 = intervals[i];
        if(temp2[0]>=temp[0] and temp2[0] <= temp[1]){
            temp = {min(temp[0],temp2[0]),max(temp[1],temp2[1])};
        }else{
            ans.push_back(temp);
            temp = temp2;
        }
    }

    ans.push_back(temp);

    return ans;
}

int32_t main(){
    
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    for(auto &x : overlappedInterval(v)){
        for(auto & y : x)
            cout << y << " ";
        cout << endl;
    }

    
    return 0;
}