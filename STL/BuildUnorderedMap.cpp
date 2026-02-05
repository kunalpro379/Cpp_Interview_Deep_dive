#include <iostream>
#include <stdio.h>
using namespace std;

template<typename K, typename V>
class UMP{
    private:
    struct Node{
        K key;
        V val;
        Node* next;
        Node(const K&k, const V&v){
            this->key=k;
            this->val=v;
            this->next=nullptr;
        }

    };
        Node** buckets;
        size_t NoOfBuckets;
        size_t currentSize;   
        size_t hashFn(const K& key){
            return hash<K>{}(key)%NoOfBuckets;
            /*
Spread keys uniformly
Produce large numbers
Reduce collisions
            */
        }
    public:
    UMP(size_t bucketCount){
        this->NoOfBuckets=bucketCount;
        currentSize=0;
        buckets=new Node*[NoOfBuckets];//array of Node* type
        for(size_t i =0;i<NoOfBuckets;i++){
            buckets[i]=nullptr;
        }

    }
    void Insert(const K&key, const V&val){
        size_t index=hashFn(key);
        Node* head=buckets[index];
        //is key already exists
        while(head){
            if(head->key==key){
                head->val=val;//update value
            }
            head=head->next;
        }
        ///if not present then insert a new node at beginning
        Node* newNode=new Node(key, val);
        newNode->next=buckets[index];
        buckets[index]=newNode;
        currentSize++;
    }
    bool find(const K&key,  V&val){
        size_t index=hashFn(key);
        Node* head= buckets[index];
        while(head){
            if(head->key==key){
                val=head->val;
                return true;
            }head=head->next;
        }
        return false;
    }
    ~UMP(){
        for(size_t i=0;i<NoOfBuckets;i++){
            Node* head=buckets[i];
            while(head){
                Node* temp=head;
                head=head->next;
                delete temp;
            }
        }delete[] buckets;
    }
    void print(){
    for(size_t i=0;i<NoOfBuckets;i++){
        cout<<"Bucket"<<i<<"------>";
        Node* head=buckets[i];
        if(!head)cout<<"NULL";
        while(head){
            cout<<"<--->"<<head->key<<","<<head->val;
            head=head->next;
        }
        cout<<endl;
    }

}

};

int main(){
    UMP<int, string>MP(10);


    // Bucket 1 collisions
    MP.Insert(1,  "one");
    MP.Insert(11, "eleven");
    MP.Insert(21, "twenty-one");
    MP.Insert(31, "thirty-one");
    MP.Insert(41, "forty-one");

    // Bucket 2 collisions
    MP.Insert(2,  "two");
    MP.Insert(12, "twelve");
    MP.Insert(22, "twenty-two");
    MP.Insert(32, "thirty-two");

    // Bucket 6 collisions
    MP.Insert(6,  "six");
    MP.Insert(16, "sixteen");
    MP.Insert(26, "twenty-six");
    MP.Insert(36, "thirty-six");

    // Extra (different buckets)
    MP.Insert(7,  "seven");
    MP.Insert(8,  "eight");
    string value;
    if(MP.find(2, value)){
        cout<<value<<endl;
    }
    cout<<endl<<endl;
    MP.print();

    return 0;
}