#include<stdio.h>
#include<string.h>

int main(){
	char message[20];
	int count,i;
	strcpy(message,"Hello World");	

	printf("���x�J��Ԃ��܂����H");
	scanf("%d",&count);

	for(i=0;i<count;i++)
		printf("%3d - %s\n",i,message);

return 0;
}
