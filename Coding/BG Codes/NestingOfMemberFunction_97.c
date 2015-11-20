// Checking a Binary No

#include<conio.h>
#include<string.h>
using namespace std;

class binary{
string s;

public:
    void getData(void){
    cout<<"Enter a Binary Number : ";
    cin>>s;
    }

    void checkData(void)
    {
        for(int i=0;i<s.length();i++){
            if(s.at(i)!=0&&s.at(i)!=1){
                cout<<"Incorrrect Binary Format ! Program will Quit";
                getch();
                exit(0);

            }  //if end

        }//for
    } //function end


  void convert(void){
  void checkData();
  for(int i=0;i<s.length;i++){
    if(s.at[i]=0)
        s.at[i]=1;
    else
        s.at[i]=0;
  }

  }

  void display(void){
  cout<<"The one's compliment is : "<<s;

  }

}


int main(){
binary b;
b.getData();
b.convert();
b.display();

getch();
return 0;

}
