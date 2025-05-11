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


int getPickIndexInBitonicArray(int arr[], int n){
    int start = 0;
    int end = n - 1;

    while (start <= end){
        int mid = start + (end - start) / 2;
        if(mid > 0 and mid < n - 1){
            if(arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]){
                return mid;
            }else if(arr[mid] > arr[mid - 1]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }else if(mid == 0){
            if(arr[0] > arr[1]){
                return 0;
            }else{
                return 1;
            }
        }else{
            if(arr[n - 1] > arr[n - 2]){
                return n - 1;
            }else{
                return n - 2;
            }
        }
    }

    return -1;
    
}

int findElement(int arr[], int start, int end, int ele, int dir){
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == ele){
            return mid;
        }else if(ele < arr[mid]){
            if(dir){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }else{
            if(dir){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
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

    int idx = getPickIndexInBitonicArray(arr, n);

    int first = findElement(arr, 0, idx, k, 1);
    int second = findElement(arr, idx + 1, n - 1, k, 0);

    if(first != -1) cout << first << endl;
    else cout << second << endl;

}