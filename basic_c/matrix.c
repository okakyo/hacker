#include<stdio.h>
#include<math.h>

double check(,metrix[],double a,double b){
return metrix[a][b]*metrix[a+1][b+1]-metrix[a+1][b]*metrix[a][b+1];
}

void gyaku(double metrix[],double *ans[]){
	double abs=0;
	for(int i=0;i<3;i++)
		for(int j=1;j<3;j++){
		abs+=metrix[0][i]*check(metrix,i,j);
		}
}

int main(){
	double metrix[3][3],ans[3][3];
	printf("行列を入力してください。:");
	for(int i=0;i<3;i++)
		scanf("%lf%lf%lf",&metrix[i][0],&metrix[i][1],&metrix[i][2]);
	gyaku(metrix,&ans);
	printf("入力された行列の逆行列は、[");
	for(int i=0;i<3;i++)
		pritnf("%lf%lf%lf\n",ans[i][0],ans[i][1],ans[i][2]);

	printf("]です。\n");
	

return 0;
}
