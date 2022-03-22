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
    
    if(x<n and y<n and arr[x][y]==1){
        return true;
    }

    return false;

}

bool ratInMaize(int** arr,int x,int y,int n,int** solArr){

    if((x==n-1) and (y==n-1)){
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        solArr[x][y] = 1;
        if(ratInMaize(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratInMaize(arr,x,y+1,n,solArr)){
            return true;
        }

        solArr[x][y] = 0;
        return false;
    }

    return false;

}


int main(){
   

    int n;
    cin >> n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }

    inc(i,0,n){
        inc(j,0,n){
            cin >> arr[i][j];
        }
    }

    int** solArr = new int*[n];
    for(int i=0;i<n;i++){
        solArr[i] = new int[n];
        for(int j=0;j<n;j++){
            solArr[i][j] = 0;
        }
    }

    

    if(ratInMaize(arr,0,0,n,solArr)){
        inc(i,0,n){
            inc(j,0,n){
                cout << solArr[i][j] << " ";
            }cout << endl;
        }
    }



    
    
    return 0;
}