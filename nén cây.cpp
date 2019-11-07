#include <stdio.h>
#include <conio.h>
#include <math.h>

main()
{
	int socanh,sodinh, me[100000],con[100000],bac[100000],medinh[100000];
	int i,j;
	printf("Nhap so canh : ");
	scanf("%d",&socanh);
	sodinh= socanh+1;
	
	for(i=0; i<socanh; i++)
	{
		scanf("%d",&me[i]);
		scanf("%d",&con[i]);
		bac[me[i]]++;
		bac[con[i]]++;
		medinh[con[i]]=me[i]; // medinh dde noi me va con . Vi con laf duy nhats nhuwng ddang bij lechje
	}
	printf("\n");
	
	for(j=0;j<socanh-1;j++)
		
		for(i=1;i<=sodinh;i++)
		{
			if(bac[i]==1) 
			{
				bac[medinh[i]]--;
				bac[i]--;
					printf(" %d ",medinh[i]);
				break;
			}
		}
	
	return 0;
}
