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

long long smallestNumber(long long num) {
    if(num == 0) return 0;
    if(num < 0){
        string s = to_string(num).substr(1);
        sort(s.begin(),s.end(),[](char a,char b){
            return a>b;
        });
        long long ans = 0;
        for(auto &x : s){
            ans = ans*10 + (x-'0');
        }
        return -1*ans;
    }else{
        string s = to_string(num);
        sort(s.begin(),s.end());
        string temp0 = "";
        int i = 0;
        while (s[i] == '0'){
            temp0.push_back('0');
            i++;
        }

        string result = "";
        result.push_back(s[i]);
        result.append(temp0);
        result.append(s.substr(i+1));
        
        long long ans = 0;
        for(auto &x : result){
            ans = ans*10 + (x-'0');
        }
        return ans;
    }
}

int32_t main(){
    
    int n;
    cin >> n;


    cout << smallestNumber(n);
    
    
    
    return 0;
}