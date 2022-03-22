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

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int inc = 1;
    for(int i=n-1;i>=0;i--){
        digits[i] = digits[i]+inc;
        if(digits[i] > 9){
            digits[i] = 0;
        }else{

            return digits;
        }
    }

    digits.push_back(1);
    reverse(digits.begin(),digits.end()) ;
    return digits;
}

int main(){

    vector<int> t = {9};
    
    vector<int> v = plusOne(t);
    for(auto &x:v){
        cout << x << " ";
    }
    
    
    return 0;
}