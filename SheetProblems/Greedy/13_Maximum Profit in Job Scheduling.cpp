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



int solve(vector<pair<pair<int,int>,int>> v,int i,int ans,pair<int,int> prePair){
    if(i == v.size()){
        // cout << ans << endl;

        return ans;
    }


    int t = i+1;
    if(v[i].first.first >= prePair.second){
    cout << prePair.first << " " << prePair.second << ":" << v[i].first.first << " " << v[i].first.second << endl;
        ans+=v[i].second;
        int choose1 = solve(v,t,ans,v[i].first);
        ans-=v[i].second;
        int choose2 = solve(v,t,ans,v[i].first);
        return max(choose1,choose2);
    }
    // cout << prePair.first << " " << prePair.second << ":" << v[i].first.first << " " << v[i].first.second << endl;

    return solve(v,t,ans,v[i].first);

}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    vector<pair<pair<int,int>,int>> v;
    int n = startTime.size();
    for(int i=0;i<n;i++){
        v.push_back({{startTime[i],endTime[i]},profit[i]});
    }

    sort(v.begin(),v.end(),[](
        pair<pair<int,int>,int> p1, 
        pair<pair<int,int>,int> p2)
        {return p1.first.first < p2.first.first ;}
    );
    
    return solve(v,0,0,{0,0});

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    vector<int> profit(n);

    for(auto &x : start)
        cin >> x;
    for(auto &x : end)
        cin >> x;
    for(auto &x : profit)
        cin >> x;


    cout << jobScheduling(start,end,profit);
    
    
    return 0;
}