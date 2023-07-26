//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  
    //Function to merge K sorted linked list.
    Node* merge(Node* left,Node* right){
        if(left==NULL)return right;
        if(right==NULL)return left;
        Node* newhead=new Node(-1);
        Node* temp=newhead;
        while(left!=NULL and right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }
            else{
                temp->next=right;
                right=right->next;
                temp=temp->next;
                
            }
        }
        while(left){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        while(right){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        return newhead->next;
        
    }
    
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           for(int i=0;i<k-1;i++){
               Node* n=merge(arr[i],arr[i+1]);
               arr[i+1]=n;
           }
           return arr[k-1];
           
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends