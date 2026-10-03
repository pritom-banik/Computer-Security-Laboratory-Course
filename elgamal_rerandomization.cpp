#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll mod_pow(ll a,ll e,ll m){
    ll r=1;
    a%=m;

    while(e){
        if(e&1){
            r=(__int128)r*a%m;
        }
        a=(__int128)a*a%m;
        e>>=1;
    }
    return r;
}

ll egcd(ll a,ll b,ll &x,ll &y){
    if(b<=0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g=egcd(b,a%b,x1,y1);


    x=y1;
    y=x1-(a/b)*y1;
    return g;
}


ll mod_inv(ll a,ll m){
    ll x,y;
    ll g=egcd(a,m,x,y);

    if(g!=1){
        return -1;
    }

    x%=m;
    if(x<0){
        x+=m;
    }
    return x;
}


int main(){
    cout<<"ElGamal Re-randomization"<<endl;

    ll p=181,x=3,g=97;

    ll y=mod_pow(g,x,p);

    cout<<"y = "<<y<<endl;

    ll m;
    cout<<"Enter msg : ";
    cin>>m;

    ll k=44;

    ll c1=mod_pow(g,k,p);
    ll c2=mod_pow(m*mod_pow(y,k,p),1,p);

    cout<<"Original (c1,c2) : "<<c1<<" "<<c2<<endl;

    ll r=52;

    ll c1_new=mod_pow(c1*mod_pow(g,r,p),1,p);
    ll c2_new=mod_pow(c2*mod_pow(y,r,p),1,p);

    cout<<"New (c1,c2) : "<<c1_new<<" "<<c2_new<<endl;

    ll s=mod_pow(c1_new,x,p);
    ll sinv=mod_inv(s,p);
    ll msg=mod_pow(c2_new*sinv,1,p);

    cout<<"Msg : "<<msg<<endl;
}
