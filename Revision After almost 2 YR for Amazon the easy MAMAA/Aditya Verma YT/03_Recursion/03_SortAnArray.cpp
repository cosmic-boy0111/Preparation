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

void insert(int arr[], int n, int ele){
    // arr = 5   ele = 2 and n = 1;

    if(n == 0){
        arr[0] = ele;
        return;
    }

    if(arr[n - 1] <= ele){
        arr[n] = ele;
        return;
    }


    int last = arr[n - 1];
    insert(arr, n - 1, ele);
    arr[n] = last;
    
}

void sort(int arr[], int n){
    // base 
    if(n <= 1) return;

    // hypothesis
    sort(arr, n - 1);

    // induction
    // 0 1 5   2    
    insert(arr, n - 1, arr[n - 1]);
}


int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

}