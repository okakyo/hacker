#include<stdio.h>
#include<string.h>

//���̃R�[�h�́A�o�b�t�@�[�I�[�o�[�t���[�̗�ł���B8�o�C�g�ɒ�߂��ꏊ�ɂ�����������̃R�[�h�����
//����ƁA�R�[�h���ʂ̃������Ɉڂ�A��쓮���N�����Ă��܂����Ƃł���B

int main(int args,char *argv[]){
	int value=5;
	char buffer_one[8],buffer_two[8];

	strcpy(buffer_one,"one");
	strcpy(buffer_two,"two");
	printf("[�O] buffer_two��%p�ɂ���A���̒l��'\%s\'�ł��B\n",buffer_two,buffer_two);
	printf("[�O] buffer_one��%p�ɂ���A���̒l��'\%s\'�ł��B\n",buffer_one,buffer_one);
	printf("[�O] value ��%p�ɂ���A���̒l��%d(0x%08x)�ł��B\n",&value,value,value);

	printf("\n[STRCPY] %d�o�C�g��buffer_two�ɃR�s�[���܂��B\n\n",strlen(argv[1]));
	strcpy(buffer_two,argv[1]);

	printf("[��]buffer_two��%d�ɂ��肻�̒l��'\%s\'�ł��B\n",buffer_two,buffer_two);
	printf("[��]buffer_one��%d�ɂ��肻�̒l��'\%s\'�ł��B\n",buffer_one,buffer_one);
	printf("[��] value ��%p�ɂ���A���̒l��%d(0x%08x)�ł��B\n",&value,value,value);



return 0;
}
