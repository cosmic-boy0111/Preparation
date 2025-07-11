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


/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example :

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

int32_t main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int start = 0;
    int end = n - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;
        if(mid > 0 && mid < n - 1){
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                cout << arr[mid] << endl;
                break;
            }else if(arr[mid - 1] > arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }else if(mid == 0){
            if(arr[0] > arr[1]){
                cout << arr[0] << endl;
            }else{
                cout << arr[1] << endl;
            }
            break;
        }else{
            if(arr[n-1] > arr[n-2]){
                cout << arr[n-1] << endl;
            }else{
                cout << arr[n-2] << endl;
            }
            break;
        }
    }

}