#include<stdio.h>

int main(){
	char char_array[5]={'a','b','c','d','e'};
	int int_array[5]={1,2,3,4,5};

	char *char_pointer;
	int *int_pointer;

	char_pointer=char_array;
	int_pointer=int_array;

	for(int i=0; i<5;i++){
		printf("[�����̃|�C���^]��%p���w���Ă���A���̓��e��%d�ł�\n",int_pointer,*int_pointer);
		int_pointer=1;}
	for(int i=0; i<5;i++){
		printf("[�����̃|�C���^]��%p���w���Ă���A���̓��e��%c�ł�\n",char_pointer,*char_pointer);
		char_pointer+=1;}
return 0;}