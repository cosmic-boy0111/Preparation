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


class ListNode{
    public:
        int data;
        ListNode* next;

        ListNode(int val){
            data = val;
            next = NULL;
        }
};


bool isPalindrome(ListNode* head) {
    vector<int> v;
    while (head!=NULL)
    {
        v.push_back(head->data);
        head = head->next;
    }

    for(int i=0;i<v.size()/2;i++){
        if(v[i] != v[v.size()-i-1]){
            return false;
        }
    }

    return true;
    
}


int main(){
    
    ListNode* root = new ListNode(1);
    root->next = new ListNode(0);
    root->next->next = new ListNode(0);
    // root->next->next->next = new ListNode(2);


    cout << isPalindrome(root);

    
    return 0;
}