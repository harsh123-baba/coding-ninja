#include<iostream>
using namespace std;

class Dynamic{
    private:
        int *data;
        int capacity;
        int nextIndex;
    public:
        Dynamic(){
            
            data = new int[capacity];
            capacity = 5;
            nextIndex = 0;
        }

        //Copy constructor over write 
        //this m aa rhai d2 and argument m aa rha hai d;


        Dynamic (Dynamic const &d){
            // this->data = d.data; // this is damn shallo copy
            //to avoid this we use deep copy

            this->data = new int[capacity];
            for(int i =0; i<d.nextIndex ; i++){
                this->data[i] = d.data[i];
            }


            this->capacity = d.capacity;
            this->nextIndex = d.nextIndex;
        }
//copy assignment over write 
//so called to avoid shallo copy by inbuilt;

    void operator=(Dynamic const &d){
        // this->data = d.data;    // shallo copy   
        this->data = new int[capacity];
        for(int i=0; i<nextIndex; i++){
            this->data[i] = d.data[i];
        }


        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
        
    }



    void Add(int x){
        if(nextIndex == capacity){
            int * newData = new int[2*capacity];
            for(int i =0;i<capacity; i++){
                newData[i] = data[i];
                // nextIndex++;
            }
            delete [] data;
            data  = newData;
            capacity *= 2;
        }
        data[nextIndex] = x;
        nextIndex++;

    }
    void Edit(int x, int i){
        if(i<nextIndex){
            data[i] = x;
        }
        if(i == nextIndex){
            Add(x);
        }
        else{
            return;
        }
    }

    void Print(){
        for(int i=0; i<nextIndex; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Dynamic d;
    d.Add(10);
    d.Add(20);
    d.Add(30);
    d.Add(40);
    d.Add(50);
    d.Add(60);
    // d.Print();


    Dynamic d2(d);

    // when i call the d.Edit(x) ; our copy constructor changes the value of d2  too;
    //beacuse our constructor use shallo copy here
    //to stop this nonsence we use to use our own copy constructor and copy assignment too;
    d.Edit(1000, 1);
    d2.Print();
    d.Print();
    Dynamic d3;
    d3 = d; //this is an copy assignment where also shallo copy works dude!!
    d3.Print();


}