/*************************************************************************
	> File Name: StackTest_1.c
	> Author:liutong 
	> Mail: 
	> Created Time: Mon 10 Apr 2017 09:44:07 AM DST
 ************************************************************************/

#include<stdio.h>


#define ok 1
#define error 0
#define true  1
#define false 0

#define MAXSIZE 20

//栈的结构定义
typedef struct{
	int data[MAXSIZE];
	int top;
}SqStack;

//栈的初始化
int InitStack(SqStack *S){
	if(S->top = -1)
		return ok;
}

//栈中数据数量
int StackLength(SqStack S){
	return S.top + 1;
}

//入栈push
int InsertStack(SqStack *S,int e){
	if(S->top == MAXSIZE-1)      //注意等于号的使用
		return error;
	S->top++;
	S->data[S->top] = e;
	return ok;
}

//出栈Pop
int Pop(SqStack *S,int *e){
	if(S->top == -1)
		return error;
	*e = S->data[S->top];
	S->top--;
	return *e;
}
//打印栈中元素
void PrintStack(SqStack S){
	printf("栈中的元素依次为:");
	while(S.top > -1){
		printf("%d ",S.data[S.top]);
		S.top--;
		}
	printf("\n");
}

/* 把S置为空栈 */
int ClearStack(SqStack *S)
{ 
        S->top=-1;
        return ok;
}

int main(){
	int j,e;
	SqStack S;
	InitStack(&S);
	ClearStack(&S);
	printf("初始化后栈的长度：%d\n",StackLength(S));
	if(InitStack(&S)==ok)
                for(j=1;j<=10;j++)
                        InsertStack(&S,j);
	printf("入栈后栈的长度：%d\n",StackLength(S));
	PrintStack(S);
	Pop(&S,&e);
	printf("pop后栈的长度：%d\n",StackLength(S));
	printf("pop de data：%d\n",e);
	PrintStack(S);
	
	return 0;
}

