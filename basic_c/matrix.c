#include<stdio.h>
#include<math.h>

int main(){
	double a[3][3];
	double inv_a[3][3]; 
	double buf; 
	int i,j,k; 
	int n=3;  
	
	printf("�s�����͂��Ă��������B�F\n");
	for (i=0;i<n;i++){
		printf("%d�s�ځF",i+1);
		scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		inv_a[i][j]=(i==j)?1.0:0.0;
		}
	}
	for(i=0;i<n;i++){
		buf=1/a[i][i];
		for(j=0;j<n;j++){
			a[i][j]*=buf;
			inv_a[i][j]*=buf;
		}	
		for(j=0;j<n;j++){
			if(i!=j){
			  buf=a[j][i];
			    for(k=0;k<n;k++){
		       a[j][k]-=a[i][k]*buf;
			 inv_a[j][k]-=inv_a[i][k]*buf;
			    }
		     }
	    }
	}
	printf("�t�s��́A[");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		printf(" %lf",inv_a[i][j]);
		}
	printf("\n");
	}
	printf("]�ł��B");
}
