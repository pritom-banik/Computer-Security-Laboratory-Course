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
    cout<<"ElGamal Product Cipher"<<endl;

    ll p=467,x=2,g=123;

    ll y=mod_pow(g,x,p);

    cout<<"Public key(g,y,p) : "<<g<<" "<<y<<" "<<p<<endl;

    ll m1,m2;

    cout<<"Give two msg : ";
    cin>>m1>>m2;


    ll k1,k2;

    cout<<"give two random number : ";
    cin>>k1>>k2;

    ll c11=mod_pow(g,k1,p);
    ll temp1=mod_pow(y,k1,p);
    ll c12=mod_pow(m1*temp1,1,p);

    ll c21=mod_pow(g,k2,p);
    ll temp2=mod_pow(y,k2,p);
    ll c22=mod_pow(m2*temp2,1,p);


    cout<<"c11 c12 : "<<c11<<" "<<c12<<endl;
    cout<<"c21 c22 : "<<c21<<" "<<c22<<endl;

    ll c1=mod_pow(c11*c21,1,p);
    ll c2=mod_pow(c12*c22,1,p);

    cout<<"c1 : "<<c1<<" c2 : "<<c2<<endl;



    ll s=mod_pow(c1,x,p);
    ll sinv=mod_inv(s,p);
    ll m1m2=mod_pow(c2*sinv,1,p);

    cout<<"m1 * m2 = "<<m1m2<<endl;
}
