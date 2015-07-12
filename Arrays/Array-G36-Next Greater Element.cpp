#include<iostream>
#include<stack>
using namespace std;


struct node{
int value;
int index;
    node(int v,int i){
        value=v;
        index=i;
    }
};


void findNextGreater(int *a,int n,int *res)
{
    stack<node> s;
    s.push(node(a[0],0));


    for(int i=1;i<n;i++){
        int next = a[i];
        //Mistake 2 : Missed the empty condtion
    /*    if(!s.empty()){
            if(next>s.top().value){
                       while(next>s.top().value){
            node top = s.top();
            res[top.index]=next;
            s.pop();
                    }

                }
        }
        s.push(node(a[i],i));

    }

    while(!s.empty()){
        res[s.top().index]=-1;
        s.pop();
    }
return;
}

void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int arr[] = { 4,5,5,24 };
int n = sizeof(arr)/sizeof(int);
int *res = new int[n];

findNextGreater(arr,n,res);
print(res,n);

int brr[] = {4,5,5,25};
int *bres = new int[4];
findNextGreater(brr,4,bres);
print(bres,4);


cout<<endl;
return 0;
}
