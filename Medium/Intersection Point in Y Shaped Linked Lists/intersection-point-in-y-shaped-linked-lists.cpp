//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
int l(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        if(head1==NULL)return head2->data;
        if(head2==NULL)return head1->data;
        int len1=l(head1);
        int len2=l(head2);
       // cout<<len1;cout<<len2;
        Node* t1;
       Node* t2;
        //t1 goes to bigger length
        if(len1>len2){
            t1=head1;
            t2=head2;
        }
        else{
            t1=head2;
            t2=head1;
            
        }
        int diff=abs(len1-len2);//cout<<diff;
      //  int count=0;
        while(diff){t1=t1->next;diff--;}
      
        while(t1->next!=NULL){
            if(t1->next==t2->next)return t1->next->data;
            t1=t1->next;
            t2=t2->next;
        }
         // cout<<t1->data;cout<<t2->data;
        return -1;
        
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends