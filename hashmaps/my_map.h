// #include<string>
// using namespace std;

// template <typename V>
// class MapNode{
//     public:
//     string key;
//     V value;
//     MapNode<V>* next;

//     MapNode(string key , V value){
//         this->key = key;
//         this->value = value;
//         next = NULL;
//     }
//     ~MapNode(){
//         delete next;
//     }

// };

// template<typename V>
// class Ourmap{
//     MapNode<V>** buckets;
//     int count;
//     int bucketsize;
//     Ourmap(){
//         count =0;
//         bucketsize = 20;
//         buckets = new MapNode<V>*[bucketsize];
//         for(int i = 0; i<bucketsize ; i++){
//             buckets[i] = NULL;
//         } 
//     }
//     ~Ourmap(){
//         for(int i = 0 ; i<bucketsize; i++){
//             delete buckets[i];
//         }
//         delete []buckets;
//     }

//     int size(){
//         return count;
//     }
//     V getvalue(string key){
         
//     }

//     private:
//     int getBuketIndex(string key){
//         int hashcode = 0;
//         int currcoeff = 1;
//         for(int i - key.length()-1; i>=0 ;i++){
//             hashcode += key[i] * currcoeff;
//             hashcode = hashcode% bucketsize;
//             currcoeff *= 37;
//             currcoeff = currcoeff % bucketsize;
//         }
//         return hashcode % bucketsize;
//     }
//     public:
//     void Insert(string key , V value){
//         int bucketIndex = getBuketIndex(key);
//         MapNode<V>* head = buckets[bucketIndex];
//         while(head != NULL){
//             if(head->key == key){
//                 head->value = value;
//                 return;

//             }
//             head = head->next;
//         }
//         head = buckets[bucketIndex];
//         MapNode<V>* node = new MapNode<V>(key, value);
//         node->next = head;
//         buckets[bucketIndex] = node;

//     }



// };


#include<string>
#include<bits/stdc++.h>
using namespace std;


template <typename V>
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
    int count;
    int numbukets;
    MapNode<V>** buckets;
    public:    
    ourmap(){
        count = 0;
        numbukets = 5;
        buckets = new MapNode<V>*[numbukets];
        for(int i = 0; i<numbukets; i++){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i = 0; i<numbukets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

    double getloadFactor(){
        return (1.0* count)/numbukets;
    }
    int bucketSize(){
        return numbukets;
    }
    private:
    int getBucketIndex(string key){
        int currcoeff = 1;
        int hashcode = 0;
        for(int i = key.length()-1; i>=0; i--){
            hashcode = hashcode + key[i]* currcoeff;
            hashcode = hashcode % numbukets;
            currcoeff *= 37;
            currcoeff = currcoeff % numbukets;
        }
        return hashcode % numbukets;
    }
    private:
    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2 * numbukets];
        for(int i = 0; i<2*numbukets; i++){
            buckets[i] = NULL;
        }
        int oldbucketCount = numbukets;
        numbukets *= 2;
        count = 0;
        for(int i = 0; i<oldbucketCount; i++){
            MapNode<V>* head = temp[i];
            while (head!= NULL)    
            {
                string key = head->key;
                V value = head->value;
                Insert(key, value);
                head = head->next;
            }
            
        }
        for(int i = 0; i<oldbucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:
    void Insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                // cout<<"done"<<endl;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;
        // cout<<"done1\n";
        buckets[bucketIndex] = node;
        count++;
        double loadfactor = (1.0 * count)/numbukets;
        if(loadfactor > 0.7){
            rehash();
        }

    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }
                else{
                prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;

            }   
            prev = head;
            head = head->next;
        }
        return 0;

    }

    bool Search(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return true;
            }
            head = head->next;
        }
        return false;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head ->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

};

