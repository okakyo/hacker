#include<stdio.h>

int main(){
	int int_var=5;
	int *int_ptr;

	int_ptr=&int_var;
	printf("int_ptr=0x%08x\n",int_ptr);
	printf("&int_ptr=0x%08x\n",&int_ptr);
	printf("*int_ptr=0x%08x\n\n",*int_ptr);

	printf("int_var�̊i�[�ꏊ�F0x%08x ���̓��e�F%d\n",&int_var,int_var);
	printf("int_ptr�̊i�[�ꏊ�F0x%08x,���̓��e�F0x%08x,�w���Ă�����e�F%d\n\n",&int_ptr,int_ptr,*int_ptr);


return 0;
}
