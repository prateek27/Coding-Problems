#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int i;

    string input;
    string letter;

    cout<<"Enter a string in lowercase ";
    cin>>input;
    int freq[26];
    for(i=0;i<26;i++){
        freq[i]=0;
    }

    for(i=0;i<input.size();i++)
    {
        freq[toascii(input[i])-97]++ ;
    }

    int maxOccuring= -1;
    for(i=0;i<input.size();i++){
    cout<<input[i]<<freq[toascii(input[i])-97];

    if(freq[toascii((input[i]-1)-97)>=maxOccuring])
        { maxOccuring=freq[toascii(input[i]-97)];
          letter=input[i];
        }
    }
    cout<<endl<<"Max Occuring letter is "<<letter<<" and it occurs "<<maxOccuring<<"Times ";



return 0;
}

