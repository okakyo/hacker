#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FONTTABLE
#include "ps.h"

//papersize
static double Xsize, Ysize;

//viewpoint
static double Xv1, Yv1, Xv2, Yv2;

//world coordinate
static double Xw1, Yw1, Xw2, Yw2;

//linety
static int Linety;

FILE* Stream;

// plotting routines for general purpose using postscript

//標準の文字フォント、フォントサイズ
static const iFont Std_ichar = TIMES_ROMAN;
static const int Std_ip = 18;

static iFont Cur_ichar; //現在の文字フォント
static int Cur_ip;      //現在の文字フォントサイズ

static void chgchar(int ichar, int ip);

iFont get_ichar(){
    return Cur_ichar;
}

iFont get_fntsize(){
    return Cur_ip;
}

void write_header(void){
    // aspect ratio of the paper is 1.4143
    fprintf(Stream, "%%!\n%%Created by Jiro Mizushima\n");
    fprintf(Stream, "/%s findfont %d scalefont setfont\n",
                    fonttbl[Std_ichar],Std_ip);
    //cm 単位を使用可能にするために cm演算を定義: point = 28.35 * cm
    fprintf(Stream, "/cm {28.35 mul} def \n");
}

void init(void){
    init_ext("");
}

// init_ext :
//   initを psファイルのファイル名を引数で指定できるようにしたもの
//   initの代わりに使用できる
void init_ext(const char *of){
    char oftmp[31];
    int len=strlen(of);
    if(len==0 || len+3>30){
        strcpy(oftmp,"temp1.ps");
    }
    else{
        strcpy(oftmp,of);
        if(strstr(of,".ps")==NULL){
            strcat(oftmp,".ps");
        }
    }
    Stream = fopen(oftmp, "w");

    write_header();

    Cur_ichar = Std_ichar;
    Cur_ip = Std_ip;
    Xsize = 21.0;/* Ysize = 29.7;*/ Ysize = 21.0;
    viewport(0.2, 0.2, 0.8, 0.8);
    xyworld(0.0, 0.0, 1.0, 1.0);
    set_line_gwt(0.0, 1, 1);
    return;
}

void ch_of(const char *of){
    if(Stream != NULL) fclose(Stream);
    Stream = fopen(of,"w");

    write_header();
}

double get_Xsize(){
    return Xsize;
}

double get_Ysize(){
    return Ysize;
}

double get_nwidth(){
    return fabs(Xv2-Xv1);
}

double get_nhight(){
    return fabs(Yv2-Yv1);
}

void viewport(double xv1d, double yv1d, double xv2d, double yv2d){
    Xv1 = xv1d; Yv1 = yv1d; Xv2 = xv2d; Yv2 = yv2d;
    return;
}

void xyworld(double xw1d, double yw1d, double xw2d, double yw2d){
    Xw1 = xw1d; Yw1 = yw1d; Xw2 = xw2d; Yw2 = yw2d;
    return;
}

void fin(void){
    stroke(); fprintf(Stream, "showpage\n"); fclose(Stream);
    return;
}

void linety(int ichar){
    Linety = ichar; //大域変数Linetyに記憶
    switch (ichar) {
        case 1: fprintf(Stream, "[] 0 setdash \n");        break;
        case 2: fprintf(Stream, "[2 2] 0 setdash \n");     break;
        case 3: fprintf(Stream, "[8 2] 0 setdash \n");     break;
        case 4: fprintf(Stream, "[8 1 1 1] 0 setdash \n"); break;
    }
    return;
}

void linewidth(double w){
    fprintf(Stream, "%lf setlinewidth\n", w); return;
}

void setgray(double g){
    fprintf(Stream, "%lf setgray\n", g); return;
}

void setrgb(double r,double g,double b){
    fprintf(Stream, "%lf %lf %lf setrgbcolor\n",r,g,b); return;
}

// 線属性を設定
void set_line_gwt(double g, double w, int it){
    setgray(g); linewidth(w); linety(it); 
}
// Defaultの線属性
void default_line_gwt(){
    set_line_gwt(0.0, 1.0, 1);
}

