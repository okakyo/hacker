#include<stdio.h>

int j=42;

void func3(){
	int i=11,j=999;
	printf("\t\t\t[func3��] i=%d,j=%d\n",i,j);
}

void func2(){
	int i=7;
	printf("\t\t[func2��] i=%d,j=%d \n",i,j);
	printf("\t\t[func2��]j��1337�������܂��B\n");
	j=1337;
	func3();
	printf("\t\t[func2�ɖ߂��Ă��܂���] i=%d,j=%d\n",i,j);
}
void func1(){
	int i=5;
	printf("\t[func1��] i=%d,j=%d \n",i,j);
	func2();
	printf("\t[func1�ɖ߂��Ă��܂���] i=%d,j=%d\n",i,j);
}
int main(){
	int i=3;
	printf("[main��] i=%d,j=%d \n",i,j);
	func1();
	printf("[main�ɖ߂��Ă��܂���] i=%d,j=%d\n",i,j);
	return 0;
}
