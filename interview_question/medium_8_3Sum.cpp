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

vector<int> adj[N];
vector<bool> visited(N,false);


int checkVal(int num,vector<int> &check){
    for(int i=0;i<check.size();i++){
        if(check[i] == num)
            return i;
    }

    return -1;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> check;
    vector<int> used;
    for(auto x: nums){
        check.push_back(x);
    }
    for(int i=0;i<nums.size();i++){
        used.push_back(1);
    }
    map<pair<int,int>,int> mp;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            // cout << i << " " << j << endl;
            mp[{i,j}] = nums[i] + nums[j];

            // cout << mp[{i,j}] << endl;
        }
    }

    map<string,int> vecMap;

    

    for(auto &pr : mp){
        int temp = -1 * pr.second;
        int idx = checkVal(temp,check);
        if(idx != -1){
            vector<int> temp = {pr.first.first, pr.first.second,idx};
            sort(temp.begin(),temp.end());
            string s = "";
            s.append(to_string(s[0]));
            s.push_back(' ');
            s.append(to_string(s[1]));
            s.push_back(' ');
            s.append(to_string(s[2]));
            if(pr.first.first != idx and pr.first.second != idx and used[idx] and vecMap.find(s) == vecMap.end()){
                
                vecMap[s] = 1;
                ans.push_back({ nums[ pr.first.first ] , nums [pr.first.second ] , nums [idx]});
                used[idx] = 0;
            }
        }

    }



    return ans;
}


int32_t main(){

    int n;
    cin >> n;    
    vector<int> v(n);

    for(auto &i : v){
        cin >> i;
    }

    for(auto & x : threeSum(v)){
        for(auto & y : x){
            cout << y << " ";
        }cout << endl;
    }

    
    
    return 0;
}