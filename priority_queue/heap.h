#include<vector>
using namespace std;

class Heap{
    private:
    vector<int> pq;
    void swap(int& a, int& b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    public:
    int size(){
        return pq.size();
   }
   bool isEmpty(){
       return pq.size() == 0;
   }

   int getMin(){
       if(isEmpty()){
           return 0;
       }
       return pq[0];
   }

   void Insert(int element){
       pq.push_back(element);
       int childIndex = pq.size()-1;
       while(childIndex > 0){
           int parentIndex = (childIndex-1)/2;
           if(pq[parentIndex] > pq[childIndex]){
               swap(pq[parentIndex], pq[childIndex]);
               childIndex = parentIndex;

           }
           else{
               break;
           }
       }
   }

    int remove(){
        if(isEmpty()){
            return 0;
        }
        int a = pq[0];
        int size = pq.size();
        pq[0] = pq[size-1];
        pq.pop_back();
        int parentIndex = 0;
        int rightChildIndex = 2* parentIndex +1;
        int leftchildIndex = 2* parentIndex +2;
        while(leftchildIndex < size){
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftchildIndex]){
                minIndex = leftchildIndex;
            }
            if( rightChildIndex < size && pq[minIndex] > pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(parentIndex == minIndex){
                break;
            }
            swap(pq[minIndex], pq[parentIndex]);
            parentIndex = minIndex;
            leftchildIndex = 2* parentIndex +1;
            rightChildIndex = 2* parentIndex+2;
       }
       return a;
   }

};  

