#include <stdio.h>

#include <stdlib.h>

void main(){

int ch=1,c;

setbuf(stdout,NULL);

while(ch==1){

   printf("Enter the choice 1)FCFS 2)scan 3)cscan\n");

   scanf("%d",&c);

   switch(c){

   case 1:{

	   printf("*****FCFS DISK SCHEDULING*****\n");

	   int head,a[20],i,distance,n,seektime=0;

	   printf("Enter the head:\n");

	   scanf("%d",&head);

	   printf("Enter the number of disk requests:\n");

	   scanf("%d",&n);

	   printf("Enter the disk requests:\n");

	   for(i=1;i<=n;i++){

	   scanf("%d",&a[i]);

	   a[0]=head;

	   }



	   for(i=0;i<n;i++){

	   distance=(a[i]>a[i+1])?a[i]-a[i+1]:a[i+1]-a[i];

	   printf("Head movement from %d to %d:%d\n",a[i],a[i+1],distance);

	   seektime=seektime+distance;

	   }

	   printf("Total seektime is:%d\n",seektime);

	   break;

   }



   case 2:{

	   printf("**********SCAN***********\n");

int queue[25],n,head,i,j,seek=0,maxrange,diff,temp,queue1[20],queue2[20],temp1=0,temp2=0;

printf("Enter the maxrange of disk:\n");

scanf("%d",&maxrange);

printf("Enter the no of requests:\n");

scanf("%d",&n);

printf("Enter the initial headposition:\n");

scanf("%d",&head);

printf("Enter the requests:\n");

for(i=1;i<=n;i++){

scanf("%d",&temp);

if(temp>head)

{

queue1[temp1]=temp;

temp1++;

}

else{

queue2[temp2]=temp;

temp2++;

}}

for(i=0;i<temp1-1;i++){

for(j=i+1;j<temp1;j++){

if(queue1[i]>queue1[j])

{

temp=queue1[i];

queue1[i]=queue1[j];

queue1[j]=temp;

}}}

for(i=0;i<temp2-1;i++){

for(j=i+1;j<temp2;j++){

if(queue2[i]<queue2[j]){

temp=queue2[i];

queue2[i]=queue2[j];

queue2[j]=temp;

}}}

queue[0]=head;

int index=1;

for(i=0;i<temp1;i++){

queue[index]=queue1[i];

index++;

}

queue[index]=maxrange;

index++;

for(i=0;i<temp2;i++){

queue[index]=queue2[i];

index++;

}

for(j=0;j<=n;j++){

diff=abs(queue[j+1]-queue[j]);

seek=seek+diff;

printf("Disk head moves from position %d to %d with seek %d\n",queue[j],queue[j+1],diff);

}

printf("Total seek time=%d\n",seek);

break;

   }

   case 3:{

	   printf("*********CSCAN************\n");

	   int q1[50],q2[50],queue[50],seektime=0,head,maxsize,n,i,temp,a1=0,a2=0,a=0,difference,j;

	   printf("Enter the head position:");

	   scanf("%d",&head);

	   printf("Enter the size of the disk:");

	   scanf("%d",&maxsize);

	   printf("Enter the no. of disk requests:");

	   scanf("%d",&n);

	   printf("Enter the queue requests:");

	   for(i=0;i<n;i++){

	    scanf("%d",&temp);

	    if(temp>head){

	     q1[a1]=temp;

	     a1++;

	    }

	    else{

	     q2[a2]=temp;

	     a2++;

	    }

	   }

	   for(i=0;i<a1;i++){

	    for(j=i+1;j<a1;j++){

	     if(q1[i]>q1[j]){

	      temp=q1[i];

	      q1[i]=q1[j];

	      q1[j]=temp;

	     }

	    }

	   }

	   for(i=0;i<a2;i++){

	    for(j=i+1;j<a2;j++){

	     if(q2[i]>q2[j]){

	      temp=q2[i];

	      q2[i]=q2[j];

	      q2[j]=temp;

	     }

	    }

	   }

	   queue[a]=head;

	   a++;

	   for(i=0;i<a1;i++){

	    queue[a]=q1[i];

	    a++;

	   }

	   queue[a]=maxsize-1;

	   a++;

	   queue[a]=0;

	   a++;

	   for(i=0;i<a2;i++){

	    queue[a]=q2[i];

	    a++;

	   }

	   for(i=0;i<(a-1);i++){

	    difference=abs(queue[i+1]-queue[i]);

	    seektime+=difference;

	   // printf(" seek time=%d\n",seektime);

	    printf("Head movement from %d to %d with difference %d\n",queue[i],queue[i+1],difference);

	    }

	    printf("Total seek time=%d\n",seektime);

	    printf("------------------------------------------\n");

	   }

   break;

   case 4:{

	   exit(0);

}

   }}}

