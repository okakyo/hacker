#include <stdio.h>
#include <math.h>

#include "ps.h"


int main(void){
	init();
	viewport(0.2, 0.2, 0.8,0.8);
	xyworld(-1.0,-1.0, 1.0,1.0);
	//顔と鼻の位置設定
	circ1(0.5,0.5,1);
	circfill1(0.5,0.5,0.1);
	circ1(0.5,0.35,0.85);
	//目の位置設定
	circ1(0.75,0.75,0.2);
	circfill1(0.75,0.75,0.1);
	circ1(0.25,0.75,0.2);
	circfill1(0.25,0.75,0.1);
	//口の位置設定
	curv1(0.2,0.1,0.25,-0.05,0.75,-0.05,0.8,0.1);
	plot(0.5,0.5,3);
	plot(0.5,0.5,2);
	plot(0.5,0.1,2);
	plot(0.2,0.1,2);
	plot(0.8,0.1,2);
	//ひげの位置設定
	double r1=0.2,r2=0.6;
	for(int i=0;i<12;i++){
		if(i==5|| i==6|| i==7 ||i==11|| i==1 || i==0 ){
	double th=2.0*PI*((double)i/12.0);
	double x1=r1*cos(th)+0.5;
	double y1=r1*sin(th)+0.3; 
	double x2=r2*cos(th)+0.5;
	double y2=r2*sin(th)+0.3; 
	plot(x1,y1,3);
	plot(x1,y1,2);
	plot(x2,y2,2);
		}
	}

	stroke();
	fin();
	return 0;}
