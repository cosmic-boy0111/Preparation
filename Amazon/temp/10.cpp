#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> v,int n,int k){
    vector<int> temp = v;
    for(int i=0;i<k-1;i++){
        temp.push_back(v[i]);
    }
    for(auto &x: temp) {
        cout << x << " ";
    }cout << endl;
    int sum = 0;
    for(int i =0 ;i<k;i++){
        sum += temp[i];
    }
    int ans = sum;
    cout << sum << endl;
    cout << temp[n-1] << endl;
    for(int i=k;i<temp.size();i++){
        sum = sum + temp[i] - temp[i-k];
        
        ans = max(ans,sum);
    }

    return ans;
}


int main(){
    
    
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto &x : v) cin >> x;


    cout << findMax(v,n,k);


    return 0;
}