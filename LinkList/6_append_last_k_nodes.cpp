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

int length(node* head){
    int l = 0;
    node* temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node* kappend(node* &head,int k){

    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);
    k = k%l;
    int cnt = 1;

    while (tail->next != NULL){

        if(cnt == l-k){
            newTail = tail;
        }

        if(cnt == l-k+1){
            newHead = tail;
        }

        tail = tail->next;
        cnt++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
    

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




int main(){
    
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    display(head);

    node* newHead = kappend(head,3);
    display(newHead);
    
    return 0;
}