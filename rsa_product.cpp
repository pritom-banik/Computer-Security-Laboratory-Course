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
    cout<<"RSA"<<endl;

    ll p,q;

    cout<<"Give p and q : ";

    cin>>p>>q;

    ll n=p*q;
    ll phi=(p-1)*(q-1);

    ll e;

    for(ll i=11;i<phi;i++){
        if(__gcd(i,phi)==1){
            e=i;
            break;
        }
    }

    ll d=mod_inv(e,phi);

    if(d==-1){
        cout<<"No d found !"<<endl;
        return 0;
    }

    ll m1,m2;

    cout<<"Give two msg : ";
    cin>>m1>>m2;


    ll c1=mod_pow(m1,e,n);
    ll c2=mod_pow(m2,e,n);

    cout<<"c1 : "<<c1<<"  c2: "<<c2<<endl;

    ll c=mul_mod(c1,c2,n);

    cout<<"c : "<<c<<endl;

    ll d1=mod_pow(c1,d,n);
    ll d2=mod_pow(c2,d,n);

    ll dm=mod_pow(c,d,n);

    cout<<"d1 : "<<d1<<" d2 : "<<d2<<endl;
    cout<<"dm : "<<dm<<endl;
    return 0;
}
