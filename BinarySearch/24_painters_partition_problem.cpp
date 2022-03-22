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

bool isFeasible(int boards[],int n,int m,int mid){
    int painters = 1;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += boards[i];
        if(sum > mid){
            painters++;
            if(painters > m)
                return false;
            sum = boards[i];
        }
    }

    return true;
}

int paintersPartision(int boards[],int n,int m){
    int totalLength = 0, k = 0;
    for(int i=0;i<n;i++){
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int ans = -1;

    int lo = k , hi = totalLength;
    while (lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(isFeasible(boards,n,m,mid)){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid + 1;
        }
    }

    return ans;
    
}

int main(){
    
    int arr[] = {10,20,30,40};
    int n = 4;
    int m = 2;

    cout << paintersPartision(arr,n,m) << endl;
    
    return 0;
}