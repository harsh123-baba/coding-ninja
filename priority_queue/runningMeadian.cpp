#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// #include <algorithm>

// void findMedian(int arr[], int n)
// {
// 	int median;
	
//     // Traverse through the array
// 	for(int i=0; i<n; i++)
// 	{	
//         // Sort the array from 0-th to i-th index
// 		sort(arr, arr+i+1);
		
//         // Check if i+1 is odd
// 		if((i+1)%2 == 1)
// 		{
// 			median = arr[i/2];
// 		}
// 		else
// 		{
// 			median = (arr[i/2] + arr[i/2 + 1])/2;
// 		}	
		
//         // Print the variable median
// 		cout << median << " ";
// 	}
// }




void runningMedian(int v[], int size){
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

    int med = v[0];
    s.push(v[0]);
    cout<<med<<endl;
    for(int i = 1; i<size; i++)
    {
        int x = v[i];
        if(s.size()>g.size()){
            if(x<med){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else{
                g.push(x);
            }
            med = (s.top()+g.top())/2.0;
        }
        else if(s.size()== g.size()){
            if(x<med){
                s.push(x);
                med = (int)s.top();
            }
            else{
                g.push(x);
                med = (int)g.top();

            }

        }
        else{
            if(x>med){
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else{

                s.push(x);
            }
            med = (s.top()+g.top())/2.0;
        }
        cout<<med<<endl;

    }

}


// void runningMedian(int arr[], int n){
//     priority_queue<int> s; 
  
//     // min heap to store the greater half elements 
//     priority_queue<int,vector<int>,greater<int> > g; 
  
//     int med = arr[0]; 
//     s.push(arr[0]); 
  
//     cout << med << endl; 
  
//     // reading elements of stream one by one 
   
//     for (int i=1; i < n; i++) 
//     { 
//         int x = arr[i]; 
  
//         // case1(left side heap has more elements) 
//         if (s.size() > g.size()) 
//         { 
//             if (x < med) 
//             { 
//                 g.push(s.top()); 
//                 s.pop(); 
//                 s.push(x); 
//             } 
//             else
//                 g.push(x); 
  
//             med = (s.top() + g.top())/2.0; 
//         } 
  
//         // case2(both heaps are balanced) 
//         else if (s.size()==g.size()) 
//         { 
//             if (x < med) 
//             { 
//                 s.push(x); 
//                 med = (int)s.top(); 
//             } 
//             else
//             { 
//                 g.push(x); 
//                 med = (int)g.top(); 
//             } 
//         } 
  
//         // case3(right side heap has more elements) 
//         else
//         { 
//             if (x > med) 
//             { 
//                 s.push(g.top()); 
//                 g.pop(); 
//                 g.push(x); 
//             } 
//             else
//                 s.push(x); 
  
//             med = (s.top() + g.top())/2.0; 
//         } 
  
//         cout << med << endl; 
//     } 
// }


int main(){
    int A[] = {6, 2, 1, 3, 7, 5};
    runningMedian(A, 6);
}