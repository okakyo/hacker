#include<stdio.h>

int j=42;

void func3(){
	int i=11,j=999;
	printf("\t\t\t[func3��] i@0x%o8x =%d\n",&i,i);
	printf("\t\t\t[func3��] j@0x%o8x =%d\n",&j,j);
}

void func2(){
	int i=7;
	printf("\t\t[func2��] i@0x%o8x =%d\n",&i,i);
	printf("\t\t[func2��] j@0x%o8x =%d\n",&j,j);
	printf("\t\t[func2��]j��1337�������܂��B\n");
	j=1337;
	func3();
	printf("\t\t[func2�ɖ߂��Ă��܂���] i@0x%o8x =%d\n",&i,i);
	printf("\t\t[func2�ɖ߂��Ă��܂���] j@0x%o8x =%d\n",&j,j);
}
void func1(){
	int i=5;
	printf("\t[func1��] i@0x%o8x =%d\n",&i,i);
	printf("\t[func1��] j@0x%o8x =%d\n",&j,j);
	func2();
	printf("\t[func1�ɖ߂��Ă��܂���] i@0x%o8x =%d\n",&i,i);
	printf("\t[func1�ɖ߂��Ă��܂���] j@0x%o8x =%d\n",&j,j);
}
int main(){
	int i=3;
	printf("[main��] i@0x%o8x =%d\n",&i,i);
	printf("[main��] j@0x%o8x =%d\n",&j,j);
	func1();
	printf("[main�ɖ߂��Ă��܂���] i@0x%o8x =%d\n",&i,i);
	printf("[main�ɖ߂��Ă��܂���] j@0x%o8x =%d\n",&j,j);
	return 0;
}