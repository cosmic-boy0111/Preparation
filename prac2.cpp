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


class Search{
    public:
        int x;
        int n;
        int arr[100000];

        Search(){
            cout << "enter size : " ;
            cin >> n;
            cout << "enter elements : ";
            for(int i=0;i<n;i++){
                cin >> arr[i];
            }
            cout << "enter ele to search : ";
            cin >> x;

        };

        bool findEle(){
            for(int i=0;i<n;i++){
                if(arr[i]==x){
                    return true;
                }
            }

            return false;
        }
};



int main(){
    
    Search st;

    cout << st.findEle() << endl;

    
    return 0;
}