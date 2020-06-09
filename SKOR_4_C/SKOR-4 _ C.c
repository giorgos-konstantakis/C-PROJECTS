#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(char mat[7][7]);    // Printing game's table
int scan();                    // Demand the player's move
int nikhths(char mat[7][7]);   // Checks win for player or PC
int orizontia(char mat[7][7]); // Functions orizontia(),katheta(),diagonia1() kai diagonia2() , check the winning terms and are combined in function nikhths 
int katheta(char mat[7][7]);   // 
int diagonia1(char mat[7][7]); // 
int diagonia2(char mat[7][7]); //
int isopalia(char mat[7][7]); // Checks if the game is a DRAW 
int NikhYpologisth(char mat[7][7]);// Checks if PC can make a move to win the game , and if TRUE the game is over
int NikhPaixth(char mat[7][7]); // Checks if player has a move to win the game , so it commands PC to prevent player's win
int StrategyYpologisth(char mat[7][7]); // This function is the "PC" , which has a strategy to follow to win the game


int main(int argc, char *argv[]) {
	int i,j,s,c=0;
	char mat[7][7];
	
	srand(time(NULL));
	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			mat[i][j]='-';
		}
	}
	
	
	for(i=0;i<500;i++){
		if(c==0){
			s=scan();
			if(mat[0][s]!='-'){
				printf("You are not allowed to use column %d because it is full !! \n",s);
				continue;
			}
			for(j=0;j<7;j++){
				if(mat[6][s]=='-'){
					mat[6][s]='+';
					c++;
					break;
				}
				if(mat[j][s]=='-' && mat[j+1][s]!='-'){
					mat[j][s]='+';
					c++;
					break;
				}
			}
		}
		else{
			printf("PC's turn \n");
			s=NikhYpologisth(mat);
			if(s==7){
				s=NikhPaixth(mat);
			}
			if(s==8){
				s=StrategyYpologisth(mat);
			}
			if(s==9){
				start:
				s=rand()%7;
			}
			if(mat[0][s]!='-'){
				goto start;
			}
			for(j=0;j<7;j++){
				if(mat[6][s]=='-'){
					mat[6][s]='*';
					c--;
					break;
				}
				if(mat[j][s]=='-' && mat[j+1][s]!='-') {
					mat[j][s]='*';
					c--;
					break;
				}
			}
		}
		print(mat);
		printf("\n");
		if(nikhths(mat)==1){
			printf("You are the winner , CONGRATULATIONS !!");
			break;
		}
		if(nikhths(mat)==2){
			printf("PC is the winner !!");
			break;
		}
		if(isopalia(mat)==1){
			printf("We have a DRAW");
			break;
		}
	}
	return 0;
}


void print(char mat[7][7]){
	int x,y;
	printf("\n  0  1  2  3  4  5  6  \n");
	for(x=0;x<7;x++){
		printf("%d",x);
		for(y=0;y<7;y++){
			printf(" %c ",mat[x][y]);
		}
		printf("\n");
	}
}

int scan(){
	int s;
	printf("Choose column to play(0 ews 6)  : ");
	scanf("%d",&s);
	return s;
}

int nikhths(char mat[7][7]){
	int result;
	if(orizontia(mat)==1 || katheta(mat)==1 || diagonia1(mat)==1 || diagonia2(mat)==1){
		result=1;
	}
	else if(orizontia(mat)==2 || katheta(mat)==2 || diagonia1(mat)==2 || diagonia2(mat)==2){
		result=2;
	}
	else{
		result=0;
	}
	return result;
}

int orizontia(char mat[7][7]){
	int a,b;
	for(a=0;a<7;a++){
		for(b=0;b<4;b++){
			if(mat[a][b]=='+' && mat[a][b+1]=='+' && mat[a][b+2]=='+' && mat[a][b+3]=='+'){
				return 1;
			}
			if(mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a][b+2]=='*' && mat[a][b+3]=='*'){
				return 2;
			}
		}
	}
	return 0;
}

