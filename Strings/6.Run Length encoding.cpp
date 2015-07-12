#include<iostream>
#include<cstring>
using namespace std;


char* compressString(char *s){
    char dest[100];
    int j=0;
    int freq[100];

    for(int i=0;i<strlen(s);i++){
        char current = s[i];
        dest[j++]=s[i];
        //cout<<dest[j-1];
        int count=1;

        while(i+1<strlen(s)&&s[i+1]==current){
            count++;
            i++;
        }
        freq[j-1]=count;

    }
dest[j]='\0';
for(int i=0;i<strlen(dest);i++)
    cout<<dest[i]<<freq[i];


cout<<endl;
return dest;
}


int main(){
char a[]=  "wwwwaaadexxxxxx" ;

char *dest = compressString(a);
for(int i=0;i<strlen(dest);i++){
    cout<<dest[i];
}
return 0;
}
