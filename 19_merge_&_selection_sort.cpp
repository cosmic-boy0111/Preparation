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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;

int arr[N];
// 1 2 3 4 5
void merge(int l,int r,int mid){
    int l_sz = mid - l + 1;
    int L[l_sz + 1];
    int r_sz = r - mid;
    int R[r_sz + 1];

    for(int i=0;i<l_sz;i++){
        L[i] = arr[l+i];
    }
    for(int i=0;i<r_sz;i++){
        R[i] = arr[mid + i + 1];
    }

    L[l_sz] = R[r_sz] = INT_MAX;

    int l_i = 0;
    int r_i = 0;
    for(int i=l;i<=r;i++){
        if(L[l_i] <= R[r_i]){
            arr[i] = L[l_i];
            l_i++;
        }else{
            arr[i] = R[r_i];
            r_i++;
        }
    }
}


void mergeSort(int l,int r){

    if(l==r) return;

    int mid = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);

    merge(l,r,mid);
}


int main(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

/////////////////// selection sort ///////////////
    // for(int i=0;i<n;i++){
    //     int minIndex = i;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]<arr[minIndex]){
    //             minIndex = j;
    //         }
    //     }

    //     swap(arr[i],arr[minIndex]);
    // }

    mergeSort(0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    
    return 0;
}