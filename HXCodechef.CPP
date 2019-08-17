#include <stdio.h>

int main()
{	int i,j,n;
	scanf("%d", &n);
	float charge[n+1][n+1];
	int polar[n+1][n+1];
	float force0=0, force1=0;
	
	for(i=1; i<=n; i++)
	{	for(j=1; j<=n; j++)
		{	scanf("%f", &charge[i][j]);
		}	
		//even row
		if(i%2 == 0)
		{	for(j=1; j<=n; j++)
			{	
				force0 = force1 = 0;
				
				/*calculate neighbours of most recent atom*/
				
				if(i-1 >= 1)
				{	if(polar[i-1][j] == 0)
						force0 += charge[i-1][j];
					else
						force1 += charge[i-1][j];
					
					if(j+1 <= n)
					{	if(polar[i-1][j+1] == 0)
							force0 += charge[i-1][j+1];
						else
							force1 += charge[i-1][j+1];
					}
				}
				
				if(j-1 >= 1)
				{	if(polar[i][j-1] == 0)
						force0 += charge[i][j-1];
					else
						force1 += charge[i][j-1];
				}
				
				polar[i][j] = force0*charge[i][j] <= force1*charge[i][j] ? 0:1;
				
			}//end for
		}
			
		//odd row
		else
		{	for(j=1; j<=n; j++)
			{	
				force0 = force1 = 0;
				
				/*calculate neighbours of most recent atom*/
				
				if(i-1 >= 1)
				{	if(polar[i-1][j] == 0)
						force0 += charge[i-1][j];
					else
						force1 += charge[i-1][j];
					
					if(j-1 >= 1)
					{	if(polar[i-1][j-1] == 0)
							force0 += charge[i-1][j-1];
						else
							force1 += charge[i-1][j-1];
					}
				}
				
				if(j-1 >= 1)
				{	if(polar[i][j-1] == 0)
						force0 += charge[i][j-1];
					else
						force1 += charge[i][j-1];
				}
				
				polar[i][j] = force0*charge[i][j] <= force1*charge[i][j] ? 0:1;
			}
		}
		
		for(j=1; j<=n; j++)
			printf("%d ", polar[i][j]);
		printf("\n");	
	}
	return 0;
}