void newpath(void){
    fprintf(Stream, "newpath\n"); return;
}

void closepath(void){
    fprintf(Stream, "closepath\n"); return;
}

void fill(void){
    fprintf(Stream, "fill\n"); return;
}

void stroke(void){ 
    fprintf(Stream, "stroke\n"); 
}

void rotate(int itheta){ 
    fprintf(Stream, "%d rotate\n",itheta); 
}

void scale(double tx, double ty){ 
    fprintf(Stream, "%lf %lf scale\n",tx, ty); 
}

double x_w2n(double x){
    return ((x-Xw1)/(Xw2-Xw1)*(Xv2-Xv1) + Xv1);
}

double y_w2n(double y){
    return ((y-Yw1)/(Yw2-Yw1)*(Yv2-Yv1) + Yv1);
}

double x_w2paper(double x){
    return x_w2n(x)*Xsize;
}

double y_w2paper(double x){
    return y_w2n(x)*Ysize;
}

double x_scale_w2paper(double sx){
    return sx/(Xw2-Xw1)*(Xv2-Xv1)*Xsize;
}

double y_scale_w2paper(double sy){
    return sy/(Yw2-Yw1)*(Yv2-Yv1)*Ysize;
}

double x_n2w(double xn){
    return ((xn*Xsize-Xv1)/(Xv2-Xv1)*(Xw2-Xw1) + Xw1)/Xsize;
}

double y_n2w(double yn){
    return ((yn*Ysize-Yv1)/(Yv2-Yv1)*(Yw2-Yw1) + Yw1)/Ysize;
}

void transrate(double x, double y){ double x1,y1;
    x1 = x_w2paper(x);
    y1 = y_w2paper(y);
    fprintf(Stream, "%lf cm %lf cm translate\n", x1, y1);
}

void clipon(double x1, double y1, double x2, double y2){ 
    newpath();
    plot(x1, y1, MOVETO);
    plot(x2, y1, LINETO);plot(x2, y2,LINETO); plot(x1, y2, LINETO);
    closepath();
    fprintf(Stream, "clip\n");
}

void eoclipon(double x1, double y1, double x2, double y2){ 
    newpath();
    plot(x1, y1, MOVETO);
    plot(x2, y1, LINETO);plot(x2, y2,LINETO); plot(x1, y2, LINETO);
    closepath();
    fprintf(Stream, "eoclip\n");
}

void clipoff(void){
    fprintf(Stream, "initclip\n");
}

void plot(double x, double y, int ipen){
    double x1, y1;

    x1 = x_w2paper(x);
    y1 = y_w2paper(y);
    switch (ipen) {
        case MOVETO: fprintf(Stream, "%lf cm %lf cm moveto\n", x1,y1);
                break;
        case LINETO: fprintf(Stream, "%lf cm %lf cm lineto\n", x1,y1);
                break;
    }
    return;
}

// 座標値を使用せず、point単位を使って現在位置から相対移動
void rmoveto(double xp, double yp){
    fprintf(Stream, "%lf %lf rmoveto\n", xp,yp);
}

void plotseries(double xx[], double yy[], int n,
                double g, double w, int it){
    int i;
    set_line_gwt(g,w,it);
    plot(xx[0],yy[0],MOVETO);
    for(i=1; i<n; i++){
        plot(xx[i],yy[i],LINETO);
    }
    stroke();
    default_line_gwt();
}

void plotseries1(double xx[], double yy[], int n){
    int i;
    plot(xx[0],yy[0],MOVETO);
    for(i=1; i<n; i++){
        plot(xx[i],yy[i],LINETO);
    }
    stroke();
}


void line1(double x, double y, double xx, double yy){
    double x1, y1, xx1, yy1;
    x1  = x_w2paper(x);  y1  = y_w2paper(y);
    xx1 = x_w2paper(xx); yy1 = y_w2paper(yy);
    fprintf(Stream, "%lf cm %lf cm moveto\n", x1, y1);
    fprintf(Stream, "%lf cm %lf cm lineto\n", xx1, yy1);
    stroke();
    return;
}

