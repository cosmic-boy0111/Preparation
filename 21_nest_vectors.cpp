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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;


void printVec(vector<int> &v){
    cout << "size : " << v.size() << endl;
    for(int i=0;i<v.size();i++){
        // cout << v[i].first << " " << v[i].second << endl;
        cout << v[i] << " ";
    }cout << endl;
}


int main(){
    

    // vector<pair<int,int>> v;

    // int n;
    // cin >> n;
    // for(int i=0;i<n;i++){
    //     int x,y;
    //     cin >> x >> y;
    //     v.push_back({x,y});
    // }
    
    // printVec(v);

    // int n;
    // cin >> n;
    // vector<int> v[n];

    // for(int j=0;j<n;j++)
    // {
    //     int t;
    //     cin >> t;
    //     for(int i=0;i<t;i++){
    //         int x;
    //         cin >> x;
    //         v[j].push_back(x);
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     printVec(v[i]);
    // }
    
    int n;
    cin >> n;
    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        vector<int> temp;
        // v.push_back(vector<int> ());
        for(int j=0;j<t;j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }

        v.push_back(temp);
    }

     for(int i=0;i<v.size();i++){
        printVec(v[i]);
    }
    
    return 0;
}