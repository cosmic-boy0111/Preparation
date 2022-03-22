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


ListNode* L = NULL;


ListNode* reverseList(ListNode* head) {

    if(head==NULL || head->next == NULL){
        return head;
    }

    if(head->next->next == NULL){
        L = head;
        head->next->next = head;
        ListNode* temp = head->next;
        head->next = NULL;
        return temp;
    }

    ListNode* last = head;

    ListNode* newHead = reverseList(head->next);
    // ListNode* temp = newHead;
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }

    // temp->next = last;
    // temp->next->next = NULL;
    L->next = last;
    L->next->next = NULL;
    L = last;
    

    return newHead;

}

// 1 2 3 4 5

int main(){

    ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    head =  reverseList(head);

    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    
    
    
    return 0;
}