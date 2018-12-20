#include<stdio.h>
#include<math.h>

double check(i,j){
return a[i%3][(i+1)%3]*a[(i+1)%3][(i+2)%3]-a[(i+1)%3][(i+1)%3]*a[2][(i+2)%3]
}

void gyaku(double a[],double *ans[]){
	double abs=0;
	for(int i=0;i<3;i++)
		abs+=(a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]);
	
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
