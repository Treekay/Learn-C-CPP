#include<stdio.h>
int a[20];
int cnt;
int i;
void cc(int n)
{
    cnt=0;
    while(n)
    {
        a[cnt++]=n%10;
        n/=10;
    }
    for(i=0;i<cnt;i++)
    {
        if(a[i]>=9)a[i]-=2;
        else if(a[i]>=4)a[i]-=1;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        cc(n);
        int ans=0;
        for(i=cnt-1;i>=0;i--)
        {
            ans*=8;
            ans+=a[i];
        }
        printf("%d: %d\n",n,ans);
    }
    return 0;
}