#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Point{
	ld x,y;
	
	Point(): x(0.0),y(0.0)
	{
	}
	
	Point(ld a,ld b): x(a) , y(b)
	{
	}
	 
	
	
};

struct Vecteur{
	ld x,y;
	
	Vecteur() : x(0.0), y(0.0)
	{
	}
	
	Vecteur(ld a,ld b) : x(a), y(b)
	{ 
	}
	
	
};

Vecteur operator +(Vecteur u,Vecteur v){
	return Vecteur(u.x+v.x,u.y+v.y);
}
ld norme(Vecteur u){
	return sqrt(u.x*u.x+u.y*u.y);
}

Vecteur normalise(Vecteur u){
	return Vecteur(u.x/norme(u),u.y/norme(u));
}

Vecteur orthogonal(Vecteur u){
	return Vecteur(-u.y,u.x);
}

ld ps(Vecteur u,Vecteur v){
	return u.x*v.x+u.y*v.y;
}

Vecteur MultScalaire(Vecteur u,ld lambda){
	return Vecteur(u.x*lambda,u.y*lambda);
}

Vecteur copier(Vecteur u){
	return Vecteur(u.x,u.y);
}

Vecteur creer(Point p,Point q){
	return Vecteur(q.x-p.x,q.y-p.y);
}

Point copier(Point p){
	return Point(p.x,p.y);
}
ld carre(ld x){
	return x*x;
}
	
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    Point p=Point(0.0,10.1),q=Point(1.4,-9.6);
    ld m=(-9.6-10.1)/1.4,b=10.1,delta;
    delta=carre(2*m*b)-4*(carre(b)-100)*(4+carre(m));
    p.x=(-2*m*b-sqrt(delta))/(2*(4+carre(m)));
    p.y=m*p.x+b;
    Vecteur u=creer(p,q),v,n,n2;
    int reflexion=-1;
    //cout << m << ' ' << b << ' ' << delta << ' ' <<  p.x << ' ' << p.y << '\n';
    while(reflexion==-1 || !( -0.01<=p.x and p.x<=0.01 and p.y>0) ){
		cout << p.x << ' ' << p.y << endl;
		cout << 4*p.x*p.x+p.y*p.y-100.0 << endl;
		ld t=(-8*p.x*u.x-2*p.y*u.y)/(4*u.x*u.x+u.y*u.y);
		q.x=p.x+t*u.x;
		q.y=p.y+t*u.y;
		

		n=normalise( Vecteur( 1, -4*q.x/q.y ) );
		n2=orthogonal( n );
		v=MultScalaire(n, ps(n,u))+MultScalaire(n2,-ps(n2,u));
		
		u=copier(v);
		p=copier(q);
		
		reflexion++;
	}
    //cout << p.x << ' ' << p.y << '\n';
    cout << reflexion << '\n';
    return 0;
}
