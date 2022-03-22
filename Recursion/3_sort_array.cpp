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


void insert(vector<int> &v,int val){
    if(v.size()==0 || v[v.size()-1] <= val){
        v.push_back(val);
        return;
    }

    int temp = v[v.size()-1];
    v.pop_back();
    insert(v,val);
    v.push_back(temp);
}


void sort(vector<int> &v){

    if(v.size()==1){
        return;
    }

    int val = v[v.size()-1];
    v.pop_back();
    sort(v);

    insert(v,val);

}


int main(){
    
    vector<int> v = {3,1,4,5,0};
    sort(v);

    for(auto &x:v){
        cout << x << " ";
    }
    
    return 0;
}