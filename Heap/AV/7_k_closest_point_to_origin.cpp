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
    vpi v;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    priority_queue<pair<int,pi>,vector<pair<int,pi>>> max_hp;

    for(auto &p:v){
        max_hp.push({(p.first*p.first + p.second*p.second),p});
        if(max_hp.size() > k)
            max_hp.pop();
    }

    while (!max_hp.empty()){
        auto t = max_hp.top().second;
        cout << t.first << " " << t.second << endl;
        max_hp.pop();
    }
    


    
    
    return 0;
}