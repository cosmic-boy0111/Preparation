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
void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}

void subsets(int arr[],int n){
    int sz = 1<<n;
    for(int i=0;i<sz;i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout << arr[j] << " ";
            }
        }cout << endl;
    }

    cout << endl;
}

int main(){
    

    int arr[] = {1,2,3,4};
    subsets(arr,4);
    
    
    return 0;
}