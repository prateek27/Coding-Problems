
#include<stdio.h>
int check(int *a,int *b,int *c,int *ar){
int in,cou=0;
for(in=*a-1;in<=*b-1;in++){
    if(ar[in]%*c==0)
cou++;
}

printf("%d",cou);


}
int main(){
int co=0,n,q,i,j,b,d,c;
scanf("%d %d",&n,&q);
int a[n];
for(i=0;i<n;i++){

    scanf("%d",&a[i]);
}
for(j=0;j<q;j++){

    scanf("%d %d %d",&b,&c,&d);
    check(&b,&c,&d,a);

}


return 0;
}

