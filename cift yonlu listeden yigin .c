#include <stdio.h>
#include <stdlib.h>

struct dll{
	struct dll * prev;
	int data;
	struct dll * next;
};

typedef struct dll node;
node * start;
node * getnode(){
	node * newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Data Giriniz\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}

void push(node * newnode){
	node * temp;
	temp=start;
	if(temp==NULL){
		start=newnode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}

node * pop(){
	node * temp;
	temp=start;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->prev->next=NULL;
	return temp;
}

void display(){
	node * temp;
	temp=start;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}

int main() {
	int secim;
	node * newnode;
	while(1){
menu:
		printf("_________________________________________________\n");
		printf("YIGINA ELEMAN EKLEME MENUSUNE HOS GELDINIZ\n");
		printf("_________________________________________________\n");
		printf("1-Yigina Ekleme Yap\n");
		printf("2-Yigindan Cikarma Yap\n");
		printf("3-Goruntule\n");
		printf("4-Cikis\n");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				newnode=getnode();
				push(newnode);
				break;
			case 2:
				newnode=pop();
				free(newnode);
				break;
			case 3:
				display();
				printf("\n");
				break;
			case 4:
				exit(0);
			default:
				goto menu;
		}
}
}
