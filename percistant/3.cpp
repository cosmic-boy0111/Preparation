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
vector<bool> visited(N,false);


int getCnt(vector<int> v,int p,int q){
    int sum = 0;
    for(auto &x:v){
        sum += x;
    }
    vector<int> temp = v;
    int cnt = -1;
    while (sum != 0){
        cout << sum << endl;
        cnt++;
        if(sum < 0){
            return 0;
        }
        sort(temp.begin(),temp.end());
        temp[0] = temp[0] - p;
        if(temp[0] < 0) temp[0] = 0;
        for(int i=1;i<v.size();i++){
            if(temp[i] == 0) continue;
            temp[i] = temp[i] - q;
            if(temp[i] < 0) temp[i] = 0;
        }

        int tempSum = 0;

        for(int i=0;i<v.size();i++){
            tempSum += temp[i];
        }

        sum = tempSum;

    }

    return cnt;
    

}

int32_t main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    int p,q;
    cin >> p >> q;
    
    cout << getCnt(v,p,q);
    
    return 0;
}