#include<stdio.h>

int main(){
	char char_array[5]={'a','b','c','d','e'};
	int int_array[5]={1,2,3,4,5};

	char *char_pointer;
	int *int_pointer;

	char_pointer=char_array;
	int_pointer=int_array;

	for(int i=0; i<5;i++){
		printf("[整数のポインタ]は%pを指しており、その内容は%dです\n",int_pointer,*int_pointer);
		int_pointer=1;}
	for(int i=0; i<5;i++){
		printf("[文字のポインタ]は%pを指しており、その内容は%cです\n",char_pointer,*char_pointer);
		char_pointer+=1;}
return 0;}
