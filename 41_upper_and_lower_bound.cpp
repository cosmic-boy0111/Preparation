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


int lower_bound(vector<int> &v,int ele){
    int lo = 0, hi = v.size()-1;
    int mid ;
    while (hi-lo>1)
    {
        mid = (hi+lo)/2;
        if(v[mid]<ele){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }

    if(v[lo]>=ele){
        return lo;
    }else if(v[hi]>=ele){
        return hi;
    }

    return -1;
    
}

int upper_bound(vector<int> &v,int ele){
    int lo = 0, hi = v.size()-1;
    int mid ;
    while (hi-lo>1)
    {
        // cout << lo << " "<< hi << endl;
        mid = (hi+lo)/2;
        // cout << mid << endl;
        if(v[mid]<=ele){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }

    if(v[lo]>ele){
        return lo;
    }else if(v[hi]>ele){
        return hi;
    }

    return -1;
    
}


int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    inc(i,0,n){
        cin >> v[i];
    }

    int ele;
    cin >> ele;

    cout << (lower_bound(v,ele)==-1?-1:v[lower_bound(v,ele)]) << endl;
    cout << (upper_bound(v,ele)==-1?-1:v[upper_bound(v,ele)]) << endl;
    
    
    return 0;
}