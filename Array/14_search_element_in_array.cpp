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


int main(){
   
    int n,m;
    cin >> n >> m;
    int target;
    cin >> target;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    bool found = false;
    int r = 0, c = m-1;
    while (r < n and c >= 0){
        if(mat[r][c] == target){
            found = true;
            break;
        }else if(target < mat[r][c]){
            c--;
        }else{
            r++;
        }
    }
    
    cout << found << endl;
    
    return 0;
}