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

int arr[40][40];

vector<vector<int>> generate(int numRows) {
    arr[0][1] = 1;
    vector<vector<int>> ans;
    for(int i=1;i<=numRows;i++){
        vector<int> temp;
        for(int j=1;j<=i;j++){
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            temp.push_back(arr[i][j]);
        }
        ans.push_back(temp);
    }

    return ans;
}

int main(){
    

    int n = 5;

    vector<vector<int>> ans = generate(n);

    for(auto x:ans){
        for(auto y:x){
            cout << y << " ";
        }cout << endl;
    }
    
    
    
    return 0;
}