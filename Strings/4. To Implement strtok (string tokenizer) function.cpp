#include<iostream>
using namespace std;

/*
On a first call, the function expects a C string as argument for str, whose first character is used as the starting
location to scan for tokens. In subsequent calls, the function expects a null pointer and uses the position right after
the end of the last token as the new starting location for scanning.  - http://www.cplusplus.com/reference/cstring/strtok/
*/

char * strtok ( char * str, const char delimiters ){
static int pos ;
static char *s;

//Copy the string for further call backs
if(str!=NULL)
    s=str;

int i=0;
int start = pos ; //Static variables are initialsied with 0.

while(s[pos]!='\0'){

    if(s[pos]==delimiters){
        s[pos]='\0';
        pos = pos+1;

        if(s[start]!=NULL){
            return (&s[start]);
            }
        else{
        //Update Start
            start = pos;
            //Decrement as position is incremented at the end of while.
            pos--;
            break;
      }
    }
    pos++;
}
s[pos]='\0';
if(s[start]==NULL)
    return NULL;
else
    return &s[start];
}

int main(){
char str[] ="Narendra Modi's Make in India is a huge success.";
char *ptr;
ptr = strtok(str,' '); //First call with str , Subsequent calls with NULL

while(ptr!=NULL){
 cout<<ptr;
 cout<<endl;
 ptr = strtok(NULL,' ');
}

return 0;
}
