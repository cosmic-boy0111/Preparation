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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new ListNode(val); 
}

void display(ListNode* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);
vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

bool dfs( int i , int j ,   string word , vector<vector<char>>&grid  )
   {
       int k = 0 ;
       int col = j;
       int row = i ;
       // Horizontal right 
       while( col < grid[0].size() && k < word.size() )
       {
           if( word[k] != grid[i][col]) break ;
           col++ ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
       k = 0 ;
       col = j;
       
       // Horizontal left 
       while( col >= 0  && k < word.size() )
       {
           if( word[k] != grid[i][col]) break ;
           col-- ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
      k = 0 ;
      row = i ;
       
       // Vertical  Up 
       while( row < grid.size() && k < word.size() )
       {
           if( word[k] != grid[row][j]) break ;
           row++ ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
       k = 0 ;
       row = i ;
       
       // vertical Down  
       while( row >= 0  && k < word.size() )
       {
           if( word[k] != grid[row][j]) break ;
           row-- ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
       
        k = 0   ;
        col = j ;
        row = i ;
       
       // Top right  
       while( col < grid[0].size() && row < grid.size() && k < word.size() )
       {
           if( word[k] != grid[row][col]) break ;
           col++ ;
           row++ ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
        k = 0   ;
        col = j ;
        row = i ;
       
       // Top Left 
       while( col >= 0 && row < grid.size() && k < word.size() )
       {
           if( word[k] != grid[row][col]) break ;
           col-- ;
           row++ ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
        k = 0   ;
        col = j ;
        row = i ;
       
       // Bottom right 
       while( col < grid[0].size() && row >= 0  && k < word.size() )
       {
           if( word[k] != grid[row][col]) break ;
           col++ ;
           row-- ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
       
       // Bottom left  
         k = 0   ;
        col = j ;
        row = i ;
       
      
       while( col >= 0 && row >= 0  && k < word.size() )
       {
           if( word[k] != grid[row][col]) break ;
           col-- ;
           row-- ;
           k++ ;
       }
       if( k == word.size()) return true ;
       
       return false ;
       
       
   }
vector<vector<int>>searchWord(vector<vector<char>>board , string word){
    // Code here
    
    int row = board.size() ;
    int col = board[0].size() ; 
    
    vector<vector<int>>ans ;
    
    for( int i = 0 ; i  < row ; i++ )
    {
        for( int j = 0 ; j < col ; j++ )
        {
            if( board[i][j] == word[0] )
            {
                   if( dfs( i , j ,  word , board  )  )
                {
                    
                       ans.push_back({ i , j }) ;
                }
                
            }
        }
    }
    
    
    
    return ans ;
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}