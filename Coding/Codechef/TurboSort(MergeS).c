#include<stdio.h>
#include<conio.h>

void partition(int arr[],int low,int high,int t);
void mergeSort(int arr[],int low,int mid,int high,int t);

int main(){
    int n,i,t;
    scanf("%d",&n);
    int merge[t];
    for(i=0;i<n;i++)
    {
                    scanf("%d",&merge[i]);
    }
     partition(merge,0,n-1,t);
    
    
    for(i=0;i<n;i++)
    {
                  printf("%d\n",merge[i]);
    }
    
    getch();
    return 0;
}


void partition(int arr[],int low,int high,int t)
{
 int mid;
 if(low<high){
              mid=(low+high)/2;
               partition(arr,low,mid,t);
               partition(arr,mid+1,high,t);
               mergeSort(arr,low,mid,high,t);
              }
              
}

void mergeSort(int arr[],int low,int mid,int high,int t)
 {   int l,h,m,i,k,temp[t];
     i=low;
     l=low;
     h=high;
     m=mid+1;
     while(l<=mid&&m<=high){
                            if(arr[l]<=arr[m]){
                                          temp[i]=arr[l];
                                          l++;
                                          }
                            else{
                                 temp[i]=arr[m];
                                 m++;
                                 }
                                 i++;
                            }
     if(l>mid){
               for(k=m;k<=high;k++){
                                    temp[i]=arr[k];
                                    i++;
                                    }
                                    }
     else{
          for(k=l;k<=high;k++){
                               temp[i]=arr[k];
                               i++;
                               }
                               }
          for(k=low;k<=high;k++){
                                 arr[k]=temp[k];
                                 }
          }
          
               
                                 
