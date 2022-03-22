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
        int val;
        ListNode* next;

        ListNode(int data){
            val = data;
            next = NULL;
        }

};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if(!l1 || !l2)
            return !l1 ? l2 : l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    

}


int main(){
    
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    // l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* sorted = mergeTwoLists(l1,l2);

    while (sorted != NULL)
    {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }
    

    
    
    return 0;
}