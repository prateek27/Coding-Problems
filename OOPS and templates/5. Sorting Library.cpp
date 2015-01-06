#include<iostream>
using namespace std;


template<typename T,typename T2>
class Sort{

public:
	void bubbleSort(T *a,int low,int n,T2 obj){

		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n-i-1;j++){
				if(obj.compare(a[j],a[j+1])){

                            T temp = a[j];
                            a[j] = a[j+1];
                            a[j+1] = temp;
                    }
                }
        }
    }

void insertionSort(T*a,int low,int n,T2 obj){
    int i,j,key;
    for(i=1;i<n;i++){
       j=i-1;
       //key=a[i];
       while(j>=0&&obj.compare(a[j],a[i])){
        a[j+1]=a[j];
        j--;
       }
     a[j+1]=a[i];
    }
 }
};



class Person{
int  grade;
int marks;

public:
	Person(int c=0,int m=0){
		grade = c;
		marks = m ;

}
int getMarks(){
return marks;
}

};

class comparePerson{
bool ascending ;


public:
    comparePerson(bool flag=true){
    ascending = flag;
    }

bool compare(Person &p1,Person &p2){
	if(ascending){
	return p1.getMarks() > p2.getMarks();
    }
    else{
    return p1.getMarks()< p2.getMarks();
    }
}
};

int main(){

Person parr[3] ;
parr[0] = Person(10,79);
parr[1] = Person(10,83);
parr[2] = Person(10,81);

//----------------------------------Bubble Sort Ascending
Sort<Person,comparePerson> S ;
Person p;
comparePerson pc;
S.bubbleSort(parr,0,3,pc);
cout<<"Bubble Ascen..."<<endl;
for(int i=0;i<3;i++)
{
	cout<<parr[i].getMarks()<<" "<<endl;
}

//-----------------------------------Bubble Sort Descending
comparePerson pd(false);
S.bubbleSort(parr,0,3,pd);
cout<<"Desc..."<<endl;
for(int i=0;i<3;i++)
{
	cout<<parr[i].getMarks()<<" "<<endl;
}
/*
//----------------------------------Insertion Sort Ascending
S.insertionSort(parr,0,3,pc);
cout<<"Insertion Asc..."<<endl;
for(int i=0;i<3;i++)
{
	cout<<parr[i].getMarks()<<" "<<endl;
}
//----------------------------------------Insertion Sort Descending
S.insertionSort(parr,0,3,pd);
cout<<"Insertion Asc..."<<endl;
for(int i=0;i<3;i++)
{
	cout<<parr[i].getMarks()<<" "<<endl;
}
*/
return 0;
}


