#include<iostream>
using namespace std;


int main();
//to find determinant and inverse of a 3*3 matrix

int i,j;
float matrix[3][3],inverse[3][3];

cout<<"Enter the elements of 3 X 3 matrix : " <<endl;
for(i=0;i<3;i++)
{
                for(j=0;j<3;j++)
                {
                cin>>matrix[i][j];
                }
}

