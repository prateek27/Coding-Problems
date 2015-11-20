#include<stdio.h>
void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[1000];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

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
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

int main(){
int n,sum=0,a[1000],count=0,distribute,i;
scanf("%d",&n);
while(n!=-1){
   for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   sum=sum+a[i];
   }
   distribute=sum/n;
   partition(a,0,n-1);
   if(sum%distribute==0){
   for(i=n-1;i>=0;i--){
   if(a[i]>distribute)
    {
        count=count+(a[i]-distribute);
    }
    else if(a[i]<distribute){
        break;
    }
   }}
   else
    count=-1;


printf("%d\n",count);
count=0;
sum=0;
scanf("%d",&n);
}

return 0;

}



