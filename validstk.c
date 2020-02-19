#include <stdio.h>

main()
{
	int n, l, i, j, flag, act, top, s[100000];
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		top=-1;
		flag=0;
		scanf("%d", &l);
		for(j=0; j<l; j++)
		{
			scanf("%d", &act);
            if(flag==1)
		        continue;
		        
			if(act==1)
				s[++top]=1;
			else
				if(top==-1)
					flag=1;
				else
					top--;
		}
		if(flag==0)
			printf("valid\n");
		else
		    printf("invalid\n");
	}
}