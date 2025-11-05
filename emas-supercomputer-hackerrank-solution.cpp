#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int g[r][c];
    char t;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>t;
            if(t=='G')
                g[i][j]=0;
            else
                g[i][j]=-1;
        }
    }
    int temp,min,a;
    vector<vector<int>> v;
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(g[i][j]!=-1)
            {
                min=100;
                temp=0;
                for(a=i+1;a<r;a++)
                {
                    if(g[a][j]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                temp=0;
                for(a=i-1;a>=0;a--)
                {
                    if(g[a][j]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                temp=0;
                for(a=j+1;a<c;a++)
                {
                    if(g[i][a]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                temp=0;
                for(a=j-1;a>=0;a--)
                {
                    if(g[i][a]==-1)
                        break;
                    else
                        temp+=1;
                }
                if(temp<min)
                    min=temp;
                g[i][j]=min;
            }
            if(g[i][j]>0)
                v.push_back(vector<int>{i,j});
        }
    }
    int j;
    if(v.size()==0)
    {
        cout<<1;
    }
    else if(v.size()==1)
    {
        int n=g[v[0][0]][v[0][1]];
        cout<<1+n*4;
    }
    else
    {
        int q=1;
        int area=1;
        for(int i=0;i<v.size();i++)
        {
            area=1;
            int h[r][c];
            memcpy(h,g,sizeof(g));
            h[v[i][0]][v[i][1]]=-1;
            int n=g[v[i][0]][v[i][1]];
            for(int y=1;y<n+1;y++)
            {   h[v[i][0]+y][v[i][1]]=-1;
                h[v[i][0]-y][v[i][1]]=-1;
                h[v[i][0]][v[i][1]+y]=-1;
                h[v[i][0]][v[i][1]-y]=-1;
            int m;
            for(j=0;j<v.size();j++)
            {
                int flag=0;
                if(j!=i)
                {
                    m=g[v[j][0]][v[j][1]];
                    for(int k=1;k<m+1;k++)
                    {
                        if(h[v[j][0]+k][v[j][1]]==-1)
                        {
                            m=k-1;
                            break;
                        }
                    }
                        for(int k=1;k<m+1;k++)
                        {
                            if(h[v[j][0]-k][v[j][1]]==-1)
                            {
                                m=k-1;
                                break;
                            }
                        }
                        for(int k=1;k<m+1;k++)
                        {
                            if(h[v[j][0]][v[j][1]+k]==-1)
                            {
                                m=k-1;
                                break;
                            }
                        }
                        for(int k=1;k<m+1;k++)
                        {
                            if(h[v[j][0]][v[j][1]-k]==-1)
                            {
                                m=k-1;
                                break;
                            }
                        }
                    if((1+y*4)>area)
                        area=(1+y*4);
                    if((1+y*4)*(1+m*4) > area)
                    {
                        area=(1+y*4)*(1+m*4);
                    }
                }
                }
            }
            if(area>q)
                q=area;
        }
        cout<<q;
    }
    return 0;
}

