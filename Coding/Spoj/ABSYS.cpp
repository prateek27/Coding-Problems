#include<iostream>
#include<cstring>
using namespace std;

int toint(char a[100]){

int len=strlen(a);

int ans=0;
    for(int i=0;i<len;i++){
        ans = 10*ans + a[i]-'0';
        }

    return ans;
}

int main(){
int t;
cin>>t;
char s1[100],op1[2],s2[100],op2[2],s3[100];
const char* s = "machula";

while(t--){
    cin>>s1>>op1>>s2>>op2>>s3;

    if(strstr(s1,s)!=NULL){
        int y = toint(s2);
        int z = toint(s3);
        int x = z-y;
        cout<<x<<" + "<<y<<" = "<<z<<endl;
    }
    else if(strstr(s2,s)!=NULL){
        int x = toint(s1);
        int z = toint(s3);
        int y = z-x;
        cout<<x<<" + "<<y<<" = "<<z<<endl;
    }
    else if(strstr(s3,s)!=NULL){
        int x = toint(s1);
        int y = toint(s2);
        int z = x+y;
        cout<<x<<" + "<<y<<" = "<<z<<endl;
    }
}

return 0;
}
