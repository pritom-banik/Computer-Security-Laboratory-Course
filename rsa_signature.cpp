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
    ll ps,qs,pr,qr;

    cout<<"Give senders p and q : ";
    cin>>ps>>qs;

    cout<<"Give receicers's p and q : ";
    cin>>pr>>qr;


    ll ns=ps*qs;
    ll phis=(ps-1)*(qs-1);

    ll nr=pr*qr;
    ll phir=(pr-1)*(qr-1);

    ll er,es;

    for(ll i=10;i<phis;i++){
        if(__gcd(i,phis)==1){
            es=i;
            break;
        }
    }

    for(ll i=10;i<phir;i++){
        if(__gcd(i,phir)==1){
            er=i;
            break;
        }
    }

    ll ds=mod_inv(es,phis);

    ll dr=mod_inv(er,phir);

    if(ds==-1||dr==-1){
        cout<<"No private key found"<<endl;
        return 0;
    }


    ll m;
    cout<<"Enter msg : ";
    cin>>m;

    ll h=mod_pow(m,er,nr);
    ll sig=mod_pow(h,ds,ns);

    cout<<"Hash : "<<h<<" signature : "<<sig<<endl;

    ll verify=mod_pow(sig,es,ns);
    ll msg=mod_pow(verify,dr,nr);

    cout<<"Verify : "<<verify<<" decr msg : "<<msg<<endl;

    return 0;
}
