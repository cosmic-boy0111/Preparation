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

int length(node* head){
    int l = 0;
    node* temp = head;
    while (temp){
        temp = temp->next;
        l++;
    }

    return l;
    
}

void intersect(node* &head1,node* &head2,int pos){
    node* temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    node* temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
    
    
}

int intersection(node* &head1,node* &head2){

    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node* ptr1;
    node* ptr2;

    if(l1 > l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return -1;
        d--;
    }

    while (ptr1 != NULL and ptr2 != NULL)
    {
        if(ptr1 == ptr2){
            return ptr1->val;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }

    return -1;
    
    

}



int main(){
    

    node* head1 = NULL;
    node* head2 = NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);

    insertAtTail(head2,9);
    insertAtTail(head2,10);
    insertAtTail(head2,11);

    intersect(head1,head2,3);
    display(head1);
    display(head2);

    cout << intersection(head1,head2) << endl;


    
    
    
    return 0;
}