void line(double x, double y, double xx, double yy,
          double g, double w, int it){
    set_line_gwt(g,w,it);
    line1(x, y, xx, yy);
    default_line_gwt();
}

void rect1(double x1, double y1, double x2, double y2){
    newpath();
    plot(x1,y1,MOVETO); plot(x2,y1,LINETO);
    plot(x2,y2,LINETO); plot(x1,y2,LINETO);
    closepath();
    stroke();
    return;
}

void rect(double x1, double y1, double x2, double y2,
          double g, double w, int it){
    set_line_gwt(g,w,it);
    rect1(x1, y1, x2, y2);
    default_line_gwt();
    return;
}

void rectfill1(double x1, double y1, double x2, double y2){
    newpath();
    plot(x1,y1,MOVETO); plot(x2,y1,LINETO);
    plot(x2,y2,LINETO); plot(x1,y2,LINETO);
    closepath();
    fprintf(Stream, " fill\n");
    stroke();
    return;
}

void circ(double x1, double y1, double r1, double g, double w, int it){ 
    set_line_gwt(g,w,it);
    circ1(x1, y1, r1);
    default_line_gwt();
    return;
}

void circ1(double x1, double y1, double r1){ 
    double xx1,yy1,rr1;
    xx1 = x_w2paper(x1); yy1 = y_w2paper(y1);
    rr1 = x_scale_w2paper(r1);
    newpath();
    fprintf(Stream, "%lf cm %lf cm %lf cm 0 360 arc\n", xx1, yy1, rr1);
    stroke();
    return;
}

void circfill1(double x1, double y1, double r1){ 
    double xx1,yy1,rr1;
    xx1 = x_w2paper(x1); yy1 = y_w2paper(y1);
    rr1 = x_scale_w2paper(r1);
    newpath();
    fprintf(Stream, "%lf cm %lf cm %lf cm 0 360 arc\n", xx1, yy1, rr1);
    fprintf(Stream, " fill\n");
    stroke();
    return;
}

//半径は座標系とは関係なくmm単位で与える
void marker_circ1(double x1, double y1, double r_mm, int fill_flag){
    double xx1,yy1;
    xx1 = x_w2paper(x1); yy1 = y_w2paper(y1);
    newpath();
    fprintf(Stream, "%lf cm %lf cm %lf cm 0 360 arc\n", xx1, yy1, r_mm/10.0);
    if(fill_flag) fprintf(Stream, " fill\n");
    stroke();
}

void grid(double x1, double y1, double x2, double y2, int nrow, int ncol){
    double x, y;
    double dx = (x2-x1)/ncol, dy = (y2-y1)/nrow;
    int i;
    newpath();plot(x1,y1,MOVETO);
    plot(x2,y1,LINETO);plot(x2,y2,LINETO);plot(x1,y2,LINETO);
    closepath();
    for(i=1; i<ncol; i++){
        x = x1 + i*dx;
        plot(x,y1,MOVETO); plot(x,y2,LINETO); 
    }
    for(i=1; i<nrow; i++){
        y = y1 + i*dy;
        plot(x1,y,MOVETO); plot(x2,y,LINETO); 
    }
    stroke();
    return;
}

void grid_with_text(double x1, double y1, double x2, double y2,
                    int nrow, int ncol, char *str){
    double x, y;
    double dx = (x2-x1)/ncol, dy = (y2-y1)/nrow;
    char *p = str;
    int i,j;
    for(i=1; i<=nrow; i++){
        y = y1+i*dy;
        for(j=0; j<ncol; j++){
            if( *p == '\0') break;
            if( *p == '\n'){
                p++;  break;
            }
            x = x1+j*dx;
            write_char(x, y, *p);
            p++;
        }
        if(*p == '\0')break;
    }
}

void ellipse(double x1, double y1, double rx, double ry,
             double g, double w, int it){     
    set_line_gwt(g,w,it);
    ellipse1(x1, y1, rx, ry);
    default_line_gwt();
}

