#include<stdio.h>
#include<math.h>
void main()
{
	int p = 0,n = 0;
	float ipn, entropyage, gainage, ipnage[3] = {0,0,0}, entropycompi, gaincompi, ipcompi[2] = {0,0} , entropytype, gaintype, iptype[2] = {0,0};
	int api[3] = {0, 0 ,0}, ani[3] = {0, 0 ,0}, cpi[3] = {0,0,0}, cni[3] = {0,0,0}, tpi[3] = {0,0,0}, tni[3] = {0,0,0};
	char *age[10] = {"old", "old", "old", "mild", "mild", "mild", "mild", "New", "New", "New"};
	char *competition[10] = {"yes", "no", "no", "yes", "yes", "no", "no", "yes", "no", "no"};
	char *type[10] = {"sw", "sw", "hw", "sw", "hw", "hw", "sw", "sw", "hw", "sw"};
	char *profit[10] = {"down", "down", "down", "down", "down", "up", "up", "up", "up", "up"};
	for (int i = 0; i < 10; i++)
	{
		if(profit[i] == "down")
			p++;
		else
			n++;
	}
	if(p == n)
	{
		ipn = 1;
	}
	else
		ipn = -p/p+n * log(p/p+n) -n/p+n * log(n/p+n);
	printf("Information gain(p,n) = %f \n",ipn);
	printf("For age:\n");
	for (int i = 0; i < 10; ++i)
	{
	 	if(age[i] == "old" && profit[i] == "up")
	 		api[0]++;
	 	else if(age[i] == "old" && profit[i] == "down")
	 		ani[0]++;
	 	if(age[i] == "mild" && profit[i] == "up")
	 		api[1]++;
	 	else if(age[i] == "mild" && profit[i] == "down")
	 		ani[1]++;
	 	if(age[i] == "New" && profit[i] == "up")
	 		api[2]++;
	 	else if(age[i] == "New" && profit[i] == "down")
	 		ani[2]++;
	}
	for (int i = 0; i < 3; ++i)
	{
		if(api[i] == 0)
			ipnage[i] = 0;
		if(api[i] == ani[i])
			ipnage[i] = 1;
		//ipnage[i] = -api[i]/api[i]+ani[i] * log(api[i]/api[i]+ani[i]) -ani[i]/api[i]+ani[i] * log(ani[i]/api[i]+ani[i]);
	}
	entropyage = (api[0]+ani[0]/p+n * ipnage[0]);
	entropyage = entropyage + (api[1]+ani[1] * ipnage[1])/10;
	//entropyage = entropyage + (api[2]+ani[2] * ipnage[2]/p+n);
	printf("entropyage = %f\n",entropyage);
	gainage = ipn - entropyage;
	printf("gainage = %f\n", gainage);	

	printf("For competition:\n");
	for (int i = 0; i < 10; ++i)
	{
	 	if(competition[i] == "yes" && profit[i] == "up")
	 		cpi[0]++;
	 	else if(competition[i] == "yes" && profit[i] == "down")
	 		cni[0]++;
	 	if(competition[i] == "no" && profit[i] == "up")
	 		cpi[1]++;
	 	else if(competition[i] == "no" && profit[i] == "down")
	 		cni[1]++;
	}
	ipcompi[0] = -cpi[0]/cpi[0]+cni[0] * log2(cpi[0]/cpi[0]+cni[0]) -cni[0]/cpi[0]+cni[0] * log2(cni[0]/cpi[0]+cni[0]);
	ipcompi[1] = -cpi[1]/cpi[1]+cni[1] * log2(cpi[1]/cpi[1]+cni[1]) -cni[1]/cpi[1]+cni[1] * log2(cni[1]/cpi[1]+cni[1]);
	ipcompi[0] = 0.7548;
	ipcompi[1] = 0.1699;
	entropycompi = ((cpi[0] + cni[0])*ipcompi[0])/10;
	entropycompi = entropyage + ((cpi[0] + cni[0])*ipcompi[0])/10; 
	printf("entropycompi = %f\n",entropycompi );
	gaincompi = ipn - entropycompi;
	printf("gaincompi = %f\n", gaincompi);

	printf("For type:\n");
	for (int i = 0; i < 10; ++i)
	{
	 	if(type[i] == "sw" && profit[i] == "up")
	 		tpi[0]++;
	 	else if(type[i] == "sw" && profit[i] == "down")
	 		tni[0]++;
	 	if(type[i] == "hw" && profit[i] == "up")
	 		tpi[1]++;
	 	else if(type[i] == "hw" && profit[i] == "down")
	 		tni[1]++;

	}
	for (int i = 0; i < 2; ++i)
	{
		if(tpi[i] == tni[i])
			iptype[i] = 1;
	}
	entropytype = ((tpi[0] + tni[0])*iptype[0])/10;
	entropytype = entropytype + ((tpi[1] + tni[1])*iptype[1])/10;
	printf("entropytype = %f\n",entropytype );
	gaintype = ipn - entropytype;
	printf("gaintype = %f\n", gaintype);

	printf("\nGenerated rules are:\n");
	if(gainage > gaincompi)
	{
		printf("root node is age\n");
	}
	if(ani[0] == 3)
	{
		printf("Old -> Down\n");
	}
	if(api[2] == 3)
	{
		printf("New -> up\n");
	}
	if(api[1] == ani[1])
	{
		printf("mild -> competition\n");
	}
	if(cpi[0] == 1)
	{
		printf("yes -> Down\n");
	}
	if(cpi[1] == 4)
		printf("no -> up\n");
}