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



int main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x:v)
        cin >> x;

    vector<int> leftMax(n);
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(mx,v[i]);
        leftMax[i] = mx;
    }
    vector<int> rightMax(n);
    mx = INT_MIN;
    for(int i=n-1;i>=0;i--){
        mx = max(mx,v[i]);
        rightMax[i] = mx;
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans += (min(leftMax[i],rightMax[i]) - v[i]);
    }

    cout << ans;
    
    return 0;
}