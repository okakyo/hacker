#include<stdio.h>
#include<stdlib.h>
#define DATA 5000

void change(int *x,int *y){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void swap(int n,int N[],int x[],int y[],int z[],w[]){
	for(i=0,i<n;i++){
		for(j=i+1;j<n;j++){
			if(N[i]<N[j]){
				change(&x[i],&x[j]);
				change(&y[i],&y[j]);
				change(&z[i],&z[j]);
				change(&w[i],&w[j]);

		}}
	}
}

int main(){
	FILE *fp;
	int i,n,num;
	int Num[DATA],Eng[DATA],Math[DATA],Jap[DATA],Sum[DATA];
	fp=fopen("seiseki.dat","r");
	n=0;
	for (i=0;i<DATA;i++){
		if(fscanf(fp,"%d,%d,%d,%d",&Num[i],&Jap[i],&Math[i],&Eng[i])==EOF)break;
		n++;
		Sum[i]=Jap[i]+Math[i]+Eng[i];	
	}
	fclose(fp);
	printf("成績順に並べる番号を1〜４で入力してください。：");
	scanf("%d",&num);
	switch(num){
		case 1: swap(n,Jap,Num,Jap,Math,Eng); break;
		case 2: swap(n,Math,Num,Jap,Math.Eng); break;
		case 3: swap(n,Eng,Num,Jap,Math,Eng); break;
		case 4: swap(n,Sum,Num,Jap,Math,Eng); break;
		default:
			printf("１〜４で入力してください。");
			exit(0);

	}
	for(int i=0;i<n;i++)
		printf("%d,%d,%d,%d\n",Num[i],Jap[i],Math[i],Eng[i]);
return 0;
}
