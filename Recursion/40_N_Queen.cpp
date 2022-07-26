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


bool isSafe(int** arr,int x,int y,int n){

    for(int row = 0; row<x ;row++){
        if(arr[row][y] == 1){
            return false;
        }
    }

    int row = x, col = y;

    while (row >= 0 and col >=0){
        if(arr[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;

    while (row >= 0 and col < n){
        if(arr[row][col] == 1){
            return false;
        }
        row--;
        col++;
    }

    return true;

}

vector<vector<string>> ans;
bool nQueen(int** arr,int x,int n){
    if(x >= n){
        vector<string> st;
        for (int i=0; i<n; i++){ 
            string s = "";
            for(int j=0;j<n;j++){
                if(arr[i][j] == 0) s.push_back('.');
                else s.push_back('Q');
            }
            st.push_back(s);
        }
        ans.push_back(st);
        // return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;
            if(nQueen(arr,x+1,n)){
                return true;
            }

            arr[x][col] = 0;
        }
    }

    return false;
}

int main(){
    

    int n;
    cin >> n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }

    bool t = nQueen(arr,0,n);

    
    for(auto &x : ans){
        for(auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    
    
    
    return 0;
}