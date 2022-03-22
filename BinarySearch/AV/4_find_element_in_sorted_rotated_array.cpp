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


int minElementIndex(vector<int> v) {
    int n = v.size();
    int lo = 0 , hi = n-1;
    int ans = -1;
    if(v[0] <= v[v.size()-1])
        return 0;
    while (lo <= hi){

        int mid = lo + (hi-lo)/2;
        int next = (mid + 1) %n;
        int pre = (mid + n - 1) % n;
        if(v[mid] <= v[next] and v[mid]<= v[pre]){
            ans = mid;
            break;
        }

        if(v[lo] <= v[mid]){
            if(lo == mid)
                lo = mid+1;
            else
                lo = mid;
        }else if(v[mid] <= v[hi]){
            if(hi == mid)
                hi = mid-1;
            else
                hi = mid;
        }

    }

    return ans;
}

int findElement(vector<int> v,int start,int end,int ele){
    while (start <= end){
        int mid = start + (end-start)/2;
        if(ele == v[mid]){
            return mid;
        }

        if(v[mid] < ele){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }   

    return -1;
    
}

int main(){

    int n,k;
    cin >> n >>k;
    vector<int> v(n);
    for(auto &i:v)
        cin >> i;

    int index = minElementIndex(v);


    int E1 = findElement(v,0,index-1,k);
    int E2 = findElement(v,index,n-1,k);

    if(E1 == E2){
        cout << -1 << endl;
    }else if(E1 == -1){
        cout << E2 << endl;
    }else{
        cout << E1 << endl;
    }


    return 0;
}