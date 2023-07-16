//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
    public:
    int key;
    int value;
    node* next;
    node* prev;
    node(int kkey,int vvalue){
        key=kkey;
        value=vvalue;
    }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>mp;
    LRUCache(int capacity)
    {
        // code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    //Function to return value corresponding to the key.
    
    void addnode(node* t){
        node* temp=head->next;
        t->next=temp;
        t->prev=head;
        head->next=t;
        temp->prev=t;
        
        
    }
    
    void delnode(node* t){
        node* pt=t->prev;
        node* nt=t->next;
        pt->next=nt;
        nt->prev=pt;
        
    }
    
    int GET(int key)
    {
        // your code here
       
        if(mp.find(key)!=mp.end()){
            node* n=mp[key];
            int t=n->value;
            
            mp.erase(key);
            delnode(n);
            addnode(n);
            mp[key]=head->next;
            return t;
            
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int k, int value)
    {
        // your code here
        
        if(mp.find(k)!=mp.end()){
            node* t=mp[k];
            // int tt=t->value;
            mp.erase(k);
            delnode(t);
            
        }
        if(cap==mp.size()){
            mp.erase(tail->prev->key);
            delnode(tail->prev);
            
            
        }
        addnode(new node(k,value));
        mp[k]=head->next;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends