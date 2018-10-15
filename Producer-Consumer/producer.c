#include<stdio.h>
#include<stdlib.h>


int mutex=1,full=0,empty,x=0,buffer[100],size;
void main() {
	int n;
	void producer();                             //Function Declaration
	void consumer();
	int wait(int);
	int signal(int);
	printf("Enter buffer Size :");
	scanf("%d", &size);
	empty = size;
	printf("\nProducer-Consumer Problem\n");
	while(1) {
		printf("\n1.Producer\n2.Consumer\n3.Exit\n");
		printf("Choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				if((mutex==1)&&(empty!=0))
					producer();
				else
					printf("Buffer full\n");
			break;
			case 2:
				if((mutex==1)&&(full!=0))
					consumer();
				else
					printf("Buffer empty\n");
			break;
			case 3:
				exit(0);
			break;
		}
	}

}
int wait(int s) {
	return(--s);
}

int signal(int s) {
	return(++s);
}

void producer() {
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("Enter Value: ");
	scanf("%d",&buffer[x]);
	printf("Producer produced the item %d\n",buffer[x]);
	x++;
	mutex=signal(mutex);
}

void consumer() {
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("Consumer consumed the item %d\n",buffer[x-1]);
	x--;
	mutex=signal(mutex);
}
