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


bool ipv4(string s){
    int cnt = 0;
    string val = "";
    for(int i=0;i<s.size();i++){
        if(s[i]-'0' > 9) return false;
        if(i+1 < s.size() and s[i] == '.' and s[i+1] == '.') return false;
        if(s[i] != '.'){
            val.push_back(s[i]);
            int t = stoi(val);
            if(i+1 < s.size() and t == 0 and s[i+1] != '.') return false;
        }else{
            if(stoi(val) < 0 or stoi(val) > 255) return false;
            val = "";
            cnt++;
        }
    }
    if(stoi(val) < 0 or stoi(val) > 255) return false;
    if(cnt != 3) return false;
    return true;
}


bool ipv6(string s){
    string temp = "";
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if( ! ((s[i]-'0'>=0 and s[i]-'0' <= 9) || (s[i]>='A' and s[i]<='F') || (s[i] >='a' and s[i]<='f')) and s[i] != ':') {
            return false;
        }
        if(i+1 < s.size() and s[i] == ':' and s[i+1] == ':') return false;
        if(s[i] != ':'){
            temp.push_back(s[i]);
        }else{
            if(temp.size() > 4) return false;
            temp = "";
            cnt ++;
        }
    }
    if(temp == "") return false;
    if(cnt != 7) return false;
    return true;
}

string validIPAddress(string queryIP) {
    if(ipv4(queryIP)) return "ipv4";
    if(ipv6(queryIP)) return "ipv6";
    return "Neither";
}

int32_t main(){

    string s;
    cin >> s;

    cout << validIPAddress(s);
    
    return 0;
}