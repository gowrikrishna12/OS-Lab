#include<stdio.h>
void main()
{
 int m_no,p_no;    
  printf("Enter the number of menory blocks\n");
  scanf("%d",&m_no);
  printf("Enter the number of processes\n");
  scanf("%d",&p_no);
 struct mem{
   int size;
   int alloc;
  }m[m_no];
    struct Process{
   int psize;
   int flag;
  }p[p_no];
  printf("Enter the size of memory blocks:\n");
 for(int i=0;i<m_no;i++)
 {
   scanf("%d",&m[i].size);
 }
 printf("Enter the size of processes\n");
   for(int i=0;i<p_no;i++)
 {
   scanf("%d",&p[i].psize);
 }
 int temp;
 for(int i=0;i<m_no;i++)
 {
  for(int j=0;j<=i;j++)
  {
   if(m[i].size>m[j].size)
   {
    temp=m[i].size;
    m[i].size=m[j].size;
    m[j].size=temp;
   }  
  }
 }
 for(int i=0;i<p_no;i++)
 {
  p[i].flag=0;
 
 }
  for(int i=0;i<m_no;i++)
 {
  m[i].alloc=0;
 
 }
 for(int i=0;i<p_no;i++)
 {
   for(int j=0;j<m_no;j++)
   {
     if(p[i].flag==0)
     {
     if(p[i].psize<=m[j].size)
     {
      if(m[j].alloc==1)
      {
       continue;
      }
      else
      {
        m[j].alloc=1;
        p[i].flag=1;
        printf("Process of size %d is allocated in memory location %d\n",p[i].psize,m[j].size);  
      }
     }
    }
   }
   }
   for(int i=0;i<p_no;i++)
   {
    if(p[i].flag==0)
    {
     printf("No space for process of size %d\n",p[i].psize);
    }
   }
  }
