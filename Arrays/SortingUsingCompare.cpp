#include<iostream>
#include<algorithm>
using namespace std;

bool compare(const int&a,const int&b){
    return a<b;
}

class triplet{
int val,index,count;
};

int main(){


int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    sortByFrequency(arr, n);


return 0;
}
