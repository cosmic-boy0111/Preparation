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

void computeNumber(vector<int> v,int k){
    pair<int,int> ans;
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += v[i];
    }

    bool found = false;
    if(sum % 3 == 0){
        ans = make_pair(0,k-1);
        found = true;
    }

    for(int i=k;i<v.size();i++){
        if(found){
            break;
        }

        sum = sum + v[i] - v[i-k];
        if(sum % 3 == 0){
            ans = make_pair(i-k+1,i);
            found = true;
        }
    }

    if(!found)
        cout << "No such Subarray exits" << endl;
    else{
        for(int i=ans.first; i<=ans.second;i++)
            cout << v[i] << " ";
    }
}

int main(){
    
    vector<int> v = {23,45,12,56,82};
    int k = 3;

    computeNumber(v,k);
    
    return 0;
}