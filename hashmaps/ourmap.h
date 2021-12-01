#include<iostream>
#include<string>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;
    }
};

template<typename V>
class ourmap{
    private:
    int numBucket;
    int count;
    MapNode<V> ** buckets;
    public:
    ourmap(){
        count=0;
        numBucket = 5;
        buckets = new MapNode<V>*[numBucket];
        for(int i = 0; i<numBucket; i++){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i = 0; i<numBucket; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }
    int bucketsize(){
        return numBucket;
    }
    private:
    int getBucketIndex(string key){
        int hashcode = 0;
        int currcoeff = 1;
        for(int i = key.length()-1; i>=0; i--){
            hashcode += key[i] * currcoeff;
            hashcode = hashcode % numBucket;
            currcoeff *= 37;
            currcoeff = currcoeff % numBucket;
        }
        return hashcode % numBucket;
    }
    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[numBucket*2];
        for(int i = 0; i<numBucket *2 ; i++){
            buckets[i] = NULL;
        }
        int oldNumbucket = numBucket;
        numBucket *=2;
        int count = 0;
        for(int i = 0; i<oldNumbucket; i++){
            MapNode<int>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                Insert(key, value);
                head = head->next;
            }
        }
        for(int i = 0; i<oldNumbucket; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:
    void Insert(string key, V value){
        int bucketindex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketindex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
        double loadfactor = (1.0* count)/numBucket;
        if(loadfactor>0.7){
            rehash();
        }
    }

    int getValue(string key){
        int bucketindex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketindex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head= head->next;
        }
        return 0;
    }

    V remove(string key){
        int bucketindex = getBucketIndex(key);
        MapNode<V> * head = buckets[bucketindex];
        MapNode<V>* prev = NULL;

        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketindex] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                count--;
                delete head;
                return value;
            }

            prev = head;
            head = head->next;
            
        }
return 0;
    }

};


