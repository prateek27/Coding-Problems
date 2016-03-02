#include<iostream>
using namespace std;

class Priority_Queue{

    int index;
    int total_size;
    int *a;

private:

     void heapify(int index){
        while(index >1){

            int parent = index/2;
            if( a[parent] > a[index]){
                break;
            }
            else{
                swap(a[parent],a[index]);
                index = index>>1;
            }

        }
       return ;
    }
     void heapifyDown(int index){

            int left = 2*index;
            int right = left + 1 ;

            int mx = index;

            if(left <= total_size ){
                if( a[left] > a[mx] ){
                    mx = left;
                }
            }
            if(right <= total_size ){
                if(a[right] > a[mx]){
                    mx = right;
                }
            }

            if(mx!=index){
            swap( a[index],a[mx]);
            heapifyDown(mx);

            }
        }




public:
    int getSize(){
    return total_size;
    }

    Priority_Queue(int s){
        index=1;
        a = new int[s+1];
        total_size = 0;
    }

    void push(int no){
            a[index] = no;
            heapify(index);
            index++;
            total_size++;
    }
    int top(){
        return a[1];
    }

    void pop(){
        swap(a[1],a[index-1]);
        index--;
        total_size--;
        heapifyDown(1);
    }



};

int main(){

Priority_Queue pq(100);
int a[]= {3,2,4,6,7,8,6,7,10};
int n = sizeof(a)/sizeof(int);
for(int i=0;i<n;i++){
    pq.push(a[i]);
}

while(pq.getSize()){
cout<<pq.top()<<endl;
pq.pop();
}

return 0;
}
