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

long long sum(long long n){
    long long ans  = 0;
    while (n){
        ans += n%10;
        n = n/10;
    }
    return ans;
}


string smallestNumber(int S, int D){
    if(D == 1){
        if(S >= 1 and S<=9) return to_string(S);
        else return "-1";
    }
    long long ans = INT_MAX;;
    long long l = pow(10,D-1);
    long long r = pow(10,D);
    cout << l << " " << r << endl;
    while (r-l > 1){
        long long mid = (l+r)/2;
        long long t = sum(mid);
        if(S == t){
            ans = min(ans,mid);
            l = pow(10,D-1);
            r = mid-1;
            continue;
        }
        if(S <= t){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    if(sum(l) == S)  return to_string(l);
    if(sum(r) == S) return to_string(r);

    return ans == INT_MAX ? "-1" : to_string(ans);
    
}

int32_t main(){
    
    int s , d;
    cin >> s >> d;

    cout << smallestNumber(s,d);
    
    
    return 0;
}