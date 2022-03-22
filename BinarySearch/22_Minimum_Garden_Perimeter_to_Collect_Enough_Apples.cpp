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


long long binExpIter(int a,long long b){
    long long ans = 1;
    while (b){
        if(b&1){
            ans = (ans*1LL*a);
        }
        a = (a*1LL*a);

        b>>=1;
    }

    return ans;
    
}


long long minimumPerimeter(long long neededApples) {
    
    long long x=0,curr=0;
        while(curr<neededApples){
            x++;
            curr+=12*x*x;
        }
    return x*8;

}

int main(){
    
    long long n = 1000000000;
    cout << minimumPerimeter(n);
    
    return 0;
}