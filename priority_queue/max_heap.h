#include<vector>
using namespace std;

class HeapSort{
    private:
    vector<int> h;
    void swap(int& a, int& b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    public:
    HeapSort(){

    }
    int size(){
        return h.size();

    }
    bool isEmpty(){
        return h.size()==0;
    }
    int getmax(){
        if(isEmpty()){
            return 0;
        }
        return h[0];
    }

    void Insert(int element){
        h.push_back(element);
        int childIndex = h.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(h[parentIndex] < h[childIndex]){
                swap(h[parentIndex], h[childIndex]);
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
        int a = h[0];
        int size = h.size();
        h[0] = h[size-1];
        h.pop_back();
        
        int parentIndex = 0;
        int lchildIndex = 2* parentIndex + 1;
        int rchildIndex = 2* parentIndex +2;

        while(lchildIndex < h.size()){
            int minIndex = parentIndex;
            if(h[minIndex]< h[lchildIndex]){
                minIndex = lchildIndex;
            }
            if(h[minIndex]<h[rchildIndex]){
                minIndex = rchildIndex;
            }
            if(rchildIndex < h.size() &&  parentIndex == minIndex){
                break;
            }
            if(parentIndex == minIndex){
                break;
            }
            swap(h[minIndex], h[parentIndex]);
            parentIndex = minIndex;
            lchildIndex = 2* parentIndex +1;
            rchildIndex = 2* parentIndex +2;
        }
        return a;

    }

};