int katheta(char mat[7][7]){
	int a,b;
	for(b=0;b<7;b++){
		for(a=0;a<4;a++){
			if(mat[a][b]=='+' && mat[a+1][b]=='+' && mat[a+2][b]=='+' && mat[a+3][b]=='+'){
				return 1;
			}
			if(mat[a][b]=='*' && mat[a+1][b]=='*' && mat[a+2][b]=='*' && mat[a+3][b]=='*'){
				return 2;
			}
		}
	}
	return 0;
}

int diagonia1(char mat[7][7]){ // diagonally from left to right
	int a,b;
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			if(mat[a][b]=='+' && mat[a+1][b+1]=='+' && mat[a+2][b+2]=='+' && mat[a+3][b+3]=='+'){
				return 1;	
			}
			if(mat[a][b]=='*' && mat[a+1][b+1]=='*' && mat[a+2][b+2]=='*' && mat[a+3][b+3]=='*'){
				return 2;	
			}
		}
	}
	return 0;
}

int diagonia2(char mat[7][7]){ // diagonally from right to left
	int a,b;
	for(a=0;a<4;a++){
		for(b=6;b>2;b--){
			if(mat[a][b]=='+' && mat[a+1][b-1]=='+' && mat[a+2][b-2]=='+' && mat[a+3][b-3]=='+'){
				return 1;	
			}
			if(mat[a][b]=='*' && mat[a+1][b-1]=='*' && mat[a+2][b-2]=='*' && mat[a+3][b-3]=='*'){
				return 2;	
			}
		}
	}
	return 0;
}


int isopalia(char mat[7][7]){
	if(mat[0][0]!='-' && mat[0][1]!='-' && mat[0][2]!='-' && mat[0][3]!='-' && mat[0][4]!='-' && mat[0][5]!='-' && mat[0][6]!='-' && nikhths(mat)==0){
		return 1;
	}
	return 0;
}


int NikhYpologisth(char mat[7][7]){
	int a,b,s;
	
	for(a=0;a<7;a++){ // horizontal search
		for(b=0;b<4;b++){
			if(a<6){
				if(mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a][b+2]=='*' && mat[a+1][b+3]!='-' && mat[a][b+3]=='-'){
					s=b+3;
					return s;
				}
				if(mat[a][b]=='*' && mat[a][b+2]=='*' && mat[a][b+3]=='*' && mat[a+1][b+1]!='-' && mat[a][b+1]=='-'){
					s=b+1;
					return s;
				}
				if(mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a][b+3]=='*' && mat[a+1][b+2]!='-' && mat[a][b+2]=='-'){
					s=b+2;
					return s;
				}
				if(mat[a][b+2]=='*' && mat[a][b+1]=='*' && mat[a][b+3]=='*' && mat[a+1][b]!='-' && mat[a][b]=='-'){
					s=b;
					return s;
				}
			}
			if(a==6){
				if(mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a][b+2]=='*' && mat[a][b+3]=='-'){
					s=b+3;
					return s;
				}
				if(mat[a][b]=='*' && mat[a][b+2]=='*' && mat[a][b+3]=='*' && mat[a][b+1]=='-'){
					s=b+1;
					return s;
				}
				if(mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a][b+3]=='*' && mat[a][b+2]=='-'){
					s=b+2;
					return s;
				}
				if(mat[a][b+2]=='*' && mat[a][b+1]=='*' && mat[a][b+3]=='*' && mat[a][b]=='-'){
					s=b;
					return s;
				}
			}
		}
	}
	
	for(a=1;a<5;a++){ // vertical search
		for(b=0;b<7;b++){
			if(mat[a][b]=='*' && mat[a+1][b]=='*' && mat[a+2][b]=='*' && mat[a-1][b]=='-' ){
				s=b;
				return s;
			}
		}
	}
	
	for(a=0;a<4;a++){ // diagonally from left to right
		for(b=0;b<4;b++){
			if(mat[a][b]=='*' && mat[a+1][b+1]=='*' && mat[a+2][b+2]=='*' && mat[a+4][b+3]!='-' && mat[a+3][b+3]=='-'){
				s=b+3;
				return s;	
			}
			if(mat[a][b]=='*' && mat[a+1][b+1]=='*' && mat[a+3][b+3]=='*' && mat[a+3][b+2]!='-' && mat[a+2][b+2]=='-'){
				s=b+2;
				return s;	
			}
			if(mat[a][b]=='*' && mat[a+3][b+3]=='*' && mat[a+2][b+2]=='*' && mat[a+2][b+1]!='-' && mat[a+1][b+1]=='-'){
				s=b+1;
				return s;	
			}
			if(mat[a+3][b+3]=='*' && mat[a+1][b+1]=='*' && mat[a+2][b+2]=='*' && mat[a+1][b]!='-' && mat[a][b]=='-'){
				s=b;
				return s;	
			}
		}
	}
	
	for(a=0;a<4;a++){ // diagonally from right to left
		for(b=6;b>2;b--){
			if(mat[a][b]=='*' && mat[a+1][b-1]=='*' && mat[a+2][b-2]=='*' && mat[a+4][b-3]!='-' && mat[a+3][b-3]=='-'){
				s=b-3;
				return s;	
			}
			if(mat[a][b]=='*' && mat[a+1][b-1]=='*' && mat[a+3][b-3]=='*' && mat[a+3][b-2]!='-' && mat[a+2][b-2]=='-'){
				s=b-2;
				return s;	
			}
			if(mat[a][b]=='*' && mat[a+3][b-3]=='*' && mat[a+2][b-2]=='*' && mat[a+2][b-1]!='-' && mat[a+1][b-1]=='-'){
				s=b-1;
				return s;	
			}
			if(mat[a+3][b-3]=='*' && mat[a+1][b-1]=='*' && mat[a+2][b-2]=='*' && mat[a+1][b]!='-' && mat[a][b]=='-'){
				s=b;
				return s;	
			}
		}
	}
	
	return 7;
}

