#include<iostream>
using namespace std;


void swap(int *a,int *b){
int temp = *a;
*a = *b;
*b = temp;
return;
}

//----------------------------------DNF Algorithm : SortIn One Pass
void sortInOnePass(int *a,int n){
 int lo = 0;
   int hi = n - 1;
   int mid = 0;

   while(mid <= hi)
   {
      switch(a[mid])
      {
         case 0:
           swap(&a[lo++], &a[mid++]);
           break;
         case 1:
           mid++;
           break;
         case 2:
           swap(&a[mid], &a[hi--]);
           break;
      }
   }
return;
}
//------------------------------------Print
void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
int a[]=  {0,1,0,1,0,2,0,1,1,2,2,0}; //{0, 1, 0, 1, 1, 1};
int n = sizeof(a)/sizeof(int);
sortInOnePass(a,n);
print(a,n);
return 0;
}
