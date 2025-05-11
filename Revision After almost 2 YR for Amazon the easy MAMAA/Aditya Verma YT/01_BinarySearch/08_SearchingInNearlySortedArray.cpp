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

int findElement(int arr[], int n, int x){
    int start = 0;
    int end = n - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;
        if(x == arr[mid]) return mid + 1;
        if(mid - 1 >= start && x == arr[mid - 1]) return mid;
        if(mid + 1 <= end && x == arr[mid + 1]) return mid + 2;

        if(x < arr[mid]) end -= 2;
        else start += 2;
    }

    return 0;
}

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x;
    cin >> x;

    int indx = findElement(arr, n, x);
    if(indx){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }


}