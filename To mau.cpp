#include<stdio.h>
#include<math.h>


struct dothi
	{
			int mau;
			int bac;
			int con[100];// nhung dinh ke voi dinh dan xet; 
	}DINH[100];
	
	
void maunhonhatcua( int so) //Tim mau phu hop
	{
		int chapnhanduoc=0;
		if (DINH[so].bac==0) DINH[so].mau=1;// Xu ly do thi co nhieu thanh phan lien thong
		else{
		
		for (int k=1; k<=DINH[so].bac+1;k++)// k la STT mau duoc xet
				
		{
				
		 	for(int j=0; j<DINH[so].bac;j++)	//Kiem tra mau cua cac con		
			{
				
				if (DINH[DINH[so].con[j]].mau==k) 
					{
						break;
					}
				if (j==(DINH[so].bac-1)) chapnhanduoc=1;
				
			}
			if (chapnhanduoc==1) 
			{
				DINH[so].mau=k;
				break;
			}
		}
	}
	}

// Du lieu mau dung de nhap
void tomau(int mau )
	{
		
		switch(mau)
		{

			case 1 : printf("red");
					break;
			case 2 : printf("orange");
					break;
			case 3 : printf("yellow");
					break;
			case 4 : printf("green");
					break;
			case 5 : printf("blue");
					break;
			case 6 : printf("pink");
					break;
			case 7 : printf("chocolate");
					break;
			case 8 : printf("yellow");
					break;		
			case 9 : printf("violet");
					break;	
			case 10 : printf("cyan1");
					break;		
		}
			
	}	



main()
{	
	int sodinh,socanh, nhap1[100], nhap2[100];
	 scanf("%d",&sodinh);
	 scanf("%d",&socanh);
	
	for(int i=0; i< socanh; i++)
	{
		scanf("%d",&nhap1[i]);
		scanf("%d",&nhap2[i]);
		
		DINH[nhap1[i]].con[DINH[nhap1[i]].bac]=nhap2[i];
		DINH[nhap1[i]].bac++;
		
		DINH[nhap2[i]].con[DINH[nhap2[i]].bac]=nhap1[i];
		DINH[nhap2[i]].bac++;
	}
	// Bắt đầu thuật toán
	DINH[1].mau=1;
	for(int i=2;i <= sodinh; i++)
	{
		if(DINH[i].mau==0) 
			{
					maunhonhatcua(i);
			} 
	}
	
	//Ket qua
	printf("graph dothi \n{");
	for(int i=1;i<=sodinh;i++)
	{	
		printf("\n   %d [fillcolor= ",i);
		tomau(DINH[i].mau);
		printf(", style=filled];");
	}
	printf("\n");
	for(int i=0; i< socanh; i++)
	{
		printf("\n   %d -- %d;",nhap1[i],nhap2[i]);
	}
	
	printf("\n}");
	return 0;
}
