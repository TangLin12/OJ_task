#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
  
struct Vertex
{
    int x;
    int y;
};
Vertex ver[107];
  
bool cmp(Vertex ver1, Vertex ver2)
{
    int x1,x2,y1,y2,s;
    x1 = ver1.x-ver[0].x;
    y1 = ver1.y-ver[0].y;
    x2 = ver2.x-ver[0].x;
    y2 = ver2.y-ver[0].y;
    s = x1*y2 - x2*y1;
    if(s>0 || s==0 && x1*x1+y1*y1>x2*x2+y2*y2)
        return true;
    else
        return false;
}
  
inline int dig(int x0, int y0, int x1, int y1, int x2, int y2)
{
    return (x2 - x0) * (y1 - y0) - (y2 - y0) * (x1 - x0);
}
  
  
void Swap(Vertex &ver1, Vertex &ver2)
{
    Vertex temp;
    temp.x = ver1.x;
    temp.y = ver1.y;
    ver1.x = ver2.x;
    ver1.y = ver2.y;
    ver2.x = temp.x;
    ver2.y = temp.y;
}
  
int main()
{
    double s,m;
    int t,p,n,i,k,a,b;
    int StackVer[107];
    int pVer;
    int MinY;
    cin>>t;
    for (p=0; p<t; p++)
    {
        cin>>n;
        for (i=0; i<n; i++)
            cin>>ver[i].x>>ver[i].y;
        if(n<=2) 
        {
            cout<<"0.0"<<endl;
            continue;
        }
        s=0;
        pVer=0;
        MinY = 0;
        for (i=1; i<n; i++)
        {
            if (ver[i].y<ver[MinY].y || ver[i].y==ver[MinY].y&&ver[i].x<ver[MinY].x)
            {
                MinY = i;
            }
        }
  
        Swap(ver[0],ver[MinY]);
        sort(ver+1,ver+n, cmp);
        k=2;
  
        for(i=2; i<n; i++)
        {
            if(dig(ver[0].x, ver[0].y, ver[i-1].x,ver[i-1].y, ver[i].x, ver[i].y) != 0)
                ver[k++] = ver[i];
        }
  
        StackVer[pVer++] = 0;
        StackVer[pVer++] = 1;
        StackVer[pVer++] = 2;
  
  
        for(i = 3; i < k; i++) 
        {
            for(a = StackVer[pVer - 2], b = StackVer[pVer - 1];
                ! (dig(ver[a].x, ver[a].y, ver[b].x, ver[b].y, ver[i].x, ver[i].y)< 0);
                a = StackVer[pVer - 2], b = StackVer[pVer - 1]) 
            {
                pVer--;  
            }
            StackVer[pVer++] = i;  
        }
  
        while(pVer>=2)
        {
            a = StackVer[pVer - 2];
            b = StackVer[pVer - 1];
            m = dig( ver[0].x, ver[0].y,ver[b].x, ver[b].y,ver[a].x, ver[a].y)/2.0;
            if(m<0) m=-m;
            pVer--;
            s=s+m;
        }
        cout<<setiosflags(ios::fixed)<<setprecision(1)<<s<<endl;   
    }
    return 0;
}