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

int knapsack(int value[],int wt[],int n,int W){



    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1] > W){
        return knapsack(value,wt,n-1,W);
    }

    return max(knapsack(value,wt,n-1,W-wt[n-1]) + value[n-1],
                knapsack(value,wt,n-1,W));



}

int main(){
    
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;

    cout << knapsack(value,wt,3,W);

    
    return 0;
}