#include<stdio.h>
int main()
{
	int N, i , otvet=0;
	int n;
	scanf("%d",&N);
	for ( i=1; i<= N; i++)
	{
		scanf("%d", &n);
		otvet= otvet-n;
	}
printf("%d\n",otvet);
}
