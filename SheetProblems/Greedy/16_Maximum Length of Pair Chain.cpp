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

int findLongestChain(vector<vector<int>>& pairs) {
    // sort(pairs.begin(),pairs.end(),[](vector<int> v1,vector<int> v2){
    //     if((v1[1]-v1[0]) == (v2[1]-v2[0])) return v1[0] < v2[0];
    //     return (v1[1]-v1[0]) < (v2[1]-v2[0]);
    // });                                                 
    sort(pairs.begin(),pairs.end(),[](vector<int> v1,vector<int> v2){
        return v1[1] < v2[1];
    });

    for(auto &x: pairs)
        cout << x[0] << " " << x[1] << endl;
    cout << endl;
    
    auto temp = pairs[0];
    int ans = 1;
    cout << temp[0] << " " << temp[1] << endl;
    for(int i=1;i<pairs.size();i++){
        if(temp[1] < pairs[i][0]){
            cout << pairs[i][0] << " " << pairs[i][1] << endl;
            ans ++;
            temp = pairs[i];
        }
    }

    return ans;

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2));
    for(auto &x : v)
        cin >> x[0] >> x[1];

    cout << findLongestChain(v);

    
    
    return 0;
}