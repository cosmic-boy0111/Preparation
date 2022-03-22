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


bool getBit(int n,int pos){
    return (n&(1<<pos));
}

int setBit(int n,int pos){
    return (n | (1<<pos));
}

int unique(int arr[],int n){

    int result = 0;
    for(int i=0;i<64;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3 != 0){
            result = setBit(result,i);
        }
    }

    return result;
}

int main(){
   

    int arr[] = {1,2,3,4,1,2,3,1,2,3};
    cout << unique(arr,10);
    
    
    return 0;
}