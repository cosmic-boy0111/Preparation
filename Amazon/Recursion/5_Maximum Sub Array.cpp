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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data = 0){
            val = data;
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
vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

vector<int> sum_array;

pair<int,int> solve(int a[],int i,int j){
    if(i > j) return {-1,-1};
    int neg_idx = -1;
    for(int k=i;k<=j;k++){
        if(a[k] < 0){
            neg_idx = k;
            break;
        }
    }

    if(neg_idx == -1) return {i,j};

    pair<int,int> p1 = solve(a,i,neg_idx-1);
    pair<int,int> p2 = solve(a,neg_idx+1,j);

    if(p1 == make_pair(-1,-1)) return p2;
    if(p2 == make_pair(-1,-1)) return p1;

    int sum1 = sum_array[p1.second] - sum_array[p1.first] + a[p1.first];
    int sum2 = sum_array[p2.second] - sum_array[p2.first] + a[p2.first];

    if(sum1 > sum2) return p1;
    if(sum2 > sum1) return p2;

    int l1 = p1.second - p1.first + 1;
    int l2 = p2.second - p2.first + 1;

    if(l1 > l2) return p1;
    if(l2 > l1) return p2;

    return p1;


}

vector<int> findSubarray(int a[], int n) {
    sum_array.push_back(a[0]);
    for(int i=1;i<n;i++){
        sum_array.push_back(sum_array[i-1] + a[i]);
    }
    pair<int,int> ans = solve(a,0,n-1);
    vector<int> result;
    if(ans == make_pair(-1,-1)) return {0};
    for(int j=ans.first;j<=ans.second;j++){
        result.push_back(a[j]);
    }
    return result;
}

int32_t main(){
    
    int n;;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(auto &x : findSubarray(a,n))
        cout << x << " ";
    
    return 0;
}