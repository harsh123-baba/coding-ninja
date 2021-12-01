#include<vector>
using namespace std;


class PriorityQueue{
    private:
    vector <int> pq;
    void swap(int& a , int& b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int size(){
        return pq.size();
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
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                swap(pq[childIndex], pq[parentIndex]);
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
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        while(leftChildIndex < size){
            int minIndex = parentIndex;
            if(pq[leftChildIndex] < pq[minIndex]){
                minIndex = leftChildIndex;

            }
            if( rightChildIndex < size &&pq[rightChildIndex] < pq[minIndex]){
                minIndex = rightChildIndex;
            }
            if(parentIndex == minIndex){
                break;
            }
            swap(pq[minIndex], pq[parentIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex +1;
            rightChildIndex = 2* parentIndex +2;
        }
        return a;
    }

};