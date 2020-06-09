#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void sol1(int mat[9]);
void sol2(int mat[9]);

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int nums[9]={8,7,6,5,4,3,2,1};
	//int nums1[8]={87,65,43,21,76,54,32};
	sol1(nums);
	printf("\n");
	sol2(nums);
	printf("\n");
	
	return 0;
}

void sol1(int mat[9]){ // lush mono me +,- , xwris sunenwseis arithmwn
	int i,j,res=8;
	printf("8");
	for(i=1;i<8;i++){
		if(res<36){
			res=res+mat[i];
			printf(" + %d",mat[i]);
		}
		else{
			res=res-mat[i];
			printf(" - %d",mat[i]);
		}
	}
	if(res==36){
		printf(" = 36 ");
	}
	else{
		printf(" !=36 ");
	}
}



void sol2(int mat[9]){ // lush me oles tis prakseis , xwris sunenwseis arithmwn
	int i,j,ch,c=1;
	float res,res1,res2;
	char p[8];
	for(j=0;j<10000;j++){
		res=8;
		res1=1;
		res2=1;
		for(i=1;i<8;i++){
				ch=rand()%4;
				if(ch==0){
					res=res-mat[i];
					p[i]='-';
					c=1;
					res1=1;
					res2=1;
				}
				else if(ch==1&&p[i-c]=='+'){
					if(c==1){
						res1=mat[i]*mat[i-1];
						res=res+res1-mat[i-1];
						c++;
					}
					else{
						res2=res1;
						res1=res1*mat[i];
						res=res+res1-res2;
						c++;
					}
					p[i]='*';
				}
				else if(ch==2&&p[i-c]=='-'){
					if(c==1){
						res1=mat[i-1]/mat[i];
						res=res-res1+mat[i-1];
						c++;
					}
					else{
						res2=res1;
						res1=res1/mat[i];
						res=res-res1+res2;
						c++;
					}
					p[i]='/';
				}
				else if(ch==1&&p[i-c]=='-'){
					if(c==1){
						res1=mat[i]*mat[i-1];
						res=res-res1+mat[i-1];
						c++;
					}
					else{
						res2=res1;
						res1=res1*mat[i];
						res=res-res1+res2;
						c++;
					}
					p[i]='*';
				}
				else if(ch==2&&p[i-c]=='+'){
					if(c==1){
						res1=mat[i-1]/mat[i];
						res=res+res1-mat[i-1];
						c++;
					}
					else{
						res2=res1;
						res1=res1/mat[i];
						res=res+res1-res2;
						c++;
					}
					p[i]='/';
				}
				else{
					res=res+mat[i];
					p[i]='+';
					c=1;
					res1=1;
					res2=1;	
				}
		}
		if(res == 36){
			printf("8 %c 7 %c 6 %c 5 %c 4 %c 3 %c 2 %c 1 == 36 \n",p[1],p[2],p[3],p[4],p[5],p[6],p[7]);
		}

	}
}




















