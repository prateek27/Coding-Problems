#include<iostream>
#include<cstring>
using namespace std;


class String{
public:char *p;
int len;
public:
    String(){len=0;p=0;}
    String(const char *s);
    String(const String &s);
    ~String(){delete p;}
friend String operator+(String &s,String &t);
friend String operator<=(String &s,String &t);
friend void show(String s);
};
String::String(const char *s){
len=strlen(s);
p=new char[len+1];
strcpy(p,s);
}
String::String(const String &s){
len=s.len;
p=new char[len+1];
strcpy(p,s.p);
}
String operator+(String &s,String &t){
String temp;
temp.len=s.len+t.len;
temp.p = new char[temp.len+1];
strcpy(temp.p,s.p);
strcat(temp.p,t.p);
return temp;
}
int operator<=(const String&s,const String &t){
int m=strlen(s.p);
int n=strlen(t.p);

if(m<=n) { return 1;}
else return 0;

}
void display(const String s)
{
    cout<<s.p<<endl;
}


int main(){
String s1="Prateek";
String s2="Narang";
String s3=s1+s2;
String string1,string2,string3;

string1=s1;
string2=s2;
string3=s1+s2;
display(s1);
display(s2);
display(s3);

if(string1.len<=string3.len){ display(s3);cout<<" is greater ";}
else { cout<<"Smaller";}

return 0;
}
