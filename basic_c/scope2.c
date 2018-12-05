#include<stdio.h>

int j=42;

void func3(){
	int i=11,j=999;
	printf("\t\t\t[func3“à] i=%d,j=%d\n",i,j);
}

void func2(){
	int i=7;
	printf("\t\t[func2“à] i=%d,j=%d \n",i,j);
	printf("\t\t[func2“à]j‚É1337‚ğ‘ã“ü‚µ‚Ü‚·B\n");
	j=1337;
	func3();
	printf("\t\t[func2‚É–ß‚Á‚Ä‚«‚Ü‚µ‚½] i=%d,j=%d\n",i,j);
}
void func1(){
	int i=5;
	printf("\t[func1“à] i=%d,j=%d \n",i,j);
	func2();
	printf("\t[func1‚É–ß‚Á‚Ä‚«‚Ü‚µ‚½] i=%d,j=%d\n",i,j);
}
int main(){
	int i=3;
	printf("[main“à] i=%d,j=%d \n",i,j);
	func1();
	printf("[main‚É–ß‚Á‚Ä‚«‚Ü‚µ‚½] i=%d,j=%d\n",i,j);
	return 0;
}
