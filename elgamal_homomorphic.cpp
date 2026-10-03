#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct Point{
    ll x,y;
    bool inf;
};

ll mod(ll a,ll m){
    a%=m;
    if(a<0){
        a+=m;
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

    if(P.x==Q.x&&(mod(P.y+Q.y,p)==0)){
        return {0,0,true};
    }

    ll lembda;

    if(P.x==Q.x && P.y==Q.y){
        lembda=mod((3*P.x*P.x+a)*mod_inv(2*P.y,p),p);
    }else{
        lembda=mod((Q.y-P.y)*mod_inv(Q.x-P.x,p),p);
    }

    ll x3=mod(lembda*lembda-P.x-Q.x,p);
    ll y3=mod(lembda*(P.x-x3)-P.y,p);

    return {x3,y3,false};
}


Point multiply(Point P,ll e,ll a,ll p){
    Point R={0,0,true};

    while(e){
        if(e&1){
            R=add(R,P,a,p);
        }

        P=add(P,P,a,p);
        e>>=1;
    }
    return R;
}

void printp(Point P){
    cout<<"("<<P.x<<" "<<P.y<<")"<<endl;
}


int main(){
 ll p=97,a=7,b=1;
 Point G={3,7,false};
 ll x=13;
 Point Q=multiply(G,x,a,p);

 cout<<" Q : ";
 printp(Q);

 Point m1=multiply(G, 5, a, p);

 ll k1=43;

 Point c11=multiply(G,k1,a,p);
 Point KQ=multiply(Q,k1,a,p);
 Point c12=add(m1,KQ,a,p);

 cout<<"c11 c12 : "<<endl;
 printp(c11);
 printp(c12);

 Point m2=multiply(G, 7, a, p);

 ll k2=41;

 Point c21=multiply(G,k2,a,p);
 Point KQ2=multiply(Q,k2,a,p);
 Point c22=add(m2,KQ2,a,p);

 cout<<"c21 c22 : "<<endl;
 printp(c21);
 printp(c22);


 Point c1=add(c11,c21,a,p);
 Point c2=add(c12,c22,a,p);

cout<<"c1 c2 : "<<endl;
 printp(c1);
 printp(c2);

 Point dc1=multiply(c1,x,a,p);
 Point invdc1={dc1.x,mod(-dc1.y,p),dc1.inf};
 Point msgsum=add(c2,invdc1,a,p);

 cout<<"Decrypted msg : "<<endl;
 printp(msgsum);

 cout<<"Actual : "<<endl;
 printp(add(m1,m2,a,p));

 return 0;

}
