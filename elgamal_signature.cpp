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
    cout<<"ElGamal Signature"<<endl;

    ll p=467,x=3,g=127;
    ll y=mod_pow(g,x,p);

    cout<<"y : "<<y<<endl;

    ll m;
    cout<<"Enter msg : ";
    cin>>m;

    ll k;
    cout<<"Enter a random number less than (p-1) and coprime with p-1 : ";
    cin>>k;

    if(__gcd(k,p-1)!=1){
        cout<<"Not prime";
        return 0;
    }

    ll r=mod_pow(g,k,p);

    ll kinv=mod_inv(k,p-1);

    ll s=mod_pow(kinv*((m-r*x)%(p-1)),1,p-1);

    if(s<0){
        s+=(p-1);
    }


    cout<<"(r,s) : "<<r<<" "<<s<<endl;

    ll v1=mod_pow(g,m,p);
    ll temp=mod_pow(y,r,p)*mod_pow(r,s,p);
    ll v2=mod_pow(temp,1,p);

    cout<<"v1 v2 :"<<v1<<" "<<v2<<endl;

    return 0;
}
