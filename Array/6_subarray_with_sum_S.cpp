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


int main(){
    
    int n,s;
    cin >> n >> s;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }


    int start = -1 , end = -1;
    int i = 0, j = 0;
    int curr_sum = 0;

    while (j < n and curr_sum+a[j] <= s)
    {
        curr_sum += a[j];
        j++;
    }

    if(curr_sum == s){
        cout << i+1 << " " << j << endl;
        return 0;
    }

    while ( j < n )
    {
        curr_sum += a[j];
        while ( curr_sum > s)
        {
            curr_sum -= a[i];
            i++;
        }

        if(curr_sum == s){
            start = i+1;
            end = j+1;
            break;
        }

        j++;
        

    }

    cout << start << " " << end << endl;
    
    return 0;
}