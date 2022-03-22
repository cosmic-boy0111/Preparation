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

vector<vector<int>> ans;
set<vector<int>> ans2;

void permute(vector<int> &a,int idx){
    if(idx == a.size()){
        ans2.insert(a);
        ans.push_back(a);
    }

    for(int i=idx; i<a.size(); i++){
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }
}

int main(){
    

    int n;
    cin >> n;

    vector<int> a(n);
    inc(i,0,n){
        cin >> a[i];
    }

    permute(a,0);
    // sort(a.begin(),a.end());
    // do{
    //     ans.push_back(a);
    // } while (next_permutation(a.begin(),a.end()));
    

    for(auto x:ans){
        for(auto y:x){
            cout << y << " ";
        }cout << endl;
    }

    cout << "----------------" << endl;

    for(auto x:ans2){
        for(auto y:x){
            cout << y << " ";
        }cout << endl;
    }

    
    
    return 0;
}