void ellipse1(double x1, double y1, double rx, double ry){     
    double x, y, dt; int i;
    newpath(); 
    x=x1+rx; y=y1; dt=PI*2.0/20.0;
    plot(x,y,MOVETO); 
    for (i=1;i<=20;i++) { 
        x=x1+rx*cos(dt*i);y=y1+ry*sin(dt*i); plot(x,y,LINETO);
    }
    stroke();
}

void ellipsefill1(double x1, double y1, double rx, double ry){     
    double x, y, dt; int i;
    newpath(); 
    x=x1+rx; y=y1; dt=PI*2.0/20.0;
    plot(x,y,MOVETO); 
    for (i=1;i<=20;i++) { 
        x=x1+rx*cos(dt*i);y=y1+ry*sin(dt*i); plot(x,y,LINETO);
    }
    fprintf(Stream, "fill\n");
    stroke();
}

void arc1(double x1, double y1, double r1, double t1, double t2){ 
    double xx1,yy1,rr1;
    xx1 = x_w2paper(x1); yy1 = y_w2paper(y1);
    rr1 = x_scale_w2paper(r1);
    newpath(); 
    fprintf(Stream,"%lf cm %lf cm %lf cm %lf %lf arc \n",xx1,yy1,rr1,t1,t2);
    stroke();
    return;
}

void arc(double x1, double y1, double r1, double t1, double t2,
         double g, double w, int it){ 
    set_line_gwt(g,w,it);
    arc1(x1, y1, r1, t1, t2);
    default_line_gwt();
    return;
}

void curv1(double x1, double y1, double x2, double y2,
           double x3, double y3, double x4, double y4){
    double xx2,yy2,xx3,yy3,xx4,yy4;
    xx2 = x_w2paper(x2); yy2 = y_w2paper(y2);
    xx3 = x_w2paper(x3); yy3 = y_w2paper(y3);
    xx4 = x_w2paper(x4); yy4 = y_w2paper(y4);
    newpath();
    plot(x1,y1,MOVETO);
    fprintf(Stream, "%lf cm %lf cm %lf cm %lf cm %lf cm %lf cm curveto\n",
                     xx2 ,yy2,xx3,yy3,xx4,yy4); 
    stroke();
    return;
}

void curv(double x1, double y1, double x2, double y2,
          double x3, double y3, double x4, double y4, double g, double w, int it){
    set_line_gwt(g,w,it);
    curv1(x1, y1, x2, y2, x3, y3, x4, y4);
    default_line_gwt(g,w,it);
    return;
}

void triangl(double x1, double y1, double r1, double a1, double g, double w, int it){
    set_line_gwt(g,w,it);
    triangl1(x1, y1, r1, a1);
    default_line_gwt();
    return; 
}

void triangl1(double x1, double y1, double r1, double a1){
    double aa1,aa2;
    aa1=a1*PI/180.0;
    aa2=aa1+PI/3.0;
    newpath(); plot(x1,y1,MOVETO); plot(x1+r1*cos(aa1), y1+r1*sin(aa1), LINETO);
    plot(x1+r1*cos(aa2), y1+r1*sin(aa2), LINETO);
    closepath();
    stroke(); 
    return; 
}

void trianglfill1(double x1, double y1, double r1, double a1){
    double aa1,aa2;
    aa1=a1*PI/180.0;
    aa2=aa1+PI/3.0;
    newpath(); plot(x1,y1,MOVETO); plot(x1+r1*cos(aa1), y1+r1*sin(aa1), LINETO);
    plot(x1+r1*cos(aa2), y1+r1*sin(aa2), LINETO);
    closepath();
    fprintf(Stream, "fill\n");
    stroke(); 
    return; 
}

void spline(double x1, double y1, double x2, double y2,
            double x3, double y3, double x4, double y4, int ipart, double g, double w){
    linewidth(w); setgray(g); 
    spline1(x1,y1,x2,y2,x3,y3,x4,y4,ipart);
    linewidth(1.0); setgray(0.0); 
    return;
}

