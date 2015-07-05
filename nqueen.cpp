#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)


using namespace std;

int a[505][505],x[505];
vector<int>v;

bool safe(int n,int c,int r)
{
    int i,j;

    // check current column
    for(i=r;i<=n;i++)
    if(a[i][c]==1)
        return false;

    for(i=1;i<r;i++)
        if(a[i][c]==1)
        return false;

    // upper diagonal
    for(i=r,j=c;i<=n,j<=n;i++,j++)
    {
        if(a[i][j]==1)
            return false;
    }
    for(i=r,j=c;i>0,j>0;i--,j--)
    {
        if(a[i][j]==1)
            return false;
    }
    for(i=r,j=c;i<=n,j>0;i++,j--)
    {
        if(a[i][j]==1)
            return false;
    }
    for(i=r,j=c;i>0,j<=n;i--,j++)
    {
        if(a[i][j]==1)
            return false;
    }
    return true;
}

bool solve(int n,int r)
{
    if(r>n)
        return true;
    if(x[r]!=0)
        return solve(n,r+1);
    for(int i=1;i<=n;i++)
    {
        if(safe(n,i,r)==true)
        {
            a[r][i]=1;
            if(solve(n,r+1)==true)
                return true;

            a[r][i]=0;
        }
    }
    return false;
}

int main()
{
    int i,t,n,j;
    while(cin>>n)
    {
        v.clear();
        rep(i,1,n+1)
        rep(j,1,n+1)
        a[i][j]=0;
        rep(i,1,n+1)
        {
            cin>>x[i];
            if(x[i]!=0)
                a[i][x[i]]=1;
        }
        solve(n,1);
            rep(i,1,n+1)
            {
                rep(j,1,n+1)
                {
                    if(a[i][j]==1)
                    {
                        v.push_back(j);
                        break;
                    }
                }
            }

            rep(i,0,v.size())
            cout<<v[i]<<" ";
            cout<<endl;
    }
    return 0;
}
