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


vector<int> maxAllSubarray(int arr[],int n,int k){
    vector<int> ans;
    deque<int> list;
    for(int i=0;i<k;i++){
        while (!list.empty() and arr[i] > list.back()){
            list.pop_back();
        }
        list.push_back(arr[i]);
    }

    ans.push_back(list.front());
    for(int i=k;i<n;i++){
        if(list.front() == arr[i-k])
            list.pop_front();
        while (!list.empty() and arr[i] > list.back()){
            list.pop_back();
        }
        list.push_back(arr[i]);
        ans.push_back(list.front());
    }

    return ans;

}


int32_t main(){
    
    int n,k;
    cin >> n >>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> ans = maxAllSubarray(arr,n,k);
    for(auto &x:ans)
        cout << x << " ";
    
    return 0;
}