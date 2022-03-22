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




ListNode* removeElements(ListNode* head, int val) {

    if(head == NULL){
        return head;
    }

    if(head->val == val){
        return removeElements(head->next,val);
    }

    ListNode* temp = new ListNode(head->val);
    ListNode* nextList = removeElements(head->next,val);

    temp->next = nextList;

    return temp;

}       

int main(){
    
    ListNode* head = new ListNode(6);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 6;

    ListNode* newHead = removeElements(head,n);

    while (newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    


    
    
    return 0;
}