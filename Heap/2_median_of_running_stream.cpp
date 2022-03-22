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

priority_queue<int,vector<int>,greater<int>>  pqmin;
priority_queue<int,vector<int>> pqmax;

void insert(int x){
    if(pqmin.size() == pqmax.size()){
        cout << "hello" << endl;
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }

        if(x < pqmax.top()){
            pqmax.push(x);
        }else{
            pqmin.push(x);
        }
    }else{
        cout << "hello2" << endl;
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top())
                pqmin.push(x);
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmax.push(x);
                pqmin.push(temp);
            }
        }else{
            if(x <= pqmin.top())
                pqmax.push(x);
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            } 

        }
    }
}

double findMedian(){
    if(pqmin.size() == pqmax.size())
        return (pqmin.top() + pqmax.top())/2.0;
    if(pqmax.size() > pqmin.top())
        return pqmax.top();
    return pqmin.top();
}

int32_t main(){
    

    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    
    return 0;
}