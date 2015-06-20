#include<iostream>
using namespace std;

void sort0s1s(int *a,int n){
int l=0;
int r = n-1;

while(l<r){
    //Note these conditons are important l<r
    while(a[l]!=1&&l<r)
        l++;
    while(a[r]!=0&&l<r)
        r--;
    //Checking l<r is important
    if(l<r)
        swap(a[l++],a[r--]);
}


}

int main()
{
    int arr[] = {1,1,1,1,0, 1, 0, 1, 1,0,0,0,1};
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);

    sort0s1s(arr, arr_size);

//    printf("array after segregation ");
    for (i = 0; i < arr_size; i++)
        cout<<arr[i]<<",";


    return 0;
}
