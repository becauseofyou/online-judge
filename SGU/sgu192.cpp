#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
struct point {
	double x,y;
	void in() {
		scanf("%lf%lf",&x,&y);
	}
	point (double x=0,double y=0):x(x),y(y){}
};
typedef point Vector;
inline Vector operator + (const Vector &a, const Vector &b) {
	return Vector(a.x + b.x, a.y + b.y);
}
inline Vector operator - (const Vector &a, const Vector &b) {
	return Vector(a.x - b.x, a.y - b.y);
}
inline Vector operator * (const Vector &a, double t) {
	return Vector(a.x * t, a.y * t);
}
inline Vector operator / (const Vector &a, double p) {
	return Vector(a.x / p, a.y / p);
}
inline int sgn(double x,double eps=1e-5) {
	return x < -eps ? -1 : x > eps;
}
bool operator < (const point &a, const point &b) {
	return sgn(a.x - b.x) < 0 || sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0;
}
bool operator == (const point &a, const point &b) {
	return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}
inline double cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}
inline double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}
struct seg {
	point s,e;
	char col[3];
	void in() {
		s.in();
		e.in();
		scanf("%s",col);
		if(sgn(s.x - e.x) > 0) std::swap(s,e);
	}
}ss[330];
bool intersect(point P, Vector v, point Q, Vector w, point &p) {
	Vector u = P - Q;
	if(sgn(cross(v, w)) == 0) return false;
	double t = cross(w, u) / cross(v, w);
	p = P + v * t;
	return true;
}
bool dotOnseg(point p,seg L)  {
	return sgn(cross(L.s - p, L.e - p)) == 0 && sgn(dot(L.s - p, L.e - p)) <= 0;
}
double calc(double mid,seg s){
	double tmp =  fabs(1.0*s.e.y-s.s.y) * (mid - s.s.x) / (1.0*s.e.x-s.s.x);
	if(s.s.y < s.e.y) return tmp + s.s.y;
	else return s.s.y - tmp;
}
double x[100010];
double len[1010];
int ID[1010];
int main(){
	memset(len,0,sizeof(len));
	ID['R'] = 0;
	ID['G'] = 1;
	ID['B'] = 2;
	int n,tot=0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)  ss[i].in();
	for(int i = 0; i < n; i++) {
		x[tot++] = ss[i].s.x;
		x[tot++] = ss[i].e.x;
		for(int j = i + 1; j < n; j++) {
			point p;
			if(intersect(ss[i].s,ss[i].e-ss[i].s,ss[j].s,ss[j].e-ss[j].s,p)) {
			//	printf("%lf %lf\n",p.x,p.y);
				if(dotOnseg(p,ss[i]) && dotOnseg(p,ss[j])) {
					x[tot++] = p.x;
				}
			}
		}
	}
	//for(int i = 0 ; i< tot; i++) printf("%lf ",x[i]);puts("");
	std::sort(x, x + tot);
	for(int i = 1; i < tot; i++) {
		if(sgn(x[i] - x[i-1]) == 0) continue;
		double mid = (x[i-1] + x[i]) / 2, mi = -1;
		int id = -1;
		for(int j = 0; j < n; j++) {
			if(sgn(mid - ss[j].s.x) < 0 || sgn(mid - ss[j].e.x) > 0)
				continue;
			double height = calc(mid, ss[j]);
			if(mi == -1 || height < mi) {
				mi = height;
				id = j;
			}
		}
		if(id!=-1)len[ID[ss[id].col[0]]] += x[i] - x[i-1];
	}
	printf("R %.2f\n",len[0]);
	printf("G %.2f\n",len[1]);
	printf("B %.2f\n",len[2]);
//	while(1);
	return 0;
}
/*
3
1 2 4 5 R
3 2 1 4 G
4 2 3 4 B

*/
