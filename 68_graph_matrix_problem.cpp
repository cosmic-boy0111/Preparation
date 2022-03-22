// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define vs vector<string>
// #define vb vector<bool>
// #define pi pair<int,int>
// #define mi map<int,int>
// #define umi unordered_map<int,int>
// #define qi queue<int>
// #define vpi vector<pi>
// #define vvi vector<vi>
// #define ff first
// #define ss second 
// #define inc(i,a,b) for(int i=a;i<b;i++)
// #define dec(i,a,b) for(int i=a;i>=b;i--)
// #define each(x,target) for(auto &x:target)
// const int N = 1e6, MOD = 1e9+7;



// void dfs(int i,int j,vector<vector<int>>& image,int initialCol,int newColor){
//     int n = image.size();
//     int m = image[0].size();
//     if(i<0 || j<0)
//         return;
//     if(i>=n || j>=m)
//         return;

//     if(image[i][j] != initialCol) return;

//     image[i][j] = newColor;
    

//     dfs(i-1,j,image,initialCol,newColor);
//     dfs(i+1,j,image,initialCol,newColor);
//     dfs(i,j-1,image,initialCol,newColor);
//     dfs(i,j+1,image,initialCol,newColor);

// }


// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//     if(image[sr][sc] != newColor)
//         dfs(sr,sc,image,image[sr][sc],newColor) ;
//     return image;
// }

// int main(){
    
//     return 0;
// }


// number is islands leetcode

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


void dfs(int i,int j,vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    if(i < 0 || j < 0) return;
    if(i >= n || j >= m) return;

    if(grid[i][j] == '0') return;

    grid[i][j] = '0';


    dfs(i-1,j,grid);
    dfs(i+1,j,grid);
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);
}


int numIslands(vector<vector<char>>& grid) {

    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '0') continue;
            dfs(i,j,grid);
            cnt++;
        }
    }

    return cnt;
        
}

int main(){
//     vector<vector<char>> grid = {
//   {'1','1','1','1','0'},
//   {'1','1','0','1','0'},
//   {'1','1','0','0','0'},
//   {'0','0','0','0','0'}
// };

    vector<vector<char>> grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
    };

    cout << numIslands(grid);
    
    
    
    return 0;
}