int NikhPaixth(char mat[7][7]){
	int a,b,s;
	
	for(a=0;a<7;a++){ // horizontal search
		for(b=0;b<4;b++){
			if(a<6){
				if(mat[a][b]=='+' && mat[a][b+1]=='+' && mat[a][b+2]=='+' && mat[a+1][b+3]!='-' && mat[a][b+3]=='-'){
					s=b+3;
					return s;
				}
				if(mat[a][b]=='+' && mat[a][b+2]=='+' && mat[a][b+3]=='+' && mat[a+1][b+1]!='-' && mat[a][b+1]=='-'){
					s=b+1;
					return s;
				}
				if(mat[a][b]=='+' && mat[a][b+1]=='+' && mat[a][b+3]=='+' && mat[a+1][b+2]!='-' && mat[a][b+2]=='-'){
					s=b+2;
					return s;
				}
				if(mat[a][b+2]=='+' && mat[a][b+1]=='+' && mat[a][b+3]=='+' && mat[a+1][b]!='-' && mat[a][b]=='-'){
					s=b;
					return s;
				}
			}
			if(a==6){
				if(mat[a][b]=='+' && mat[a][b+1]=='+' && mat[a][b+2]=='+' && mat[a][b+3]=='-'){
					s=b+3;
					return s;
				}
				if(mat[a][b]=='+' && mat[a][b+2]=='+' && mat[a][b+3]=='+' && mat[a][b+1]=='-'){
					s=b+1;
					return s;
				}
				if(mat[a][b]=='+' && mat[a][b+1]=='+' && mat[a][b+3]=='+' && mat[a][b+2]=='-'){
					s=b+2;
					return s;
				}
				if(mat[a][b+2]=='+' && mat[a][b+1]=='+' && mat[a][b+3]=='+' && mat[a][b]=='-'){
					s=b;
					return s;
				}
			}
		}
	}
	
	for(a=1;a<5;a++){ // vertical search
		for(b=0;b<7;b++){
			if(mat[a][b]=='+' && mat[a+1][b]=='+' && mat[a+2][b]=='+' && mat[a-1][b]=='-' ){
				s=b;
				return s;
			}
		}
	}
	
	for(a=0;a<4;a++){ // diagonally from left to right
		for(b=0;b<4;b++){
			if(mat[a][b]=='+' && mat[a+1][b+1]=='+' && mat[a+2][b+2]=='+' && mat[a+4][b+3]!='-' && mat[a+3][b+3]=='-'){
				s=b+3;
				return s;	
			}
			if(mat[a][b]=='+' && mat[a+1][b+1]=='+' && mat[a+3][b+3]=='+' && mat[a+3][b+2]!='-' && mat[a+2][b+2]=='-'){
				s=b+2;
				return s;	
			}
			if(mat[a][b]=='+' && mat[a+3][b+3]=='+' && mat[a+2][b+2]=='+' && mat[a+2][b+1]!='-' && mat[a+1][b+1]=='-'){
				s=b+1;
				return s;	
			}
			if(mat[a+3][b+3]=='+' && mat[a+1][b+1]=='+' && mat[a+2][b+2]=='+' && mat[a+1][b]!='-' && mat[a][b]=='-'){
				s=b;
				return s;	
			}
		}
	}
	
	for(a=0;a<4;a++){ // diagonally from right to left
		for(b=6;b>2;b--){
			if(mat[a][b]=='+' && mat[a+1][b-1]=='+' && mat[a+2][b-2]=='+' && mat[a+4][b-3]!='-' && mat[a+3][b-3]=='-'){
				s=b-3;
				return s;	
			}
			if(mat[a][b]=='+' && mat[a+1][b-1]=='+' && mat[a+3][b-3]=='+' && mat[a+3][b-2]!='-' && mat[a+2][b-2]=='-'){
				s=b-2;
				return s;	
			}
			if(mat[a][b]=='+' && mat[a+3][b-3]=='+' && mat[a+2][b-2]=='+' && mat[a+2][b-1]!='-' && mat[a+1][b-1]=='-'){
				s=b-1;
				return s;	
			}
			if(mat[a+3][b-3]=='+' && mat[a+1][b-1]=='+' && mat[a+2][b-2]=='+' && mat[a+1][b]!='-' && mat[a][b]=='-'){
				s=b;
				return s;	
			}
		}
	}
	
	return 8;
}

