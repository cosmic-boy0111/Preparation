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

vector <int> maxOfMin(int arr[], int n){
    stack<int> leftMin,rightMin;
    vector<int> leftMinPos(n+1,-1),rightMinPos(n+1,n);
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){


        while(!leftMin.empty() && arr[leftMin.top()]>=arr[i]){
            leftMin.pop();
        }
        if(leftMin.empty())
            leftMinPos[i]=-1;
        else
            leftMinPos[i]=leftMin.top();
        leftMin.push(i);
    


        while(!rightMin.empty() && arr[rightMin.top()]>=arr[n-i-1]){
            rightMin.pop();
        }
        if(rightMin.empty())
            rightMinPos[n-i-1]=n;
        else rightMinPos[n-i-1]=rightMin.top();
        rightMin.push(n-i-1);
    }
    for(int i=0;i<n;i++){
        int pos = rightMinPos[i]-leftMinPos[i]-1;
        // cout << ans[pos] << " " <<arr[i] << endl;
        ans[pos] = max(ans[pos],arr[i]);
    }

    // for(auto &x : ans)
    //     cout << x << " ";
    // cout << endl;

    for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    vector<int> tmp;
    for(int i=1;i<=n;i++){
        tmp.push_back(ans[i]);
    }
    return tmp;
   
}

int32_t main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    for(auto &x : maxOfMin(arr,n))
        cout << x << " ";
    
    
    
    return 0;
}