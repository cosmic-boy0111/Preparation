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

void firstNegative(int arr[],int n,int k){
    int start = 0;
    queue<int> q;
    for(int i=0;i<k;i++){
        if(arr[i] < 0)
            q.push(arr[i]);
    }

    if(q.empty())
        cout << 0 << " ";
    else    
        cout << q.front() << " ";
    for(int i=k;i<n;i++){
        if(arr[i] < 0)
            q.push(arr[i]);
        if(arr[start] < 0)
            q.pop();
        if(q.empty())
            cout << 0 << " ";
        else    
            cout << q.front() << " ";
        start++;
    }
}

int32_t main(){
    
    int n,k;
    cin >> n >> k;
    int arr[n];
    inc(i,0,n)
        cin >> arr[i];

    firstNegative(arr,n,k);
    
    return 0;
}