#include<stdio.h>

void func3(){
	int i=11;
	printf("\t\t\t[func3��] i=%d\n",i);
}
void func2(){
	int i=7;
	printf("\t\t[func2��] i=%d\n",i);
	func3();
	printf("\t\t[func2�ɖ߂��Ă��܂����B] i=%d\n",i);
}
void func1(){
	int i=5;
	printf("\t[func1��] i=%d\n",i);
	func2();
	printf("\t[func1�ɖ߂��Ă��܂����B] i=%d\n",i);
}
int main(){
	int i=3;
	printf("[main��] i=%d\n",i);
	func1();
	printf("[main�ɖ߂��Ă��܂����B] i=%d\n",i);
	return 0;
}
