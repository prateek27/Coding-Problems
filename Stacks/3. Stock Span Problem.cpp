#include<iostream>
#include<stack>
using namespace std;

/* Interesting Problem , Nice Logic */
//In the worst case , every element will pushed once and popped once . So Time Complexity is O(n)
void findSpans(int *days,int *span,int n){
stack<int> s;
s.push(0) ; //Index of 0th Day
span[0]=1;
int i;
    for(i=1;i<n;i++){

        while(!s.empty()&&days[s.top()]<days[i])
            { s.pop(); }

        if(s.empty())
            span[i] =i+1;
        else{
            span[i] = i - s.top();
        }

    s.push(i);
    }
}


void print(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){

int days[] = { 100, 80, 60, 70, 60, 75, 85 };
int n = sizeof(days)/sizeof(days[0]);
int *span = new int[n];
findSpans(days,span,n);
print(days,n);
print(span,n);
return 0;
}
