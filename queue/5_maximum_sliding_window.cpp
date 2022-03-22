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



int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    deque<int> q;
    vector<int> ans;

    for(int i=0;i<k;i++){
        while (!q.empty() and v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i);  
    }

    ans.push_back(v[q.front()]);
    for(int i=k;i<n;i++){
        if(q.front() == i-k){
            q.pop_front();
        }

        while (!q.empty() and v[q.back()] < v[i]){
            q.pop_back();
        }
        q.push_back(i); 

        ans.push_back(v[q.front()]);
        
    }

    for(auto &x:ans){
        cout << x << " ";
    }

    

    return 0;
}