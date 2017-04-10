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

//ջ�Ľṹ����
typedef struct{
	int data[MAXSIZE];
	int top;
}SqStack;

//ջ�ĳ�ʼ��
int InitStack(SqStack *S){
	if(S->top = -1)
		return ok;
}

//ջ����������
int StackLength(SqStack S){
	return S.top + 1;
}

//��ջpush
int InsertStack(SqStack *S,int e){
	if(S->top == MAXSIZE-1)      //ע����ںŵ�ʹ��
		return error;
	S->top++;
	S->data[S->top] = e;
	return ok;
}

//��ջPop
int Pop(SqStack *S,int *e){
	if(S->top == -1)
		return error;
	*e = S->data[S->top];
	S->top--;
	return *e;
}
//��ӡջ��Ԫ��
void PrintStack(SqStack S){
	printf("ջ�е�Ԫ������Ϊ:");
	while(S.top > -1){
		printf("%d ",S.data[S.top]);
		S.top--;
		}
	printf("\n");
}

/* ��S��Ϊ��ջ */
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
	printf("��ʼ����ջ�ĳ��ȣ�%d\n",StackLength(S));
	if(InitStack(&S)==ok)
                for(j=1;j<=10;j++)
                        InsertStack(&S,j);
	printf("��ջ��ջ�ĳ��ȣ�%d\n",StackLength(S));
	PrintStack(S);
	Pop(&S,&e);
	printf("pop��ջ�ĳ��ȣ�%d\n",StackLength(S));
	printf("pop de data��%d\n",e);
	PrintStack(S);
	
	return 0;
}

