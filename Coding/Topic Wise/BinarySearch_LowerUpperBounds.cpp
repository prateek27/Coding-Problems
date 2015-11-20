#include<iostream>
using namespace std;
//---------------------------------Lower Bound
bool lowFunc(int no,int key){ return no>=key; }
void lowerBound(int a[],int low,int high,int key)
{
    int bestSoFar=-1;
while(low<=high){
        int x=(low+high)/2;
        if(a[x]>=key)
        {
            bestSoFar=x;s
            high=x-1;
        }
        else
            low=x+1;
        }
cout<<"Lower Bound"<<bestSoFar<<endl;
}
//------------------------------Upper
bool upperFunc(int no,int key){ return no<=key; }
void upperBound(int a[],int low,int high,int key)
{
    int bestSoFar=-1;
while(low<=high){
        int x=(low+high)/2;
        if(upperFunc(a[x],key))
        {
            bestSoFar=x;
            low=x+1;
        }
        else
            high=x-1;
        }
cout<<"Upper bound :"<<bestSoFar<<endl;
}
//-------------------------Main

int main(){
int n,i,key;
int a[100];
cout<<"Enter no of elements";
cin>>n;
cout<<"Enter elements "<<endl;
for(i=0;i<n;i++)
    cin>>a[i];
cout<<"Enter the key ";
cin>>key;

lowerBound(a,0,n-1,key);
upperBound(a,0,n-1,key);
return 0;
}
