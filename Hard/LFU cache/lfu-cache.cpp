//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node{
    public:
    int key,value,count;
    Node* prev;Node* next;
    Node(int k,int v){
        key=k;
        value=v;
        count=1;
    }
};
class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addnode(Node* t){
        Node* temp=head->next;
        head->next=t;
        t->next=temp;
        temp->prev=t;
        t->prev=head;
        size++;
    }
    void delnode(Node* t){
        Node* pn=t->prev;
        Node* nn=t->next;
        pn->next=nn;
        nn->prev=pn;
        size--;
    }
    
};

class LFUCache {
    
    map<int,Node*>kn;
    map<int,List*>freq;
    int maxsize;
    int minfreq;
    int cursize;
    
public:
    LFUCache(int capacity) {
        maxsize=capacity;
        minfreq=0;
        cursize=0;
    }
    
    void updatefreqmap(Node* t){
        kn.erase(t->key);
        freq[t->count]->delnode(t);
        if(t->count==minfreq and freq[t->count]->size==0)minfreq++;
        
        List* nexthigherfreq=new List();
        if(freq.find(t->count+1)!=freq.end()){
            nexthigherfreq=freq[t->count+1];
        }
        t->count+=1;
        nexthigherfreq->addnode(t);
        freq[t->count]=nexthigherfreq;
        kn[t->key]=t;
        
    }
    
    int get(int key) {
        if(kn.find(key)!=kn.end()){
            Node* t=kn[key];
            int v=t->value;
            updatefreqmap(t);
            return v;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(maxsize==0)return;
        
        if(kn.find(key)!=kn.end()){
            Node* n=kn[key];
            n->value=value;
            updatefreqmap(n);
        }
        else{
            if(cursize==maxsize){
                List* list= freq[minfreq];
                kn.erase(list->tail->prev->key);
                freq[minfreq]->delnode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List* listf=new List();
            if(freq.find(minfreq)!=freq.end()){
                listf=freq[minfreq];
            }
            Node* n=new Node(key,value);
            listf->addnode(n);
            kn[key]=n;
            freq[minfreq]=listf;
            
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        int capacity; cin >> capacity;
        LFUCache* obj = new LFUCache(capacity);

        int runs; cin >> runs;
        for(int i = 0;i<runs;i++){
            int s; cin >> s;
            if(s==1){
                int key; cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }else{
                int key,value;
                cin >> key >> value;
                obj->put(key,value);
            }
            
            
            
        }
        


    }
}

// } Driver Code Ends