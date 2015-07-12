#include<iostream>
using namespace std;

void sortIt(int *a,int n)
{
/* 0 to low-1 : 0
   low to mid-1 : 1
   mid to high : UNDETERMINED
   high+1 to n-1 : 2's
   */

   //Notes: Use else if in second and third cases.If will give error.
   int low=0,mid=0,high=n-1;
   while(mid<=high){

            if(a[mid]==0){
                swap(a[low++],a[mid++]);

            }
            else if(a[mid]==1){
                mid++;
            }
            else if(a[mid]==2){
                swap(a[high--],a[mid]);
            }

        }
   }

void print(int *a,int n){
    for(int i=0;i<n;i++)
        {cout<<a[i]<<",";
        }
}
int main(){
int a[] = {0,1,0,0,2,0,0,1,2,0,0,0,2,1,0,2,1};
int n =sizeof(a)/sizeof(int);
sortIt(a,n);
print(a,n);
return 0;
}
