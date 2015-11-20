#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
    char str[101][101];
    char str1[101];
    int fre[101][101];
    int t,k,n,i,f,j;
    ifstream f1("input.txt");
    ofstream f2("archit.txt");
    f1>>t;
    for(k=1;k<=t;++k)
    {
        f=1;
        for(i=0;i<=100;++i)
        {

            for(j=0;j<=100;++j)
            {

                fre[i][j]=0;
            }
        }
        cout<<"Case #"<<k<<": ";
        int n;
        f1>>n;
        for(i=1;i<=n;++i)
            f1>>str[i];
            int ct;

        ct=0;
        str1[ct]=str[1][0];
        fre[1][ct]++;

        for(i=1;i<strlen(str[1]);++i)
        {
            if(str[1][i]!=str[1][i-1])
            {
                ct++;
                str1[ct]=str[1][i];

                fre[1][ct]++;
            }
            else{
                fre[1][ct]++;
            }
        }
        for(i=2;i<=n;++i)
        {
            ct=0;
            if(str[i][0]!=str1[0])
            {
                f=0;
                break;
            }
            else{
                    fre[i][ct]++;

            }
            for(j=1;j<strlen(str[i]);++j)
            {
                if(str[i][j]!=str[i][j-1])
                {
                    ct++;
                    if(str[i][j]!=str1[ct])
                    {
                        f=0;
                        break;
                    }
                    else
                    fre[i][ct]++;
                }
               else{
                fre[i][ct]++;
                 }
            }
        }
            if(f==0)
                f2<<"Fegla Won\n";
            else{
                int len=strlen(str1);
                int ans=0;

                int tmp;
                for(i=0;i<len;++i)
                {
                    tmp=0;
                    for(j=1;j<=n;++j)
                    {
                       tmp=tmp+fre[j][i];
                    }
                    if(tmp%n==0)
                    {
                        tmp=tmp/n;
                        int ans1=0;
                        for(j=1;j<=n;++j)
                       {
                       ans1=ans1+abs(tmp-fre[j][i]);
                        }
                        ans=ans+ans1;
                    }
                    else{
                        int tmp1,tmp2;
                        int ans1,ans2;
                        ans1=ans2=0;
                        tmp1=tmp/n;
                        tmp2=tmp1+1;
                        for(j=1;j<=n;++j)
                       {
                       ans1=ans1+abs(tmp1-fre[j][i]);
                        }
                        for(j=1;j<=n;++j)
                       {
                       ans2=ans2+abs(tmp2-fre[j][i]);
                        }
                        ans=ans+min(ans1,ans2);
                    }
                }
                f2<<ans<<endl;
            }


    }
    return 0;
}
