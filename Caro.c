C-DEMO Caro
====
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define WIDTH 15
#define HEIGHT 50
#define _C 254
int scanInt(int A)
{
	int i,n;
	fflush(stdin);
	i=scanf("%d",&n);
	while(i==0||(n<0||n>A))
	{
		printf("\nBan da nhap sai!");
		printf("\nNhap =");
		fflush(stdin);
		i=scanf("%d",&n);
	}
	return n;
}
void khoitao(char A[WIDTH][HEIGHT])
{
	int i,j;
	for(i=0;i<WIDTH;i++)
	for(j=0;j<HEIGHT;j++)
	A[i][j]=_C;
	return;
}
void caro(char A[WIDTH][HEIGHT])
{
	int i,j;
	printf("\n_________[GAME Demo CARO]__________\n");
	for(i=0;i<WIDTH;i++)
	{
		printf("\n");
		for(j=0;j<HEIGHT;j++)
		printf("%c",A[i][j]);
	}
	return;
}
int kiemtra(char A[WIDTH][HEIGHT],int x,int y,char c)
{
	int i,j,dem1=0,dem2=1;
	//duyet theo cheo chinh
	for(i=x-1,j=y-1;i>=0&&j>=0&&A[i][j]==c;i--,j--)
	dem1++;
	for(i=x+1,j=y+1;i<WIDTH&&j<HEIGHT&&A[i][j]==c;i++,j++)
	dem2++;
	if(dem1+dem2>=5) return 1;
	//duyet theo cheo phu
	dem1=0;dem2=1;
	for(i=x+1,j=y-1;i<WIDTH&&j>=0&&A[i][j]==c;i++,j--)
	dem1++;
	for(i=x-1,j=y+1;i>=0&&j<HEIGHT&&A[i][j]==c;i--,j++)
	dem2++;
	if(dem1+dem2>=5) return 1;
	//duyet theo chieu doc
	dem1=0,dem2=1;
	for(i=x-1,j=y;i>=0&&A[i][j]==c;i--)
	dem1++;
	for(i=x+1,j=y;i<WIDTH&&A[i][j]==c;i++)
	dem2++;
	if(dem1+dem2>=5) return 1;
	//duyet theo chieu ngang
	dem1=0;dem2=1;
	for(i=x,j=y-1;j>=0&&A[i][j]==c;j--)
	dem1++;
	for(i=x,j=y+1;j<HEIGHT&&A[i][j]==c;j++)
	dem2++;
	if(dem1+dem2>=5) return 1;
	return 0;
}
void nhap(int *x,int *y, char c)
{
	fflush(stdin);
	printf("\nNhap vi tri %c[x,y], khoang X[0->%d], Y[0->%d]:",c,WIDTH,HEIGHT);
	printf("\nX=");*x=scanInt(WIDTH);
	printf("\nY=");*y=scanInt(WIDTH);
	return;
}
int main(void)
{
	int x,y;
	char A[WIDTH][HEIGHT],c='X';
	khoitao(A);
	while(1){
		system("cls");
		caro(A);
		nhap(&x,&y,c);
		while(A[x][y]=='X'||A[x][y]=='O'){
			printf("\nBan da danh vao o nay roi!");
			nhap(&x,&y,c);
		}
		A[x][y]=c;
		if(kiemtra(A,x,y,c)){
			system("cls");
			caro(A);
			printf("\nYou win!");
			getch();
			return 0;
		}
		if(c=='X')c='O';
		else c='X';
	}
	getch();
	return 0;
}
C/C++
