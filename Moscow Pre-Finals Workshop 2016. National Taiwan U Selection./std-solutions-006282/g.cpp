#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline int SG(double x){
  const double EPS=1E-7;
  if(x>-EPS && x<EPS) return 0;
  return x>0?1:-1;
}

struct PT{
  double x,y;
  PT(){}
  PT(double x,double y):x(x),y(y){}
  PT operator+(const PT& p) const{
    return PT(x+p.x,y+p.y);
  }
  PT operator-(const PT& p) const{
    return PT(x-p.x,y-p.y);
  }
  PT operator*(const double c) const{
    return PT(x*c,y*c);
  }
  PT operator/(const double c) const{
    return PT(x/c,y/c);
  }
  double operator*(const PT& p) const{
    return x*p.x+y*p.y;
  }
  double operator^(const PT& p) const{
    return x*p.y-y*p.x;
  }
  void p() const{
    fprintf(stderr,"%.6f %.6f\n",x,y);
  }
};

int n,m;
double alpha;

PT pt[100000];
PT qt[100000];

int BTW(double a,double b,double c){
  if(b>c) swap(b,c);
  return SG(b-a)<0 && SG(c-a)>0;
}

inline PT ref(const PT& p1,const PT& p2){
  double a = atan2(p2.y-p1.y,p2.x-p1.x)*2;
  return PT(cos(a),sin(a));
}

inline double tri(const PT& p1,const PT& p2,const PT& p3){
  return (p2-p1)^(p3-p1);
}

inline PT sect(const PT& p1,const PT& p2,const PT& p3,const PT& p4){
  double ta = tri(p1,p2,p3);
  double tb = tri(p1,p2,p4);
  return (p3*tb-p4*ta)/(tb-ta);
}

void readgon(int n,PT *p,double vx,double vy){
  double a = atan2(vy,vx);
  double x,y;
  for(int i=0;i<n;i++){
    scanf("%lf %lf",&x,&y);
    double l = sqrt(x*x+y*y);
    double b = atan2(y,x)-a;
    p[i] = PT(cos(b)*l,sin(b)*l);
  }
}

void input(){
  double vx,vy;
  scanf("%d %d %lf %lf %lf",&n,&m,&alpha,&vx,&vy);
  //fprintf(stderr,"%.5f %.5f\n",vx,vy);
  readgon(n,pt,vx,vy);
  readgon(m,qt,vx,vy);
}

double calc_direct(){
  PT pU,pD,qU,qD;
  pU = pD = pt[0];
  for(int i=1;i<n;i++){
    if(pt[i].y>pU.y) pU=pt[i];
    if(pt[i].y<pD.y) pD=pt[i];
  }
  qU = qD = qt[0];
  for(int i=1;i<m;i++){
    if(qt[i].y>qU.y) qU=qt[i];
    if(qt[i].y<qD.y) qD=qt[i];
  }
  //fprintf(stderr,"%.6f %.6f %.6f %.6f\n",pD.y,pU.y,qD.y,qU.y);
  if((BTW(qU.y,pU.y,pD.y) || BTW(qD.y,pU.y,pD.y) || BTW(pU.y,qU.y,qD.y)) && 
    (SG(tri(qU,qD,pU))>0 || SG(tri(qU,qD,pD))>0)){
    return (pU.y-pD.y)-(min(pU.y,qU.y)-max(pD.y,qD.y));
  }else{
    return pU.y-pD.y;
  }
}

double yrange[2][2];
int yr;
void calc_yrange(){
  PT pU,pD,qU,qD;
  pU = pD = pt[0];
  for(int i=1;i<n;i++){
    if(pt[i].y>pU.y) pU=pt[i];
    if(pt[i].y<pD.y) pD=pt[i];
  }
  qU = qD = qt[0];
  for(int i=1;i<m;i++){
    if(qt[i].y>qU.y) qU=qt[i];
    if(qt[i].y<qD.y) qD=qt[i];
  }
  if((BTW(pU.y,qU.y,qD.y) || BTW(pD.y,qU.y,qD.y) || BTW(qU.y,pU.y,pD.y)) && 
    (min(pU.x,pD.x)<max(qU.x,qD.x))){
    if(pD.y<qD.y){
      if(pU.y<qU.y){
        yr = 1;
        yrange[0][0] = pU.y;
        yrange[0][1] = qU.y;
      }else{
        yr = 0;
      }
    }else{
      if(pU.y<qU.y){
        yr = 2;
        yrange[0][0] = qD.y;
        yrange[0][1] = pD.y;
        yrange[1][0] = pU.y;
        yrange[1][1] = qU.y;
      }else{
        yr = 1;
        yrange[0][0] = qD.y;
        yrange[0][1] = pD.y;
      }
    }
  }else{
    yrange[0][0] = qD.y;
    yrange[0][1] = qU.y;
    yr = 1;
  }
}


