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

int BinarySearch(int arr[], int l , int h, int key){

    while (l <= h){
        int mid = (l + h) / 2;
        if(arr[mid] == key) 
            return mid;
        
        if(arr[mid] < key)
            l = mid+1;
        else
            h = mid-1;
    }

    return -1;
    

}

int getPivot(int A[],int l,int h){
    if(l > h) return -1;
    if (l == h) return l;

    int mid = (l + h) /2;
    if (mid < h and A[mid] > A[mid + 1])
        return mid;
 
    if (mid > l and A[mid] < A[mid - 1])
        return (mid - 1);
 
    if (A[l] >= A[mid])
        return getPivot(A, l, mid - 1);
 
    return getPivot(A, mid + 1, h);
}

int search(int A[], int l, int h, int key){
    int pivot = getPivot(A,l,h);
    
    if(pivot == -1)
        return BinarySearch(A,l,h,key);

    if(A[pivot] == key)
        return pivot;

    if(key < A[pivot])
        return BinarySearch(A,l,pivot-1,key);

    return BinarySearch(A,pivot+1,h,key);

    
}

int32_t main(){
    
    int n , key;
    cin >> n >> key;

    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << search(arr,0 , n-1, key);
    
    
    return 0;
}