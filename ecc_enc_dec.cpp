#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct Point{
ll x,y;
bool inf;
};

ll mod(ll a,ll p){
    a%=p;
    if(a<0){
        a+=p;
    }
    return a;
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

ll mod_inv(ll a,ll p){
    return mod_pow(a,p-2,p);
}

Point add(Point P,Point Q,ll a,ll p){
    if(P.inf){
        return Q;
    }
    if(Q.inf){
        return P;
    }

    if(P.x==Q.x&&mod(P.y+Q.y,p)==0){
        return {0,0,true};
    }

    ll lembda;

    if(P.x==Q.x&&P.y==Q.y){
        lembda=mod((3*P.x*P.x+a)*mod_inv(2*P.y,p),p);
    }else{
        lembda=mod((Q.y-P.y)*mod_inv(Q.x-P.x,p),p);
    }

    ll x3=mod(lembda*lembda-P.x-Q.x,p);
    ll y3=mod(lembda*(P.x-x3)-P.y,p);

    return {x3,y3,false};
}

Point multiply(Point P,ll k,ll a,ll p){
    Point R={0,0,true};

    while(k){
        if(k&1){
            R=add(R,P,a,p);
        }

        P=add(P,P,a,p);
        k>>=1;
    }
    return R;
}

void PrintP(Point P){
cout<<"Point : "<<P.x<<" "<<P.y<<endl;
}


int main(){
    ll p=97,a=7,b=1;

    Point G={3,7,false};

    ll x=13;

    Point publickey=multiply(G,x,a,p);

    cout<<"Public key is : ";

    PrintP(publickey);

    Point m={8,20,false};



    ll k=45;
    Point c1=multiply(G,k,a,p);
    Point KQ=multiply(publickey,k,a,p);
    Point c2=add(m,KQ,a,p);

    cout<<"c1 c2 : "<<endl;
    PrintP(c1);
    PrintP(c2);


    Point dc=multiply(c1,x,a,p);
    Point negdc={dc.x,mod(-dc.y,p),dc.inf};

    Point msg=add(c2,negdc,a,p);

    cout<<"Dec msg : ";
    PrintP(msg);


    return 0;
}
