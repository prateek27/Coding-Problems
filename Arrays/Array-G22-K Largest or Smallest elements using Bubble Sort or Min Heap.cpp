#include<iostream>
#include<queue>
#include<functional>
using namespace std;

/*Methods
1. Bubble Sort
2. Temporary Array
3. Sorting
4. Max Heap
5. Order Statistics
6. Min Heap
*/
//---------------------------------------------Bubble Sort Method
void kBubbleSort(int *a,int n,int k){

    for(int i=0;i<k;i++){
        for(int j=i;j<n-1;j++){
                if(a[j]>a[j+1])
                    swap(a[j],a[j+1]);
            }
    }
for(int i=n-1;i>=n-k;i--){
        cout<<a[i]<<" ,";
    }
}
//------------------------------------------------Min Heap Method implemented using Priority Queue
// Priority Queue supports PUSH,POP,TOP,EMPTY operations. By default it acts like a Max Heap


void maxHeapMethod(int *a,int n,int k){
    priority_queue<int> mxHeap;

    cout<<"Using Max Heap :"<<endl;
    for(int i=0;i<n;i++){
    mxHeap.push(a[i]);
    }
    int cnt = k;
    while(cnt--){
        cout<<mxHeap.top()<<",";
        mxHeap.pop();
    }

}


void minHeapMethod(int *a,int n,int k){
    priority_queue<int,vector<int>,greater<int>> minHeap;

    cout<<"Using Min Heap :"<<endl;
    for(int i=0;i<n;i++){
    minHeap.push(a[i]);
    }
    int cnt = k;
    while(cnt--){
        cout<<minHeap.top()<<",";
        minHeap.pop();
    }

}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int i, n = sizeof(arr)/sizeof(arr[0]);

    kBubbleSort(arr,n,3);
    maxHeapMethod(arr,n,3);
    minHeapMethod(arr,n,3);


    return 0;
}
