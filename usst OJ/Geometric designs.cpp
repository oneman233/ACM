#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double x[105],y[105];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    double ans=1e+9;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //选了两个点（xi，yi）和（xj，yj）
            if(fabs(x[i]-x[j])<=1e-8)
            {
                for(int l=0;l<n;l++)
                {
                    if(l!=i&&l!=j)
                        ans=min(ans,fabs(x[l]-x[i])/2.0);
                }
            }
            /*斜率不存在*/
            else
            {
                double k=(y[i]-y[j])/(x[i]-x[j]);
                double b=y[i]-k*x[i];
                //y=kx+b
                for(int l=0;l<n;l++)
                {
                    if(l!=i&&l!=j)
                        ans=min(ans,(fabs(k*x[l]-y[l]+b)/sqrt(k*k+1))/2.0);
                }
            }
            /*斜率存在*/
        }
    }
    printf("%.6lf",ans);
    return 0;
}
