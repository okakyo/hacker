#include<stdio.h>
#include<math.h>

int  kanzen(int i){
	int ans=1;
	int N=floor(sqrt(i));
	for(int j=2;j<=N;j++){
		if(i%j==0){
			if(j==i/j)
				ans+=j;
			else
				ans=ans+j+i/j;
				
		}
	}
	if(ans==i)
		return ans;
}

int main(){
	for(int i=2;i<=10000;i++){
		int a=0;
		a=kanzen(i);
		printf("%d\n",a);
	}

return 0;
}
