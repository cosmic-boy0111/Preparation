

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

vector<vector<int>> ans;
void generate(vector<int> &temp,int i,vector<int> &nums){

    if(i==nums.size()){
        ans.push_back(temp);
        return;
    }

    generate(temp,i+1,nums);

    temp.push_back(nums[i]);
    generate(temp,i+1,nums);
    temp.pop_back();

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;
    generate(temp,0,nums);
    return ans;
}


int main(){

    vector<int> nums = {1,2,3};

    vector<vector<int>> t = subsets(nums);
    for(auto &x:t){
        for(auto &y:x){
            cout << y << " ";
        }cout << endl;
    }

    
    
    return 0;
}