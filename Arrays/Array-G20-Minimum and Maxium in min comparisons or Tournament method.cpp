#include<iostream>
using namespace std;
#define pair Pair
struct pair{
int chota;
int bada;
};

//There is another method given (easy) on GeeksForGeeks.This method "Comparison in Pairs" takes even less comparisons.

pair findChotaBada(int *a,int low,int high){
    int n = high-low+1;

    if(n==1){
        pair p;
        p.chota = a[low];
        p.bada = a[low];
        return p;
    }
    if(n==2){
        pair p;
        p.chota = min(a[low],a[high]);
        p.bada = max(a[low],a[high]);
        return p;
    }
    else{
        pair p;
        int mid=(low+high)/2;
        pair p1 = findChotaBada(a,low,mid);
        pair p2 = findChotaBada(a,mid+1,high);

        p.chota = min(p1.chota,p2.chota);
        p.bada = max(p1.bada,p2.bada);

        return p;
    }
}



int main(){
int a[] = {1,-200,3,5,6,7,8,100,1,-50,-80,150,250,35};
int n= sizeof(a)/sizeof(int);
pair p = findChotaBada(a,0,n-1);
cout<<p.bada<<","<<p.chota;
return 0;
}
