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

int max_upper(vector<int> &v,int n){
    
    int lo = 0;
    int ans = -1;
    int hi = v.size()-1;
    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]<=n){
            ans = v[mid];
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }

    return ans;
    
}

int min_upper(vector<int> &v,int n){
    
    int lo = 0;
    int ans = -1;
    int hi = v.size()-1;
    while (lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]>=n){
            ans = v[mid];
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }

    return ans;
    
}

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int,int> mp; 
    vector<int> index;
    bool pre = false;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*' &&  pre){
            cnt++;
        }
        if(s[i]=='|' and pre==false){
            mp[i] = cnt;
            pre = true;
        }
        if(s[i]=='|' and pre){
            mp[i] += cnt;
            pre = true;
        }
    }
    for(auto &x:mp){
        index.push_back(x.first);
    }cout << endl;

    sort(index.begin(),index.end());



    for(auto &x:queries){
        int left = min_upper(index,x[0]);
        int right = max_upper(index,x[1]);

        if(left == -1 || right==-1){
            ans.push_back(0);
            continue;
        }
        if(mp[right] - mp[left] < 0)
            ans.push_back(0);
        else
            ans.push_back(mp[right] - mp[left]);

    }

    return ans;



}

int main(){
    
    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};

    vector<int> v = platesBetweenCandles(s,queries);

    each(x,v){
        cout << x << " ";
    }
    
    return 0;
}