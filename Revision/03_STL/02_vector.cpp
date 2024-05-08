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


void printVec ( vector<int>& v ) {
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }cout << endl;

}

void printVec ( vector<string>& v ) {
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }cout << endl;

}

void printVec ( vector<pair<int,int>>& v ) {

    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

}

int32_t main(){

    // vector<int> v;

    // int n;
    // cin >> n;


    // for(int i = 0; i < n; i++){
    //     int x;
    //     cin >> x;
    //     v.push_back(x); // O(1) 
    // }
    
    // printVec(v);

    // vector<int> v1(5,3);
    // v1.push_back(6);

    // printVec(v1);

    // v1.pop_back();
    // printVec(v1); // O(1);

    // vector<int> v2 = v1; // O(n);
    // v2.push_back(7);
    // printVec(v2);


    // vector<string> v_string;
    // int n1;
    // cin >> n1;

    // for(int i = 0; i < n1; i++){
    //     string x;
    //     cin >> x;
    //     v_string.push_back(x);
    // }


    // printVec(v_string);

    // // vector<pair<int,int>> v_pair = {
    // //     {1, 2},
    // //     {2, 3},
    // //     {3, 5}
    // // };

    // vector<pair<int,int>> v_pair;
    // int n2;
    // cin >> n2;

    // for(int i = 0; i < n2; i++){
    //     int x, y;
    //     cin >> x >> y;
    //     v_pair.push_back(make_pair(x,y));
    // }


    // printVec(v_pair);

    // int N;
    // cin >> N;

    // vector<int> arr_vec[N];

    // for(int i = 0; i < N; i++){
    //     int n;
    //     cin >> n;
    //     for(int j = 0; j < n; j++){
    //         int x;
    //         cin >> x;
    //         arr_vec[i].push_back(x);
    //     }cout << endl;
    // }

    // cout << N << endl;

    // for( int i = 0; i < N; i++){
    //     printVec(arr_vec[i]);
    // }

    int N;
    cin >> N;

    vector<vector<int>> v;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        vector<int> temp;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }

        v.push_back(temp);
    }

    for(int i = 0; i < N; i++){
        printVec(v[i]);
    }


}