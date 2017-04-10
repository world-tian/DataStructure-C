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

 /* 线性表的静态链表存储结构 */
 typedef struct{
     char data;
     int cur;

 }Component,StaticLinkList[MAXSIZE];
 //也就是定义了两个自定义数据类型Component和staticlist其中Component类型就是一个有两个int成员data和cur的结构体
 //而staticlist类型则是一个有100个元素的结构体数组这种数组的每个元素都是一个Component类型的结构体
 
 /********初始化********/
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
 
 /******定义内存分配函数 类似malloc*********/
 int Malloc_SSL(StaticLinkList space){
	 int i = space[0].cur;
	 if(space[0].cur)
		 space[0].cur = space[i].cur;
	 return i;
 }
 
/***********定义释放函数 类似free()***************/
// int Free_SSL(StaticLinklist space,int k){
	
// }

/********在L中i的元素之前插入e**********/
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

//删除元素
int DeleElement(StaticLinkList L,int i,char *e){
	int j,k;
	j = MAXSIZE -1;
	if(i<1 || i>ListLength(L)-1)
		return error;
	for(k=0;k<i-1;k++){
		j = L(k).cur;
	}
}

//打印
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
	 printf("初始化L后：L.length=%d\n",ListLength(L));
	 StaticListInsert(L,1,'A');
	 StaticListInsert(L,1,'B');
	 StaticListInsert(L,1,'C');
	 StaticListInsert(L,1,'D');
	 StaticListInsert(L,1,'E');
	 printf("初始化L后：L.length=%d\n",ListLength(L));
	 PrintList(L);
     printf("\n");
     return 0;
 }
 
