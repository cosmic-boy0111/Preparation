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

bool isSafe(int i,int j,int n,int m,vector<vector<int>>& mat){
    if(i-1>=0 and mat[i][j] < mat[i-1][j]){
        return false;
    }
    if(i+1<n and mat[i][j] < mat[i+1][j]){
        return false;
    }

    if(j-1 >= 0 and mat[i][j] < mat[i][j-1]){
        return false;
    }
    if(j+1 < m  and mat[i][j] < mat[i][j+1]){
        return false;
    }

    return true;
}

vector<int> next(int i,int j,int n,int m,vector<vector<int>>& mat){
    if(i-1>=0 and mat[i][j] < mat[i-1][j]){
        return {i-1,j};
    }
    if(i+1<n and mat[i][j] < mat[i+1][j]){
        return {i+1,j};
    }

    if(j-1 >= 0 and mat[i][j] < mat[i][j-1]){
        return {i,j-1};
    }
    if(j+1 < m  and mat[i][j] < mat[i][j+1]){
        return {i,j+1};
    }

    return {i,j};
}

vector<int> ans(int i,int j,int n,int m,vector<vector<int>>& mat){
    if(isSafe(i,j,n,m,mat)){
        return {i,j};
    }

    vector<int> nt = next(i,j,n,m,mat);

    vector<int> result =  ans(nt[0],nt[1],n,m,mat);

    return result;

}

vector<int> findPeakGrid(vector<vector<int>>& mat) {    
    int n = mat.size();
    int m = mat[0].size();
    return ans(0,0,n,m,mat);
}


int main(){
    

    vector<vector<int>> v = {{10}};

    vector<int> ans = findPeakGrid(v);

    cout << ans[0] << " " << ans[1] << endl;
    
    
    return 0;
}