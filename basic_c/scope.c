#include<stdio.h>

void func3(){
	int i=11;
	printf("\t\t\t[func3“à] i=%d\n",i);
}
void func2(){
	int i=7;
	printf("\t\t[func2“à] i=%d\n",i);
	func3();
	printf("\t\t[func2‚É–ß‚Á‚Ä‚«‚Ü‚µ‚½B] i=%d\n",i);
}
void func1(){
	int i=5;
	printf("\t[func1“à] i=%d\n",i);
	func2();
	printf("\t[func1‚É–ß‚Á‚Ä‚«‚Ü‚µ‚½B] i=%d\n",i);
}
int main(){
	int i=3;
	printf("[main“à] i=%d\n",i);
	func1();
	printf("[main‚É–ß‚Á‚Ä‚«‚Ü‚µ‚½B] i=%d\n",i);
	return 0;
}
