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


bool ans;
void calculateScore(vector<int> nums,int i,int j,int player1,int player2,bool turn){

    if((i > j) || (j < i)){
        cout << player1 << " " << player2 << endl;
        if(player1 >= player2){
            ans = true;
        }else{
            ans = false;
        }
        return;
    }

    if(turn){
        if(nums[i] > nums[j]){
            calculateScore(nums,i+1,j,player1+nums[i],player2,false);
        }else{
            calculateScore(nums,i,j-1,player1+nums[j],player2,false);
        }
    }else{
        if(nums[i] > nums[j]){
            calculateScore(nums,i+1,j,player1,player2+nums[i],true);
        }else{
            calculateScore(nums,i,j-1,player1,player2+nums[j],true);
        }
    }

}

bool PredictTheWinner(vector<int>& nums) {
    calculateScore(nums,0,nums.size()-1,0,0,true);
    return !ans;
}

int main(){
    
    vector<int> v = {1,5,233,7};

    cout << PredictTheWinner(v) << endl;
    
    
    return 0;
}