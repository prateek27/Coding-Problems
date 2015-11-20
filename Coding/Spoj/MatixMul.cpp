#include<iostream>
using namespace std;

class matrix{
public:
int m,n;
int a[100][100];


void setSize(int a,int b){
m=a;
n=b;

};


void scanMatrix(){
  cout<<"Enter the Elements ";


for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
}

virtual void multiplyMatrix(matrix A,matrix B){
cout<<"I am the virtual function in Base Class.\
Please refer me in derived class to multiply the matrixes"<<endl;
    }

void display(matrix A){
    for(int i=0;i<A.m;i++)
        for(int j=0;j<A.n;j++)
            cout<<a[i][j]<<" ";
}

};

class matrixMultiply:public matrix{

public:
void mutliplyMatrix(matrix A,matrix B)
{

int c,d,k;
int m=A.m;
int p=B.m,q=B.n;
int sum=0;
int multiply[m][q];

for (c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      {
        for ( k = 0 ; k < p ; k++ )
        {
          sum = sum + A.a[c][k]*B.a[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      cout<<multiply[c][d]<<" ";
      }
    cout<<endl;
    }
}


};

int main(){

matrix A,B;
A.setSize(2,2);
A.scanMatrix();

B.setSize(2,2);
B.scanMatrix();

matrix C;
C.multiplyMatrix(A,B);

matrix *mptr;
mptr = &C;

mptr->multiplyMatrix(A,B);
//C.display();

return 0;
}
