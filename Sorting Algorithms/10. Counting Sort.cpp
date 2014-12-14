#include<iostream>
#include<cstring>
using namespace std;
//Complexity : O(n+k) N is the number of elements , k is the range of elements.
//Problem to sort a string .
/* Algorithm : For simplicity, consider the data in the range 0 to 9.
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index
  stores the sum of previous counts.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in
the output sequence.

  3) Output each object from the input sequence followed by
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place
  next data 1 at an index 1 smaller than this index.

  */

void countingSort(char *s){
int len = strlen(s);
char output[len];
int count[256];
memset(count,0,sizeof(count));
int i;
for(i=0;i<len;i++)
    count[s[i]]++;
for(i=1;i<256;i++){
    count[i]+=count[i-1];  //This gives the effective ending postion in output of that number
}
for(i=0;i<len;i++){
//Filling the 'right' character for the i th position.
    output[count[s[i]]-1]=s[i];
    --count[s[i]];
    }
//Copy back to orignial array
for(i=0;i<len;i++)
    s[i]=output[i];
}

int main(){
    char s[] = "efgabclmnopdefeaac";
    countingSort(s);
    cout<<s;
    return 0;
}
