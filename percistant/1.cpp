#include <bits/stdc++.h>
using namespace std;

int getMaxEnergy(vector<int> energy,int i,int j){

    if(j<i){
        return INT_MIN;
    }

    if(i == j) return energy[i];

    if(j==i+1) return energy[i]*energy[j];

    int ans = INT_MIN;

    for(int k=i+1;k<=j;k++){
        int st1 = getMaxEnergy(energy,i,k-1);
        int st2 = getMaxEnergy(energy,k,j);

        ans = max(ans,st1+st2);
    }

    return ans;

}

int32_t main(){
    

    int n;
    cin >> n;
    vector<int> v(n);

    for(auto &x:v){
        cin >> x;
    }

    cout << getMaxEnergy(v,0,n-1);
    
    return 0;
}