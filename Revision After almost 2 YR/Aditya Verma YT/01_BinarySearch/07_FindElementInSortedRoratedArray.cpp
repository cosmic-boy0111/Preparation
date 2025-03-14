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

int findMinElement(int arr[], int n){
    int start = 0;
    int end = n - 1;

    if(arr[0] <= arr[n - 1]) return 0;

    while(start <= end){
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            return mid;
        }
        if(arr[start] <= arr[mid]){
            if(arr[mid] >= arr[end])
                start = mid + 1;
            else 
                end = mid - 1;
        }
        if(arr[start] >= arr[mid]){
            if(arr[mid] <= arr[end])
                end = mid - 1;
            else 
                start = mid + 1;
        }
    }

    return -1;
}

int findElement(int arr[], int ele, int start, int end){
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == ele) return mid + 1;
        if(ele < arr[mid]) end = mid - 1;
        else start = mid + 1;
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
    int k;
    cin >> k;
    
    int indx = findMinElement(arr, n);

    int ele1 = findElement(arr, k, 0, indx - 1);
    int ele2 = findElement(arr, k, indx, n - 1);

    if(ele1 || ele2){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;k
    }

}