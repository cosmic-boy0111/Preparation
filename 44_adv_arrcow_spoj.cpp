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

int n,cows;
int position[N];


bool canPlace(int minDist){

    int lastPos = -1;
    int cnt = cows;
    for(int i=0;i<n;i++){
        if(position[i] - lastPos >= minDist || lastPos == -1){
            cnt--;
            lastPos = position[i];
        }
        if(cnt==0) break;
    }

    return cnt==0;

}


int main(){
    
    int T;
    cin >>T;
    while (T--)
    {
        cin >> n >> cows;
        for(int i=0;i<n;i++){
            cin >> position[i];
        }

        sort(position,position+n);

        // t t t t t f f f f 
        int lo = 0, hi = 1e9, mid;
        while (hi-lo>1)
        {
            mid = (lo+hi)/2;
            if(canPlace(mid)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }

        if(canPlace(hi)){
            cout << hi << endl;
        }else{
            cout << lo << endl;
        }
        

    }
    
    
    
    return 0;
}