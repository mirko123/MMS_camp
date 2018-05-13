#ifndef _P1_H_
#define _P1_H_

 
void clear(unsigned int * , int N)
{
int j;
for(j=0;j<=N;j++)
	set (i,N,j,0)
}
int get(const unsigned int * , int N,int bit)
{
if((N<0) || (bit<0)) return -1;
	
}
int set(unsigned int * , int N,int bit,int boolean)
{
if((N<0) || (bit<0)) return -1;

	if(boolean==0)
	{
	 *i &=-(1u<<bit);
	}
	else if (boolean==1)
	{
	*i |=-(1u<<bit);
	}
	else return -1;




#endif