void spline1(double x1, double y1, double x2, double y2,
             double x3, double y3, double x4, double y4, int ipart){
    int ns=10,i; double u,x,y; 
    newpath(); 
    u = (double) ipart; 
    x = -u*(u-1.)*(u-2.)/6.*x1+(u+1.)*(u-1.)*(u-2.)/2.*x2
        -(u+1.)*u*(u-2.)/2.*x3+(u+1.)*u*(u-1.)/6.*x4;
    y = -u*(u-1.)*(u-2.)/6.*y1+(u+1.)*(u-1.)*(u-2.)/2.*y2
        -(u+1.)*u*(u-2.)/2.*y3+(u+1.)*u*(u-1.)/6.*y4; 
    plot(x,y,MOVETO); 
    for (i=1;i<=ns;i++){
        u = (double) ipart +(double) i/(double) ns;
        x = -u*(u-1.)*(u-2.)/6.*x1+(u+1.)*(u-1.)*(u-2.)/2.*x2
            -(u+1.)*u*(u-2.)/2.*x3+(u+1.)*u*(u-1.)/6.*x4; 
        y = -u*(u-1.)*(u-2.)/6.*y1+(u+1.)*(u-1.)*(u-2.)/2.*y2
            -(u+1.)*u*(u-2.)/2.*y3+(u+1.)*u*(u-1.)/6.*y4; 
        plot(x,y,LINETO); 
    }
    stroke();
    return;
}

void parabola(double x1, double y1, double x2, double y2,
              double x3, double y3, double g, double w, int it){
    set_line_gwt(g,w,it);
    parabola1(x1,y1,x2,y2,x3,y3); 
    default_line_gwt();
    return; 
}

void parabola1(double x1, double y1, double x2, double y2, double x3, double y3){
    double u,x,y; int i,ns=20; u=0.0;
    newpath(); 
    x=(u-1.)*(u-2.)/2.*x1-u*(u-2.)*x2+u*(u-1.)/2.*x3; 
    y=(u-1.)*(u-2.)/2.*y1-u*(u-2.)*y2+u*(u-1.)/2.*y3; 
    plot(x,y,MOVETO); 
    for (i=1; i<=2*ns; i++){
        u=(double) i/(double) ns; 
        x=(u-1.)*(u-2.)/2.*x1-u*(u-2.)*x2+u*(u-1.)/2.*x3; 
        y=(u-1.)*(u-2.)/2.*y1-u*(u-2.)*y2+u*(u-1.)/2.*y3; 
        plot(x,y,LINETO); 
    }
    stroke(); 
    return; 
}

void arrow(double x1, double y1, double x2, double y2, double d, double g, double w){
    linewidth(w); setgray(g); 
    arrow1(x1,y1,x2,y2,d); 
    default_line_gwt();
    return; 
}

void arrow1(double x1, double y1, double x2, double y2, double d){
    double alpha=2.2,s,x3,y3,x4,y4;
    int linety_old;
    s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
    x3=x2-(x2-x1)/s*d*alpha-(y2-y1)/s*d;
    y3=y2-(y2-y1)/s*d*alpha+(x2-x1)/s*d;
    x4=x2-(x2-x1)/s*d*alpha+(y2-y1)/s*d;
    y4=y2-(y2-y1)/s*d*alpha-(x2-x1)/s*d;
    plot(x1, y1, MOVETO); plot(x2, y2, LINETO);
    stroke();
    linety_old = Linety; linety(SOLID);
    plot(x3, y3, MOVETO);
    plot(x2, y2, LINETO);
    plot(x4, y4, LINETO); 
    linety(linety_old);
    stroke(); 
    return; 
}

