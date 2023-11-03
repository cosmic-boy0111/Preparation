#include<bits/stdc++.h>

using namespace std;


vector<int> solve(int N, int X, vector<int> A) {
  vector<int> ans;

  for (int i = 0; i < A.size(); i++) {
    int snge = -1;

    int ngei = -1;
    for (int j = i + 1; j < N; j++) {
      if (A[i] + X <= A[j]) {
        ngei = j;
        break;
      }
    }

    if (ngei != -1) {
      for (int k = ngei + 1; k < N; k++) {
        if (A[i] + X <= A[k] && k > i) {
          snge = A[k];
          break;
        }
      }
    }

    ans.push_back(snge);
  }

  return ans;
}

int main(){

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(auto & x : v) {
        cin >> x;
    }

    vector<int> ans = solve(n,x,v);
    for(auto & x : ans){
        cout << x << " ";
    }


}