double calc_reflect(double D,double U){
  if(SG(U-D)<=0) return 0;
  int qi=0;
  for(int i=1;i<m;i++){
    if(SG(qt[i].y-qt[qi].y)>0 || (SG(qt[i].y-qt[qi].y)==0 && qt[i].x<qt[qi].x)) qi=i;
  }
  int f=1;
  int pl,pr;
  double sum = 0;
  for(int i=qi;;i=(i+1)%m){
    int j=(i+1)%m;
    if(SG(qt[i].y-qt[j].y)<=0) break;
    if(SG(qt[j].y-U)>=0) continue;
    if(SG(qt[i].y-D)<=0) break;
    if(SG(qt[i].x-qt[j].x)==0) continue;
    PT rr = ref(qt[i],qt[j]);
    PT q1 = qt[i];
    PT q2 = q1 + rr;
    if(f){
      f = 0;
      pl=pr=0;
      for(int k=1;k<n;k++){
        if(SG(tri(q1,q2,pt[k])-tri(q1,q2,pt[pl]))>0) pl = k;
        if(SG(tri(q1,q2,pt[k])-tri(q1,q2,pt[pr]))<0) pr = k;
      }
    }
    while(SG(tri(q1,q2,pt[(pl+1)%n])-tri(q1,q2,pt[pl]))>=0) pl = (pl+1)%n;
    while(SG(tri(q1,q2,pt[(pr+1)%n])-tri(q1,q2,pt[pr]))<=0) pr = (pr+1)%n;
    PT qi=qt[i];
    PT qj=qt[j];
    if(qi.y>U) qi = (qt[i]-qt[j])*((U-qt[j].y)/(qt[i].y-qt[j].y))+qt[j];
    if(qj.y<D) qj = (qt[j]-qt[i])*((D-qt[i].y)/(qt[j].y-qt[i].y))+qt[i];
    if(SG(tri(pt[pl],pt[pr],qi))<0){
      if(SG(tri(pt[pl],pt[pr],qj))>0){
        qj = sect(pt[pl],pt[pr],qi,qj);
      }
    }else if(SG(tri(pt[pl],pt[pr],qj))<0){
      qi = sect(pt[pl],pt[pr],qi,qj);
    }else{
      continue;
    }
    q1 = qi+rr;
    q2 = qj+rr;
    PT r1,r2;
    int g = 0;
    if(SG(tri(qj,q2,pt[pl]))<=0 && SG(tri(qi,q1,pt[pl]))>=0){
      r2 = sect(qi,qj,pt[pl],pt[pl]-rr);
      g = 1;
    }else{
      r2 = qj;
    }
    if(SG(tri(qj,q2,pt[pr]))<=0 && SG(tri(qi,q1,pt[pr]))>=0){
      r1 = sect(qi,qj,pt[pr],pt[pr]-rr);
      g = 1;
    }else{
      r1 = qi;
    }
    /*rr.p();
    qi.p();
    qj.p();
    r1.p();
    r2.p();
    pt[pr].p();
    pt[pl].p();*/
    if(g==0){
      if(SG(tri(qj,q2,pt[pr]))>=0 || SG(tri(qj,q2,pt[pl]))<=0){
        continue;
      }
    }
    double dr = max(r1.y-r2.y,0.0);
    //fprintf(stderr,"%.8f\n",dr);
    sum += dr;
  }
  return sum;
}

int main() {
  int TT;
  scanf("%d",&TT);
  for(int tt=0; tt<TT; tt++){
    input();
    double s = calc_direct();
    //fprintf(stderr,"%.6f\n",s);
    calc_yrange();
    for(int i=0;i<yr;i++){
      double d = calc_reflect(yrange[i][0],yrange[i][1]);
      //fprintf(stderr,"%.4f %.4f  %.6f\n",yrange[i][0],yrange[i][1],d);
      s += d*alpha;
    }
    printf("%.9f\n",s);
  }
  return 0;
}