// arrow, arrow1の改善版
// d: 矢印の大きさのパラメータ(cm単位)
void arrow01(double x1, double y1, double x2, double y2,
             double d, double g, double w){
    linewidth(w); setgray(g); 
    arrow11(x1,y1,x2,y2,d);
    default_line_gwt();
    return; 
}
void arrow11(double x1, double y1, double x2, double y2, double d){
    double alpha=2.2,s;
    double x_1,y_1,x_2,y_2,x3,y3,x4,y4;
    int linety_old;
    x_1 = x_w2paper(x1);  y_1 = y_w2paper(y1);
    x_2 = x_w2paper(x2);  y_2 = y_w2paper(y2);

    s=sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));

    x3=x_2-(x_2-x_1)/s*d*alpha-(y_2-y_1)/s*d;
    y3=y_2-(y_2-y_1)/s*d*alpha+(x_2-x_1)/s*d;
    x4=x_2-(x_2-x_1)/s*d*alpha+(y_2-y_1)/s*d;
    y4=y_2-(y_2-y_1)/s*d*alpha-(x_2-x_1)/s*d;
    
    fprintf(Stream, "%lf cm %lf cm moveto\n", x_1,y_1);
    fprintf(Stream, "%lf cm %lf cm lineto\n", x_2,y_2);
    stroke();
    linety_old = Linety; linety(SOLID);
    fprintf(Stream, "%lf cm %lf cm moveto\n", x3,y3);
    fprintf(Stream, "%lf cm %lf cm lineto\n", x_2,y_2);
    fprintf(Stream, "%lf cm %lf cm lineto\n", x4,y4);

    stroke(); 
    linety(linety_old);
    return; 
}

void resist(double x1, double y1, double x2, double y2, double d, double w){
    double dx, dy, ex, ey, xx, yy;int i; 
    //s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
    linewidth(w); 
    dx=(x2-x1)/12.0; dy=(y2-y1)/12.0; 
    ex=-d*dy; ey=d*dx; 
    
    plot(x1, y1, MOVETO);
    xx=x1+dx+ex; yy=y1+dy+ey;
    plot(xx, yy, LINETO); 
    
    for(i=1;i<=5; i++){
        xx=x1+(i*2+1)*dx+pow(-1,i)*ex; yy=y1+(i*2+1)*dy+pow(-1,i)*ey; 
        plot(xx, yy, LINETO);
    }
    plot(x2, y2, LINETO); 
    stroke(); linety(1); linewidth(1.0); 
    return;
}

void battery(double x1, double y1, double x2, double y2, double d, double w){
    double dx,dy,ex,ey,xx,yy; 
    //s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
    linewidth(w); 
    dx=(x2-x1)/3.0; dy=(y2-y1)/3.0; 
    ex=-dy; ey=dx; 
    
    plot(x1, y1, MOVETO);
    
    xx=x1+dx; yy=y1+dy; plot(xx, yy, LINETO); stroke();
    linewidth(2.0*w); 
    
    xx=x1+dx+3.0*ex; yy=y1+dy+3.0*ey; 
    plot(xx, yy, MOVETO);
    
    xx=x1+dx-3.0*ex; yy=y1+dy-3.0*ey;
    plot(xx, yy, LINETO); stroke(); 
    
    xx=x1+2.0*dx+ex; yy=y1+2.0*dy+ey; 
    plot(xx, yy, MOVETO);
    
    xx=x1+2.0*dx-ex; yy=y1+2.0*dy-ey;
    plot(xx, yy, LINETO); stroke(); 
    
    linewidth(w);
    plot(x2, y2, MOVETO);
    xx=x2-dx; yy=y2-dy;
    plot(xx, yy, LINETO); stroke(); 
    linewidth(1.0); linety(1); 
    return;
}

void coil(double x1, double y1, double x2, double y2, double d, int n, double w){
    double s,ex,ey,ds,a,xx,yy,t;
    int i;

    s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    linewidth(w);
    ex=(x2-x1)/s;
    ey=(y2-y1)/s;
    a=2.0; ds=(s-2.0*d)/((double) n +0.5);
    plot(x1, y1, MOVETO);
    for(i=1;i<=(40*n+20);i++) {
        t=2.0*PI*(double) i/40.0; 
        xx=x1+((d-d*cos(t))+t/2.0/PI*ds)*ex-a*d*sin(t)*ey;
        yy=y1+((d-d*cos(t))+t/2.0/PI*ds)*ey+a*d*sin(t)*ex;
        plot(xx, yy, LINETO);
    }
    stroke();
    linewidth(1.0);linety(1);
    return;
}

