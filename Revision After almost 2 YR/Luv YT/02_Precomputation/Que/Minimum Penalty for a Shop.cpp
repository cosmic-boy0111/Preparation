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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

int bestClosingTime(string customers) {
    int n = customers.size();
    vector<int> forward = {0};
    int cnt = 0;
    for(auto& x : customers){
        cnt += x == 'N';
        forward.push_back(cnt);
    }
    cnt = 0;
    vector<int> backward(n + 1, 0);
    for(int i = n - 1; i>=0; i--){
        cnt += customers[i] == 'Y';
        backward[i] = cnt;
    }


    int best_hour = 0;
    int min_penalty = forward[0] + backward[0];

    for(int i = 1; i <= n; i++){
        int penalty = forward[i] + backward[i];
        if(penalty < min_penalty){
            min_penalty = penalty;
            best_hour = i;
        }
    }

    return best_hour;
}

int32_t main(){

    

}