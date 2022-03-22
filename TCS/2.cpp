#include <bits/stdc++.h>
using namespace std;



int main(){
    
    int n;
    cin >> n;
    int arr[n] ;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int k ;
    cin >> k;
    int c = 1;
    int initial = k-1;
    for(int j=k;j<n;j++){
        if(arr[j] > arr[initial]){
            c++;
            initial = j;
        }else{
            break;
        }
    }

    cout << c << endl;
    
    return 0;
}