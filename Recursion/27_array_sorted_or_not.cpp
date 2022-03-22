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


bool sortedME(int arr[],int i,int j){
    if(i==j){
        return true;
    }

    return (arr[i]<arr[i+1]) and sortedME(arr,i+1,j);
}

int main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << sortedME(arr,0,n-1);
    
    
    return 0;
}