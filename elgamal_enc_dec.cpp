#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll mul_mod(ll a,ll b,ll m){
    return (ll)((__int128)a*b%m);
}

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
    cout<<"ElGamal Enc Dec"<<endl;
    ll p=97;
    ll x=3;
    ll g=83;
    ll y=mod_pow(g,x,p);

    cout<<" P : "<<p<<" x : "<<x<<" g : "<<g<<" y : "<<y<<endl;

    ll m;
    cout<<"Give msg : ";
    cin>>m;

    ll k=57;

    ll c1=mod_pow(g,k,p);
    ll temp=mod_pow(y,k,p);
    ll c2=mod_pow(m*temp,1,p);

    cout<<"c1 : "<<c1<<" c2 : "<<c2<<endl;


    ll s=mod_pow(c1,x,p);
    ll inv_s=mod_inv(s,p);
    ll msg=mod_pow(c2*inv_s,1,p);

    cout<<"s : "<<s<<" s-1 : "<<inv_s<<endl;

    cout<<"msg : "<<msg<<endl;
}
