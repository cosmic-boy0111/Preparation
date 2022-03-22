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

int mah(vector<int> v){
    stack<int> st;
    vector<int> right;
    for(int i=v.size()-1;i>=0;i--){
        while (!st.empty() and v[st.top()] >= v[i]){
            st.pop();
        }

        if(st.empty()){
            right.push_back(v.size());
        }else{
            right.push_back(st.top());
        }

        st.push(i);
    }

    while (!st.empty()){
        st.pop();
    }

    reverse(right.begin(),right.end());
    vector<int> left;
    for(int i=0;i<v.size();i++){
        while (!st.empty() and v[st.top()] >= v[i]){
            st.pop();
        }

        if(st.empty()){
            left.push_back(-1);
        }else{
            left.push_back(st.top());
        }

        st.push(i);
    }

    int ans = 0;
    for(int i=0;i<v.size();i++){
        ans = max(ans,(right[i]-left[i]-1)*v[i]);
    }

    return ans;

}

int main(){
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp(m);
        for(auto &x:temp)
            cin >> x;
        v.push_back(temp);
    }

    
    int ans = 0;
    vector<int> temp(m);
    for(int j=0;j<m;j++){
        temp[j] = v[0][j];
    }

    ans = max(ans,mah(temp));
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 0)
                temp[j] = 0;
            else
                temp[j] += 1;
        }
        ans = max(ans,mah(temp));
    }

    cout << ans;


    return 0;
}