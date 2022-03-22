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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


void helper(int r,int c,vector<vector<char>> &a,map<pi,mi> &mp,vector<mi> &row,vector<mi> &cal){
    if(r == 9){
        each(x,a){
            each(t,x){
                cout << t << " ";
            }cout << endl;
        }cout << endl;
        return;
    }

    if(c==9){
        helper(r+1,0,a,mp,row,cal);
        return;
    }

    if(a[r][c] != '.'){
        helper(r,c+1,a,mp,row,cal);
        return;
    }

    inc(i,1,10){
        if(!mp[{r/3,c/3}][i] and !row[r][i] and !cal[c][i]){
            mp[{r/3,c/3}][i] = 1;
            row[r][i] = 1;
            cal[c][i] = 1;
            a[r][c] = i + '0';
            helper(r,c+1,a,mp,row,cal);
            mp[{r/3,c/3}][i] = 0;
            row[r][i] = 0;
            cal[c][i] = 0;
            a[r][c] = '.';
        }
    }

}

void solveSodoku(vector<vector<char>> &a){
    map<pair<int,int>,map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    inc(i,0,9){
        inc(j,0,9){
            if(a[i][j]!='.'){
                mp[{i/3,j/3}][a[i][j]-'0'] = 1;
                row[i][a[i][j]-'0'] = 1;
                col[j][a[i][j]-'0'] = 1;
            }
        }
    }

    helper(0,0,a,mp,row,col);
}

int main(){

    vector<vector<char>> soduko = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    solveSodoku(soduko);
    
    
    return 0;
}