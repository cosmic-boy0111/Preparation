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



int32_t main(){
    
    int k;
    cin >> k;
    vector<vector<int>> a(k);

    for(int i=0;i<k;i++){
        int size;
        cin >> size;
        a[i] = vector<int> (size);
        for(int j=0;j<size;j++)
            cin >> a[i][j];
    }

    vector<int> idx(k,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    inc(i,0,k){
        pq.push({a[i][0],i});
    }

    vi ans;

    while (!pq.empty()){
        pi x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second]+1 < a[x.second].size())
            pq.push({a[x.second][idx[x.second]+1], x.second});
        
        idx[x.second] += 1;
    }

    each(x,ans)
        cout << x << " ";
    
    


    
    return 0;
}