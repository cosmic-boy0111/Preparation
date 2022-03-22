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
        node* next;

        node(int data = 0){
            val = data;
            next = NULL;
        }
};


void insertAtTail(node* &head,int data){
    node* n = new node(data);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    
}

void display(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
    
}


node* merge(node* &head1,node* &head2){

    node* p1 = head1;
    node* p2 = head2;

    node* dummy = new node(-1);
    node* p3 = dummy;

    while (p1 != NULL  and p2 != NULL){
        if(p1->val < p2->val){
            p3->next = p1;
            p1 = p1->next;
        }else{
            p3->next = p2;
            p2 = p2->next;
        }

        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p1 = p2->next;
        p3 = p3->next;
    }
    
    return dummy->next;
    

}


node* mergeRecursive(node* &head1,node* &head2){

    if(head1==NULL){
        return head2;
    }

    if(head2 == NULL){
        return head1;
    }

    node* result;
    if(head1->val < head2->val){
        result = head1;
        result->next = mergeRecursive(head1->next,head2);
    }else{
        result = head2;
        result->next = mergeRecursive(head1,head2->next);
    }

    return result;
}


int main(){
    

    node* head1 = NULL;
    node* head2 = NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,7);

    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,6);

    display(head1);
    display(head2);

    // node* newHead = merge(head1,head2);
    node* newHead = mergeRecursive(head1,head2);

    display(newHead);


    
    return 0;
}