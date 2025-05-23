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
bool vis[N];

int mah(vector<int>& arr){
    int n = arr.size();
    vector<int> previousMini;
    stack<int> st;

    for(int i=0; i<n; i++){
        if(st.empty()){
            previousMini.push_back(-1);
            st.push(i);
            continue;
        }

        while ( !st.empty() && arr[st.top()] >= arr[i] ){
            st.pop();
        }

        if(st.empty()){
            previousMini.push_back(-1);
        }else{
            previousMini.push_back(st.top());
        }
        
        st.push(i);
    }

    vector<int> nextMini;
    while (!st.empty()){
        st.pop();
    }

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            nextMini.push_back(n);
            st.push(i);
            continue;
        }

        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(st.empty()){
            nextMini.push_back(n);
        }else{
            nextMini.push_back(st.top());
        }

        st.push(i);
    }
    
    reverse(nextMini.begin(), nextMini.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, (nextMini[i] - previousMini[i] - 1)*arr[i]);
    }

    return ans;
}

int32_t main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;

    for(int i=0; i<n; i++){
        vector<int> temp(m);
        for(auto& x : temp){
            cin >> x;
        }
        v.push_back(temp);
    }
    // my solution


    // for(int i = n-1; i>=0; i--){
    //     int total = 0;
    //     for(int j = m-1; j>=0; j--){
    //         if(v[i][j] == 0){
    //             total = 0;
    //             continue;
    //         }
    //         total += 1;
    //         v[i][j] = total;
    //     }
    // }

    // for(auto& x : v){
    //     for(auto& y : x){
    //         cout << y << " ";
    //     }cout << endl;
    // }

    // int ans = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(v[i][j] == 0) continue;
    //         int countRow = 1;
    //         for(int k=i+1;k<n;k++){
    //             if(v[k][j] >= v[i][j]) countRow++;
    //             else break;
    //         }
    //         for(int k=i-1;k>=0;k--){
    //             if(v[k][j] >= v[i][j]) countRow++;
    //             else break;
    //         }
    //         ans = max(ans, v[i][j]*countRow);
    //     }
    // }

    // cout << ans << endl;

    vector<int> temp;
    for(int i = 0; i<m; i++){
        temp.push_back(v[0][i]);
    }

    int ans = mah(temp);

    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] == 0){
                temp[j] = 0;
            }else{
                temp[j] += v[i][j];
            }
        }

        ans = max(ans, mah(temp));
    }

    cout << ans << endl;

}