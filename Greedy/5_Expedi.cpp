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



int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vpi v(n);
        for(auto &x:v)
            cin >> x.first >> x.second;
        int l,p;
        cin >> l >> p;

        for(int i=0;i<n;i++){
            v[i].first = l - v[i].first;
        }

        sort(v.begin(),v.end());
        int ans = 0;
        int curr = p;

        maxHeapInt hp;
        bool flage = 0;
        for(auto &x:v){
            if(curr >= l)
                break;
            while (curr < x.first){
                if(hp.empty()){
                    flage = 1;
                    break;
                }
                ans ++;
                curr += hp.top();
                hp.pop();
            }
            if(flage)
                break;
            
            hp.push(x.second);
            
        }

        if(flage){
            cout << -1 << endl;
            continue;
        }

        while (!hp.empty() and curr < l){
            curr += hp.top();
            hp.pop();
            ans ++;
        }

        if(curr < l){
            cout << -1 << endl;
            continue;
        }

        cout << ans << endl;


        
        
    }
    
    return 0;
}