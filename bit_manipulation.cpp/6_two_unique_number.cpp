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


bool setBt(int n,int pos){
    return (n & (1<<pos));
}

void unique(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum ^= arr[i];
    }

    int tempXor = sum;
    int setBit=0;
    int pos = 0;
    while (setBit != 1)
    {
        setBit = sum & 1;
        pos++;
        sum = sum >> 1;
    }

    int newXor = 0;

    for(int i=0;i<n;i++){
        if(setBt(arr[i],pos-1)){
            newXor ^=arr[i];
        }
    }

    cout << newXor << endl;
    cout << (newXor^tempXor) << endl;

}

int main(){
    
    int arr[] = {1,2,3,1,2,3,5,7};
    unique(arr,8);
    
    return 0;
}