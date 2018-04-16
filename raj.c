#include<semaphore.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdio.h>
#define MAX_RESOURCES 7
sem_t m1;
sem_t m2;
int available_resources=MAX_RESOURCES;
/*decrease available resources by count resources*/
void *decrease_count(void *coun)
{	int *count =coun;
    	sem_wait(&m1);
		while(available_resources<*count)
		printf("\n>>>>>>> Client is Waiting to get %d Licences Because Available Resource is %d <<<<<<<",*count,available_resources);
		available_resources-=*count;
		printf("\n:::::: Number of Licence Given to new Client is %d .\n Now Remaining Licences are %d :::::: \n ",*count,available_resources);
		sem_post(&m1);
		increase_count(*count);
}
int increase_count(int coun)
{     	sem_wait(&m2);  
		int count =coun;
		available_resources+=count;
		printf("\n:::::: Number of Licence Expired are %d . \n Now Availability Of Resources Increased to %d ::::::\n",count,available_resources);
		sem_post(&m2);
		
}
int main()
{   
	//printf("\n                       :::::::::::::::::::::::::::::::::::::");
  // printf("\n                       ::                                 ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @      WELCOME TO     @     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @  LICENSE Progrm-->> @     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
 //  printf("\n                       ::                                 ::");
 //  printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
 getch();
	sem_init(&m1,0,1);
	sem_init(&m2,0,1);
	pthread_t no_of_client[100];
	int count[100];
	int clients,i;
	printf("\n\n\n\t Enter the Number of Clients you want:\t");
	scanf("%d",&clients);
	for(i=0;i<clients;i++)
	{
		printf("\n Enter Number of Licence Client %d wants :\t",i+1);
		scanf("%d",&count[i]);
		if(count[i]>available_resources)
		{
		printf("\n:::::: #####LIMIT EXCEDDED , PLEASE ENTER IN LIMIT ::::::\n");
		printf("\n:::::: #####LIMIT EXCEDDED , PLEASE ENTER IN LIMIT ::::::\n");
		printf("\n:::::: #####LIMIT EXCEDDED , PLEASE ENTER IN LIMIT ::::::\n");
		printf("\n:::::: #####LIMIT EXCEDDED , PLEASE ENTER IN LIMIT ::::::\n");
		i=i-1;
	}
	}
	for(i=0;i<clients;i++)
	{
		pthread_create(&no_of_client[i],NULL,decrease_count,&count[i]);
	}
	for( i=0;i<clients;i++)
	{
		pthread_join(no_of_client[i],NULL);
	}
}