void show_text(char* str){
    fprintf(Stream, "(%s) show\n", str);
}

void text(double x, double y, int n, char* str){
    plot(x,y,MOVETO);
    show_text(str);
}

void write_char(double x, double y, char c){
    plot(x,y,MOVETO);
    fprintf(Stream, "(%c) show\n", c);
}

void textx(double x, double y, int n, char* str){
    plot(x,y,MOVETO);
    rmoveto(-n/2.0*9.0,-3.0/2.0*15.0);
    show_text(str);
}

void texty(double x, double y, int n, char* str){ 
    plot(x,y,MOVETO);
    rmoveto(-(n+1)*9.0,-1.0/2.0*12.0);
    show_text(str);
}

// 与えられた文字数とlbAlignの値に応じて、座標値(0,0)から
// 少しシフトさせた座標値(xs,ys)を得る。
void offset_wrt_line(lbAlign a, int ftsize, int n,double *xs, double *ys){
    switch(a){
        case LEFT : 
            *xs = -(n+2)*ftsize/2.0; *ys = - 1.0/3.0*ftsize;
            break;
        case BELOW : 
            *xs = -n/2.0*ftsize/2;   *ys = -5.0/4.0*ftsize;
            break;
        case RIGHT :
            *xs = 1.0/2.0*ftsize;    *ys = -1.0/3.0*ftsize;
            break;
        case ABOVE :
            *xs = -n/2.0*ftsize/2;   *ys = 1.0/2.0*ftsize;
            break;
        case LEFTABOVE :
            *xs = -(n+1)*ftsize/2.0; *ys = 1.0/2.0*ftsize;
            break;
        case LEFTBELOW :
            *xs = -(n+1)*ftsize/2.0; *ys = -5.0/4.0*ftsize;
            break;
        case RIGHTBELOW :
            *xs = 1.0/2.0*ftsize;    *ys = -5.0/4.0*ftsize;
            break;
        case RIGHTABOVE :
            *xs = 1.0/2.0*ftsize;    *ys = 1.0/2.0*ftsize;
            break;
        default : 
            *xs = 0.0; *ys = 0.0; 
            break;
    }
}

void textsft(int ftsize, lbAlign a, double x, double y, int n, char* str){
    double xs,ys;

    plot(x,y,MOVETO);
    offset_wrt_line(a,ftsize,n,&xs,&ys); 
    rmoveto(xs,ys);
    show_text(str);
    return;
}

// 上付き文字 [str]^sup
void textsup(char *sup){
    chgchar(get_ichar(),(int)(0.6*get_fntsize()));
    rmoveto(0.0,0.5*get_fntsize());
    show_text(sup);
    chgchar(get_ichar(),get_fntsize());
}

// 下付き文字 [str]_sub
void textsub(char *sub){
    chgchar(get_ichar(),(int)(0.6*get_fntsize()));
    rmoveto(0.0,-1.0*get_fntsize()/6.0);
    show_text(sub);
    chgchar(get_ichar(),get_fntsize());
}

static void chgchar(int ichar, int ip){
    fprintf(Stream, "/%s findfont %d scalefont setfont\n",
                    fonttbl[ichar],ip);
    return;
}

void setchar(int ichar, int ip){
    Cur_ichar = ichar;
    Cur_ip = ip;
    fprintf(Stream, "/%s findfont %d scalefont setfont\n",
                    fonttbl[ichar],ip);
    return;
}

void resetchar(){
    setchar(Std_ichar,Std_ip);
}

void square(double x, double y){
    double x1, y1, delta;
    x1 = x_w2paper(x);  y1 = y_w2paper(y);
    delta = 0.1;
    fprintf(Stream, "%lf cm %lf cm moveto\n", x1-delta,y1-delta);
    fprintf(Stream, "%lf cm %lf cm lineto\n", x1+delta,y1-delta);
    fprintf(Stream, "%lf cm %lf cm moveto\n", x1+delta,y1+delta);
    fprintf(Stream, "%lf cm %lf cm lineto\n", x1-delta,y1+delta);
    closepath();stroke();
    return;
}
