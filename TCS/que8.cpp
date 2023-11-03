#include <bits/stdc++.h>
using namespace std;


int solve(int N, int K){
    int totalCandles = N;
    int extraCandles = 0;

    while (N >= K) {
        int newCandles = N / K;
        extraCandles += newCandles;
        N = N % K + newCandles;
    }

    return totalCandles + extraCandles;
}

int main(){

    int N , K;
    cin >> N >> K;

    cout << solve(N, K) << endl;

}