#include <stdio.h>

#include <math.h>

#include "ps.h"


int main(void){

	init();
	viewport(0.2, 0.2, 0.8,0.8);
	xyworld(-1.0,-1.0, 1.0,1.0);
	//��ƕ@�̈ʒu�ݒ�
	circ1(0.5,0.5,1);
	circfill1(0.5,0.5,0.1);
	circ1(0.5,0.35,0.85);
	//�ڂ̈ʒu�ݒ�
	circ1(0.75,0.75,0.2);
	circfill1(0.75,0.75,0.1);
	circ1(0.25,0.75,0.2);
	circfill1(0.25,0.75,0.1);
	//���̈ʒu�ݒ�
	curv1(0.2,0.1,0.25,-0.05,0.75,-0.05,0.8,0.1);
	plot(0.5,0.5,3);
	plot(0.5,0.5,2);
	plot(0.5,0.1,2);
	plot(0.2,0.1,2);
	plot(0.8,0.1,2);
	//�Ђ��̈ʒu�ݒ�
	for(int i=0;i<8;i++){
		if(i==2 or i==6) continue;
	th+=npi
	X+=r*cos()+;
	y+=i*sin()+; 
	plot(,,3);
	plot(,,2);
	plot(,,2);
	}

	stroke();
	fin();
	return 0;}
