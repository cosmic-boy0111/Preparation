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


bool isValid(vector<int> &v,int k,int min){
    int students = 1, sum = 0;
    for(int i=0;i<v.size();i++){
        sum += v[i];
        if(sum > min){
            students ++;
            if(students > k)
                return false;
            sum = v[i];
        }
    }

    return true;
}

int main(){
    
    int n , k;
    cin >> n >> k;
    vector<int> v(n);
    int lo = INT_MAX;
    int hi = 0;
    for(auto &i:v){
        cin >> i;
        lo = min(lo,i);
        hi += i;
    }
    int ans = -1;
    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(isValid(v,k,mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    




    

    
    return 0;
}