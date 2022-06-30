
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,w;
};
int parent[2000];
bool comp(node a,node b)
{
    if(a.w<b.w)return true;
    else return false;
}
int findd(int a)
{
    if(parent[a]==a)return a;
    else return parent[a]=findd(parent[a]);
}
void unionn(int a,int b)
{
    parent[a]=b;
}
int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int n;
        cin>>n;
        int weak;
        cin>>weak;
        printf("Case %d:\n",k);
        struct node ar[2000];
        int cnt=0;
        for(int i=1; i<=weak; i++)
        {
            int a,b,c;
            cin>>ar[cnt].a>>ar[cnt].b>>ar[cnt].w;
            cnt++;
            int temp=cnt;
            cnt=0;
            long long sum=0;
            sort(ar,ar+temp,comp);
            for(int j=1; j<=n; j++)parent[j]=j;
            for(int j=0; j<temp; j++)
            {
                int u=findd(ar[j].a);
                int v=findd(ar[j].b);
                if(u!=v)
                {
                    sum+=ar[j].w;
                    unionn(u,v);
                    ar[cnt].a=ar[j].a;
                    ar[cnt].b=ar[j].b;
                    ar[cnt].w=ar[j].w;
                    cnt++;
                }

            }
            int num=0;
            for(int j=1; j<=n; j++)
            {
                if(parent[j]==j)num++;
            }
            if(num>1)
                cout<<-1<<endl;
            else cout<<sum<<endl;
        }
    }
}