int StrategyYpologisth(char mat[7][7]){ // PC pseudo-strategy to defeat player
	int a,b,c;
	if(mat[6][3]=='-'){
		return 3;
	}
	if(mat[5][3]!='-' && mat[4][3]=='-'){
		return 3;
	}
	if(mat[6][4]!='-' && mat[5][4]=='-'){
		return 4;
	}
	if(mat[5][4]=='*' && mat[4][4]=='-'){
		return 4;
	}
	if(mat[4][3]=='-'  || mat[5][4]=='-' || mat[4][4]=='-'){
		c=rand()%2;
		return 3+c;
	}
	
	for(a=0;a<7;a++){
		for(b=3;b<5;b++){
			if(mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a+1][b+1]=='*' && mat[a+2][b]=='*'  && mat[a+1][b+2]!='-' ){
				return b+2;
			}
			if( mat[a][b]=='*' && mat[a][b+1]=='*' && mat[a+1][b+1]=='*' && mat[a+2][b]=='*' ){
				c=rand()%2;
				return c+5;
			}
		}
	}

	if(mat[6][2]!='-' && mat[5][2]=='-'){
		return 2;
	}
	if(mat[5][2]=='*' && mat[4][2]=='-'){
		return 2;
	}
	if(mat[4][3]=='-'  || mat[5][2]=='-' || mat[4][2]=='-'){
		c=rand()%2;
		return 3-c;
	}
	
	for(a=0;a<7;a++){
		for(b=3;b>1;b--){
			if(mat[a][b]=='*' && mat[a][b-1]=='*' && mat[a+1][b-1]=='*' && mat[a+2][b]=='*'  && mat[a+1][b-2]!='-' ){
				return b-2;
			}
			if( mat[a][b]=='*' && mat[a][b-1]=='*' && mat[a+1][b-1]=='*' && mat[a+2][b]=='*' ){
				c=rand()%2;
				return c;
			}
		}
	}
	
return 9;	
}













