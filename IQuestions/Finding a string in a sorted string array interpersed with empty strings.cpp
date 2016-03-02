#include<iostream>
#include<cstring>
using namespace std;

/* This works Good very Good */


int searchRecursive(string*s,string key,int low,int high){
if(high<low){
    return -1;
}
int mid = (low+high)/2;
if( s[mid]==""){
    int premid = mid-1;
    int postmid = mid+1;

    while(1){

 if(premid<low && postmid>high){
        return -1;
    }
    else if(premid>=low && s[premid]!=""){
        mid = premid;
        break;
    }
    else if(postmid<=high && s[postmid]!=""){
        mid = postmid;
        break;
    }
    premid--;
    postmid++;
    }
}


if(s[mid]==key){
    return mid;
}
else if(key.compare(s[mid])>0){
//Key is greater than mid.
return searchRecursive(s,key,mid+1,high);
}
else{
    return searchRecursive(s,key,low,mid-1);
}


}


int main(){

string s[]= { "aloo","","","","aloobukhara","","baat","ball","","","","cat","catrina","dog","tree"};
int n=sizeof(s)/sizeof(string);

cout<<searchRecursive(s,"aloobukhara",0,n-1)<<endl;

cout<<searchRecursive(s,"catrina",0,n-1)<<endl;
//string s1= "aloo";
//cout<<s1.compare("alob");
// +ve value means bracket vala chota.
// 0 means equal.

return 0;
}
