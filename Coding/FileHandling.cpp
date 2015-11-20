#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 char roll[256],name[256];
 int marks[6];
 int total;
string line;
ifstream read_file("student.dat"); //file opened in write mode
ofstream outPass("pass.dat");
ofstream outFail("fail.dat");

while(getline(read_file, line)){
bool pass=true;
read_file>>roll;
read_file>>name;
int i;

for(i=0;i<6;i++){
    read_file>>marks[i];
    if(marks[i]<40)
        pass=false;
    }
    read_file>>total;

if(pass)
{ outPass<<roll<<"\t"<<name<<"\t";
    for(i=0;i<6;i++)
        outPass<<marks[i]<<"\t";
outPass<<total<<endl;
}
else{
outFail<<roll<<"\t"<<name<<"\t";
    for(i=0;i<6;i++)
        outFail<<marks[i]<<"\t";
outFail<<total<<endl;
    }
}
read_file.close(); //file closed

return 0;
}
