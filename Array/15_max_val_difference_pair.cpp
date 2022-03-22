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

int maxValue(int arr[], int N) {

    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int max2 = INT_MIN;
    int min2 = INT_MAX;

    for(int i=0;i<N;i++){
        max1 = max(max1,arr[i]+i);
        min1 = min(min1,arr[i]+i);
        max2 = max(max2,arr[i]-i);
        min2 = min(min2,arr[i]-i);
    }

    return max((max1 - min1),(max2 - min2));
}

int main(){
    
    int arr[] = {1, 1, 1};
    int n = 3;

    cout << maxValue(arr,n) << endl;
    
    return 0;
}