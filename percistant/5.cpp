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

int calBusses(vector<pair<int,int>> stations,int n){
    sort(stations.begin(),stations.end());
    if(n==1){
        return 1;
    }

    pair<int,int> station1 = stations[0];
    int answer = 1;  

    for(int i=1;i<n;i++){
        if(
            (stations[i].first >= station1.first and stations[i].first <= station1.second) || 
            (stations[i].second >= station1.first and stations[i].second <= station1.second)
        ){
            station1.first = min(station1.first,stations[i].first);
            station1.second = max(station1.second,stations[i].second);
        }else{
            answer++;
            station1 = stations[i];
        }
    }
    

    return answer;
}

int32_t main(){
   
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> stations;


    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        stations.push_back({x,y});
    }

    cout << calBusses(stations,n);


    
    
    return 0;
}