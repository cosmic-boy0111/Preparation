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

class CustomFunction{
    public:
        int f(int x,int y){
            return x*y;
        }
};

vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

    vector<vector<int>> res;
    for(int i=1;i<=z/2;i++){
        int s=1,e=z;
        while (s<=e){
            int m = s + (e-s)/2;
            if(customfunction.f(i,m) == z){
                res.push_back({i,m});
                res.push_back({m,i});

                e = m-1;
            }else if(customfunction.f(i,m) > z){
                e = m-1;
            }else{
                s = m+1;
            }
        }
        
    }

    return res;
        
}


int main(){
    
    CustomFunction customfunction;

    vector<vector<int>> res = findSolution(customfunction,5);
    for(auto x:res){
        cout << x[0] << " " << x[1] << endl;
    }
    
    return 0;
}