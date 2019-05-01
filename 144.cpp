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
    return 0;
}
