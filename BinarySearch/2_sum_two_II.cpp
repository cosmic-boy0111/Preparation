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



vector<int> twoSum(vector<int>& numbers, int target) {

    int lo = 0, hi = numbers.size()-1;
    while (hi-lo>1)
    {
        if(numbers[hi]+numbers[lo] == target){
            return {lo+1,hi+1};
        }
        if(numbers[hi]+numbers[lo] > target){
            hi = hi-1;
        }else{
            lo = lo+1;
        }
    }

    return {lo+1,hi+1};
    
}

int main(){

        int n,t;
        cin >> n >> t;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }

        vector<int> temp = twoSum(v,t);
        cout << temp[0] << " "<< temp[1] << endl;
    
    
    
    return 0;
}