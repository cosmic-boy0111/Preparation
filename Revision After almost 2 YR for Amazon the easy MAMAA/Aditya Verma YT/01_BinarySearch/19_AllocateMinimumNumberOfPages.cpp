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

bool valid(int arr[], int n, int x, int min){
    int sum = 0;
    int students = 1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > min){
            students++;
            if(students > x){
                return false;
            }
            sum = arr[i];
        }
    }

    return true;
}

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    int lo = INT_MIN;
    int hi = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }

    int x;
    cin >> x;

    int ans = 0;

    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(valid(arr,n,x,mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    
    


}