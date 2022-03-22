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

bool isPalindrom(int num){
    int temp = num, number = 0;
    while (temp > 0){
        number = number*10 + temp%10;
        temp = temp/10;
    }

    return num == number;
    
}

int findPalindromicSubarray(vector<int> arr,int k){
    int num = 0;
    for(int i=0;i<k;i++){
        num = num*10 + arr[i];
    }

    if(isPalindrom(num)){
        return 0;
    }

    for(int i=k;i<arr.size();i++){
        num = (num % int(pow(10,k-1)))*10 + arr[i];
        if(isPalindrom(num)){
            return i-k+1;
        }
    }

    return -1;
}

int32_t main(){
    

    vector<int> arr = {2,3,5,1,1,5};
    int k = 4;

    int ans = findPalindromicSubarray(arr,k) ;

    if(ans == -1)
        cout << "not exits" << endl;

    else{
        inc(i,ans,ans+k){
            cout << arr[i];
        }
    }

    
    return 0;
}