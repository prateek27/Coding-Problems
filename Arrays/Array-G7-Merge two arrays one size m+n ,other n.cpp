#include<iostream>
using namespace std;



#define NULL -1

void printArray(int *a,int m){
    for(int i=0;i<m;i++)
        {cout<<a[i]<<", ";}
}

/*This party is tricky.Dont make the remaining elements as -1*/
void moveToEnd(int a[],int n){
    int j=n-1;
    int i;
    for(i=n-1;i>=0;i--){

        if(a[i]!=-1){
            a[j]=a[i];
            j--;
            }

    }

}

void merge_arrays(int *big,int *small,int m,int n){
int i=n;
int j=0;
int k=0;
while(k<(m+n)){
        //Check the last condition Carefully............
    if(j==n||big[i]<=small[j]&&i<(m+n))
    {
        big[k]=big[i];
        i++;
        k++;

    }
    else{
        big[k]=small[j];
        j++;
        k++;

    }


    }
}

int main()
{
 int mPlusN[] = {2, 8, NULL, NULL, NULL, 13, NULL, 15, 20};
  int N[] = {5, 7, 9, 25};
  int n = sizeof(N)/sizeof(N[0]);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
  moveToEnd(mPlusN, m+n);

  merge_arrays(mPlusN,N,m,n);
  printArray(mPlusN, m+n);
  return 0;
}
