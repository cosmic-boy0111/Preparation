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

vector<vector<int>> checkMaxStackPrise(vector<int> A,int n){
    vector<vector<int>> ans;
    stack<pair<int,int>> st;
    for(int i=n-1;i>=0;i--){
        if(!st.empty() and st.top().second <= A[i]){
            pair<int,int> temp = st.top();
            st.pop();
            while (!st.empty() and st.size() > 1){
                st.pop();
            }
            if(!st.empty()){
                pair<int,int> temp2 = st.top();
                st.pop();

                ans.push_back({temp.first, temp2.first});
            }
            
        }
        st.push({i,A[i]});
    }

    if(!st.empty()){
        pair<int,int> temp = st.top();
        st.pop();
        while (!st.empty() and st.size() > 1){
            st.pop();
        }
        if(!st.empty()){
            pair<int,int> temp2 = st.top();
            st.pop();

            ans.push_back({temp.first, temp2.first});
        }

    }


    return ans;
}


vector<vector<int>> checkMaxStackPrise2(vector<int> A,int n){
    vector<vector<int>> ans;
    int i =0;
    while(i<n){
        int first = A[i];
        // pair<int,int> maxVal = {i,A[i]}; // {0,100}
        int pos = i;
        int val = A[i];

        int pre = i;

        int j = i+1 ;

        for(j;j<n;j++){
            if(A[j] >= val){
                pos = j;
                val = A[j];
            }else{
                i = j;
                break;
            }
        }

        if(pre != pos){
            ans.push_back({pre,pos});
        }

        if(j==n){
            break;
        }

    }

    return ans;
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> stockPrise(n);
    for(auto &x:stockPrise){
        cin >> x;
    }

    for(auto x: checkMaxStackPrise2(stockPrise,n))
        cout << x[0] << " " << x[1] << endl;

    
    return 0;
}