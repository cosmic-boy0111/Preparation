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
int binarySearch(vector<int> arr, int low,
                 int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high) / 2; 
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    
    return binarySearch(arr, low, (mid - 1), key);
}
 
int findPivot(vector<int> arr, int low, int high)
{
    
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; 
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
 
int pivotedBinarySearch(vector<int> arr, int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
 
    
    
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
 
    
    
    if (arr[pivot] == key)
        return pivot;
 
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
 
    return binarySearch(arr, pivot + 1, n - 1, key);
}

int search(vector<int> &nums,int target){
    return pivotedBinarySearch(nums,nums.size(),target);
}


int32_t main(){
    
    int n , target;
    cin >> n >> target;
    vector<int>  v(n);

    for(auto  & x: v)
        cin >> x;

    cout << search(v,target) << endl;
    
    
    return 0;
}