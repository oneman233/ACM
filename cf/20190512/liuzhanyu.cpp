#include<bits/stdc++.h>
#define $$ long long int
#define pb push_back
#define db pop_back
#define q2(n) (n%2)==0
#define vp vector<pair <$$,$$> >
#define vctr vector<$$>
#define in(a) scanf("%lld",&a)
#define out(a) printf("%lld ",a)
#define loop(i,m,p) for ($$ i = m; i < p; ++i)
#define loopn(i,m,p) for ($$ i = p-1; i >=m; --i)

using namespace std;

int main()
{
  $$ n,m,sum=0;
  in(n);
  in(m);
  $$ b[n],g[m];
  loop(i,0,n) in(b[i]);
  loop(i,0,m) in(g[i]);
  sort(b,b+n);
  sort(g,g+m);
  if(b[n-1]>g[0])
    cout<<"-1\n";
  else
  {


//  if (n>=m)
//  {
//    $$ k=n-m;
//    loop(i,0,k)
//    {
//      sum+=(b[i]*m);
//    }
//    loop(i,k,n)
//    {
//      sum+=(b[i]*(m-1));
//    }
//    loop(i,0,m) sum+=g[i];
//  }
//  else
//  {
      $$ flag=0;
      loop(i,0,m)
      {
          if(b[n-1]==g[i]) flag=1;
      }
      if(flag==1)
      {
         loop(i,0,n-1)
          {
                  sum+=(b[i]*m);
          }

      loop(i,0,m) sum+=g[i];

      }
      else
      {
          loop(i,0,n-2)
          {
                  sum+=(b[i]*m);
          }
           sum+=(b[n-2]*(m-1));
            sum+=b[n-1];
             loop(i,0,m) sum+=g[i];

      }



  cout<<sum<<endl;
  }


  return 0;

}
