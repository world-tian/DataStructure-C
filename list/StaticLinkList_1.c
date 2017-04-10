/*************************************************************************
	> File Name: StaticLinkList.c
	> Author:liutong 
	> Mail: 
	> Created Time: Sat 08 Apr 2017 01:32:28 PM DST
 ************************************************************************/

 #include "stdio.h"
 #include "stdlib.h"


 #define ok 1
 #define true 1
 #define error 0
 #define false 

 #define MAXSIZE 1000

 /* ���Ա�ľ�̬����洢�ṹ */
 typedef struct{
     char data;
     int cur;

 }Component,StaticLinkList[MAXSIZE];
 //Ҳ���Ƕ����������Զ�����������Component��staticlist����Component���;���һ��������int��Աdata��cur�Ľṹ��
 //��staticlist��������һ����100��Ԫ�صĽṹ���������������ÿ��Ԫ�ض���һ��Component���͵Ľṹ��
 
 /********��ʼ��********/
 int InitList(StaticLinkList space){
    int i;
        for(i=0;i<MAXSIZE-1;i++)
            space[i].cur = i+1;
        space[MAXSIZE-1].cur = 0;//
        return ok;
    }
	
int ListLength(StaticLinkList L){
	int i,j;
	j = 0;
	i = L[MAXSIZE-1].cur;
	while(i){
		i = L[i].cur;
		j++;
	}
	return j;
}
 
 /******�����ڴ���亯�� ����malloc*********/
 int Malloc_SSL(StaticLinkList space){
	 int i = space[0].cur;
	 if(space[0].cur)
		 space[0].cur = space[i].cur;
	 return i;
 }
 
/***********�����ͷź��� ����free()***************/
// int Free_SSL(StaticLinklist space,int k){
	
// }

/********��L��i��Ԫ��֮ǰ����e**********/
int StaticListInsert(StaticLinkList L,int i,char e){
	int j,k,l;
	k = MAXSIZE - 1;
	if(i<1 || i>ListLength(L)+1)
		return error;
	j = Malloc_SSL(L);
	if(j){
		L[j].data = e;
		for(l=1;l<i-1;l++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return ok;
	}
}

//ɾ��Ԫ��
int DeleElement(StaticLinkList L,int i,char *e){
	int j,k;
	j = MAXSIZE -1;
	if(i<1 || i>ListLength(L)-1)
		return error;
	for(k=0;k<i-1;k++){
		j = L(k).cur;
	}
}

//��ӡ
void PrintList(StaticLinkList L){
	int i = L[MAXSIZE-1].cur;
	while(i){
		printf("%c ",L[i].data);
		i = L[i].cur;
	}
}


 int main(){
	 StaticLinkList L;
	 int i;
	 InitList(L);
	 printf("��ʼ��L��L.length=%d\n",ListLength(L));
	 StaticListInsert(L,1,'A');
	 StaticListInsert(L,1,'B');
	 StaticListInsert(L,1,'C');
	 StaticListInsert(L,1,'D');
	 StaticListInsert(L,1,'E');
	 printf("��ʼ��L��L.length=%d\n",ListLength(L));
	 PrintList(L);
     printf("\n");
     return 0;
 }
 
