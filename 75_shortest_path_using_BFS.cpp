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

const int INF = 1e9+10;

int vis[8][8] ;
int lev[8][8];

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1] - '1';
}

bool isValid(int x,int y){
    return x>=0 && y>=0 and x<8 and y<8;
}

vector<pi> movements = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};



int bfs(string s1,string s2){
    int sourceX = getX(s1);
    int sourceY = getY(s1);

    int destX = getX(s2);
    int destY = getY(s2);

    queue<pair<int,int>> q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY] = 1;
    lev[sourceX][sourceY] = 0;

    while (!q.empty()){
        pi v = q.front();
        q.pop();
        int x=v.first, y=v.second;
        for(auto movement: movements){
            int childX = movement.first + x;
            int childY = movement.second + y;
            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX,childY});
                lev[childX][childY] = lev[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
        if(lev[destX][destY] != INF){
            break;
        }
    }
    
    return lev[destX][destY];

}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            lev[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main(){
    

    int n;
    cin >> n;
    while (n--){
        reset();
        string s1,s2;
        cin >> s1 >> s2;
        cout << bfs(s1,s2) << endl;
    }
    

    
    return 0;
}