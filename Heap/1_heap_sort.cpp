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

void heapify(vector<int> &v,int n,int i){
    int maxIdx = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n and v[l] > v[maxIdx]){
        maxIdx = l;
    }

    if(r<n and v[r] > v[maxIdx]){
        maxIdx = r;
    }

    if(maxIdx != i){
        swap(v[i],v[maxIdx]);
        heapify(v,n,maxIdx);
    }

}

void heapSort(vector<int> &v){
    int n = v.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(v,n,i);
    }

    for(int i = n-1 ; i > 0 ; i--){
        swap(v[0],v[i]);
        heapify(v,i,0);
    }

}

int32_t main(){
    

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v)
        cin >> i;

    heapSort(v);
    for(auto &x:v)
        cout << x << " ";
    
    
    return 0;
}