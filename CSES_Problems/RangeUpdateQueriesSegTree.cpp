#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll n;
vector<ll> t;

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
       // cout<<v<<":  "<<t[v]<<" ";
    } else {
        ll tm = (tl + tr) / 2;
       // cout<<tm<<" ";
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        t[v] = t[v*2+1]+t[v*2+2];
       
    }
    // cout<<v<<":  "<<t[v]<<" ";
}

ll querie(ll v, ll tl, ll tr, ll l, ll r) {
    //outside the range
    if(r<tl || tr<l)
    return 0;
    //inside the range
    if(l<=tl && tr<=r)
    return t[v];
    //partially present in range
    ll tm=(tl+tr)/2;
     ll p1=querie(v*2+1, tl, tm, l,r);
     ll p2=querie(v*2+2, tm+1, tr, l, r);
     return p1+p2;

   
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v]+= new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, pos, new_val);
        else
            update(v*2+2, tm+1, tr, pos, new_val);
        t[v] = t[v*2+1] + t[v*2+2];
    }
}

int main(){
  cin>>n;
  ll q;
  cin>>q;
  ll b[n];
  for(ll i=0;i<n;i++)
  {   
     cin>>b[i];
  }
  ll a[n];
  a[0]=b[0];
  for(int i=1;i<n;i++)
   a[i]=b[i]-b[i-1];

  t.resize(4*n+1,0);
  build(a,0,0,n-1);
 
  while (q--){
      ll p,l,r,u;
      cin>>p;
      if(p==1){
          cin>>l>>r>>u;
          update(0,0,n-1,l-1,u);
          if(r<n)
          update(0,0,n-1,r,-u);
      }
      else
      {   cin>>l;
          ll ans=querie(0, 0, n-1, 0, l-1);
      cout<<ans<<"\n";}
  }
  
  

    return 0;
}
