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


int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){


    int sum1 = accumulate(S1.begin(),S1.end(),0);
    int sum2 = accumulate(S2.begin(),S2.end(),0);
    int sum3 = accumulate(S3.begin(),S3.end(),0);


    int i = 0;
    int j = 0;
    int k = 0;

    while ( i != N1 and j != N2 and k != N3 ){

        if(sum1 == sum2 and sum2 == sum3) return sum1;
        if(sum1 >= sum2 and sum1 >= sum3)
            sum1 -= S1[i++];
        else if(sum2 >= sum1 and sum2 >= sum3)
            sum2 -= S2[j++];
        else if(sum3 >= sum1 and sum3 >= sum2)
            sum3 -= S3[k++];
    }
    
    return 0;


}

int32_t main(){
    

    int l,m,n;
    cin >> l >> m >> n;
    vector<int> s1(l);
    vector<int> s2(m);
    vector<int> s3(n);
    for(auto &x : s1)
        cin >> x;
    for(auto &x : s2)
        cin >> x;
    for(auto &x : s3)
        cin >> x;

    cout << maxEqualSum(l,m,n,s1,s2,s3);

    
    
    
    return 0;
}