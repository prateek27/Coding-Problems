#include<iostream>
using namespace std;

/*
There can be three different types of inputs that need to be handled separately.
1) The input number is palindrome and has all 9s. For example “9 9 9″. Output should be “1 0 0 1″
2) The input number is not palindrome. For example “1 2 3 4″. Output should be “1 3 3 1″
3) The input number is palindrome and doesn’t have all 9s. For example “1 2 2 1″. Output should be “1 3 3 1″.
*/

void print(int *a,int n){

for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}

void helper(int *num,int n){
   int mid=n/2;
   int  i = mid-1;
   int j = n%2==1?mid+1:mid;


   bool leftsmaller = false;

    while(i>=0&&num[i]==num[j])
    {    i--; j++; }


    // i < 0 when the string is a palindrome
    // num[i] < num[j] Add carry to the middle , propagate to left

    if(i<0||num[i]<num[j])
      {

        leftsmaller=true;
      }

    while(i>=0){
    num[j]=num[i];
    j++;
    i--;
    }

    if(leftsmaller==true){
    int carry=1;


    i = mid-1;

    if(n%2==1){

        num[mid+1]+=carry;
        carry = num[mid+1]/10;
        num[mid+1]%=10;
        j=mid+1;
    }
    else{
        j=mid;
    }
    //Propagate Carry and Copy to right
    while(i>=0){
        num[i]+=carry;
        carry = num[i]/10;
        num[i]%=10;
        num[j++]=num[i--];
        }
    }
}


void nextPalindrome(int *a,int n){

//Special case if all 9
    bool is9 =true;
    int i;
    for(i=0;i<n;i++){
        if(a[i]!=9)
            is9=false;
    }
    if(is9){
    cout<<"1";
    for(i=0;i<n-1;i++)
        cout<<"0";
     cout<<"1"<<endl;
    return;
    }
    else{
      helper(a,n);
      print(a,n);
    }
}


int main(){

   // int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    //int num[] =  {1 ,2, 3, 4, 6, 2, 8};
     int num[]  ={7 ,1 ,3 ,3 ,2, 2};

    int n = sizeof (num)/ sizeof(num[0]);

    nextPalindrome( num, n );


return 0;
}
