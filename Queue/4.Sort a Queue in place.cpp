#include<iostream>
using namespace std;

//INCOMPLETE
struct Queue{
    int arr[100];
    int front;
    int rear;
    int currentSize;
};


void enQueue(Queue &Q,int x){

    Q.rear += 1;   //Bhaga Lo Pehle

    if(Q.currentSize==100){
        cout<<"Q is Full "<<endl;
        return ;
    }

    if(Q.rear == 100)
        Q.rear =0;

    Q.arr[Q.rear]=x;
    Q.currentSize++;
}

void deQueue(Queue &Q){
    if(Q.currentSize==0){
        cout<<"Empty "<<endl;
        return ;
    }
    Q.front++;
    if(Q.front==100){
     Q.front = 0;
    }
    Q.currentSize--;
    if(Q.currentSize==0){
        Q.front = 0;
        Q.rear = -1;
    }
}


void print(Queue Q){

while(Q.currentSize){
    cout<<Q.arr[Q.front]<<" ";
    deQueue(Q);
    }
    cout<<endl;
}

//------------------------------Sorting a Queue in Place involves two steps.
// Finding a Min element
// Reordering the queue


/*This is just returns the min element without affecting queue state*/
int findMin(Queue &Q,int k,int n){
int Min = 1000000000;

for(int i=0;i<n;i++){
    int current = Q.arr[Q.front];

    deQueue(Q);
    if(current<Min && i<k)
    { Min = current;}

    enQueue(Q,current);
    }
print(Q); //This Prints the Queue , print function takes Q by copy and doesnt modify actual Queue.
return Min;
}

void reorder(Queue &Q,int Min,int n){
    for(int i=0;i<n;i++){
        int curr = Q.arr[Q.front];
        deQueue(Q);
        if(curr!=Min)
            {  enQueue(Q,curr) ; }

    }
    enQueue(Q,Min);  //EnQueue the min element at last

}

void Sort(Queue &Q){
int n = Q.currentSize;

for(int i=0;i<n;i++){
    int min_no = findMin(Q,n-i,n);
    cout<<"Min : "<<min_no<<endl;
    reorder(Q,min_no,n);
    }

}


int main(){
Queue Q ;
Q.front = 0;
Q.rear = -1;
enQueue(Q,9);
enQueue(Q,6);
enQueue(Q,1);
enQueue(Q,3);
enQueue(Q,5);
Sort(Q);
print(Q);
cout<<"Finally Sorted... :D";
}
