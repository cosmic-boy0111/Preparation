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



int32_t main(){
    
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    inc(i,0,n){
        int start , end;
        cin >> start >> end;
        v.push_back({start,end});
    }

    sort(v.begin(),v.end(),[&](pair<int,int> p1,pair<int,int> p2){
        return p1.second < p2.second;
    });

    // 12 15
    // 10 20
    // 20 30

    int ans = 1;
    pair<int,int> pre = v[0];
    for(int i=1;i<n;i++){
        if(v[i].first >= pre.second){
            ans++;
            pre = v[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}