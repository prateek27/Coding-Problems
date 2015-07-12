#include<iostream>
#include<string>
using namespace std;




void generateStrings(int range,int index,int subindex,buffer,vector<char> &vc,vector<string>&result){

    if(index==range){
        buffer[index]='\0';
        string str(buffer);
        cout<<str;
        result.push_back(str);
    }
    vector<char>::iterator it;
    for(it=)


return ;
}

void generateStringHelper(vector<char> &vc,int range){
vector<string> result;
char *buffer[5];
generateStrings(range,0,-1,buffer,vc,result)

}




vector<char> makeKeypad(int *range){
//Push 3 alphabets for each number starting from
// 2 -abc, 3-def,....
vector<char> *v = new vector<char>[range+1];
char ch='a';

for(int i=2;i<=range;i++){
    for(int char_count =0;char_count<3;char_count++){
        *v[i].push_back(ch++);
    }
}

return *v;
}


int main(){
vector<char> v = makeKeypad(5);
vector<string> result ;
int *a={2,3,4};
generateStrings(v,a,result);
printStrings(result);

return 0;
}
