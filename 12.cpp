#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
#define ERROR -1
#define OK 0
#define FALSE 0
#define TRUE 1
typedef enum{RIGHT,DOWN,LEFT,UP}Direction;
typedef enum{YES,NO}MarkTag;
typedef struct position{
	int x;int y;
}Position;
typedef struct{
	int order;
	Position seat;
	Direction di;
}SElemType;
typedef struct{
	SElemType *elem;
	int top;
}Stack;
char maze[MAXSIZE+2][MAXSIZE-2];
int InitStack(Stack *S){
	S->elem=(SElemType *)malloc(MAXSIZE*MAXSIZE*sizeof(SElemType));
	if(!S->elem)return ERROR;
	S->top=0;return OK;
}/* InitStack */
int Push(Stack *S,SElemType e){
	if(S->top>=MAXSIZE*MAXSIZE) return ERROR;
	S->elem[S->top++]=e; return OK;
}/* Push */
int Pop(Stack *S,SElemType *e){
	if(S->top<=0) return ERROR;
	*e = S->elem[--S->top];return OK;
}/* Pop */
int Empty(Stack S){
	if(S.top==0) return TRUE;
	return FALSE;
}/* Empty */

int createMaze(char *filename,Position *startpos,Position *endpos){
	FILE *fp;
	int i,j,rows,cols,temp;
	Position start,end;
	fp=fopen(filename,"r");
	if(!fp){
		printf("open file %s error! \n",filename);
		return ERROR;
	}
	if(!feof(fp)){
		fscanf(fp,"%d %d",&rows,&cols);
		fscanf(fp,"%d %d",&start.x,&start.y);
		fscanf(fp,"%d %d",&end.x,&end.y);
	}
	for(i=1;i<=rows;i++)
		for(j=1;j<=cols;j++){
			fscanf(fp,"%d",&temp);maze[i][j]=48+temp;
		}
	fclose(fp);
	/* 在迷宫四周加墙壁 */
	for(i=0,j=0;i<=rows+1;i++) maze[i][j]='1';
	for(i=0,j=cols+1;i<=rows+1;i++) maze[i][j]='1';
	for(i=0,j=0;j<=cols+1;j++) maze[i][j]='1';
	for(i=rows+1,j=0;j<cols+1;j++) maze[i][j]='1';
	*startpos=start;*endpos=end;
	return OK;
}/* createMaze */
int canPass(Position curpos){
	if(maze[curpos.x][curpos.y]=='0') return TRUE;
	return FALSE;
}/* canPass */
