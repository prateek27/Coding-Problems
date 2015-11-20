#include<iostream>
using namespace std;
int Partition(int a[], int beg, int end)          //Function to Find Pivot Point
{
int p=beg, pivot=a[beg], loc;

for(loc=beg+1;loc<=end;loc++)
{
if(pivot>a[loc])
{
a[p]=a[loc];
a[loc]=a[p+1];
a[p+1]=pivot;

p=p+1;
}
}
return p;
}


void QuickSort(int a[], int beg, int end)
{
if(beg<end)
{
int p=Partition(a,beg,end);                       //Calling Procedure to Find Pivot

QuickSort(a,beg,p-1);                             //Calls Itself (Recursion)
QuickSort(a,p+1,end);			              //Calls Itself (Recursion)
}
}
int main(void){
    long long ans=0;
    long long sum=0;
    int arr[100005]={0},t=0,x;
    int n,num;
    cin>>n;
    while(n){
        cin>>num;
        if(num<0){
            sum=sum+(-num);
            arr[t]=-num;
            t++;
        }
        n--;
    }
    QuickSort(arr,0,t-1);
    cin>>x;
    long long sum1=0;

    for(int i=0;i<t-x;i++)
        sum1+=arr[i];
    long long sum2=sum-sum1;
    //cout<<sum1<<" "<<sum2;
    ans=ans+(x*arr[t-x-1]);
    sum2=sum2-(x*arr[x-1]);
    ans+=sum2;
    cout<<ans;
    return 0;
}
