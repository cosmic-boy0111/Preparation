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

long long maxSubarraySum(int arr[], int n){

    long long totalSum = 0;
    long long ans ;

    vector<int> forward(n);
    vector<int> backward(n);

    for(int i=0;i<n;i++){
        totalSum += arr[i];
        forward.push_back(0);
        backward.push_back(0);
    }

    ans = totalSum;

    forward[0] = arr[0];
    for(int i=1;i<n;i++){
        forward[i] = arr[i] + forward[i-1];
    }

    backward[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        backward[i] = arr[i] + backward[i+1];
    }
    
    for(int i=0;i<n;i++){
        ans = max(ans,totalSum - forward[i]);
    }
    for(int i=n-1;i>=0;i--){
        ans = max(ans,totalSum - backward[i]);
    }


    return ans;
    
}

int32_t main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << maxSubarraySum(arr,n);
    
    return 0;
}