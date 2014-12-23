#include<iostream>
using namespace std;

int main(){
char ch,nextchar , prevchar;
ch = cin.get();
while(ch!=EOF){
    if(ch=='/'){
        nextchar = cin.get();
        if(nextchar=='/'){
            while((ch=cin.get()!='n')&&ch!=EOF);

        }else if(nextchar == '*'){
          ch = cin.get();
          nextchar = cin.get();
          while(ch!='*'&&nextchar!='/'){
            ch = nextchar;
            nextchar = cin.get();
          }

        }
       else{
        cout<<ch<<nextchar;
       }
        continue;
     }
    cout<<ch;

}

return 0;
}
