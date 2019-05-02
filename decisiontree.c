#include <stdio.h>
#include<string.h>
#include<math.h>
float entrophy(int ayes,int ano,int atotal){		//for entrophy calculation formula -(pi/total)*log2(pi/total);
	float temp=-((ayes/(float)atotal)*log2(ayes/(float)atotal))-((ano/(float)atotal)*log2(ano/(float)atotal));
	return temp;
}
int main(int argc, char **argv)
{
	FILE *input;
	
	char outlook[20],temp[20],humidity[20],windy[20],play[20];		//file operations
	int temp1=0;								
	float maxGain=0;							//calculate maximum gain to find selected nodes
	
	int totalplay=0;							//for play class YES/NO
	float EntrophyPlay=0;						
	
	float EntrophyWindyTrue=0,EntrophyWindyFalse=0;		//WINDY
	int totalWindyFalse=0,totalWindyTrue=0;
	
	float EntrophyHumidityHigh=0,EntrophyHumidityNormal=0;		//HUMIDITY
	int totalHumidityHigh=0,totalHumidityNormal=0;
	
	float EntrophySunny=0,EntrophyOvercast=0,EntrophyRainy=0;	//OUTLOOK
	int totalSunny=0,totalOvercast=0,totalRainy=0;
	
	float EntrophyHot=0,EntrophyMild=0,EntrophyCool=0;		//TEMPERATURE
	int totalHot=0,totalMild=0,totalCool=0;
	
	
	float totalOutlook=0,totalTemp=0,totalHumidity=0,totalWindy=0;	
	float gainOutlook=0,gainTemp=0,gainHumidity=0,gainWindy=0;
	
	
	
	
	//Total Yes or No Of PLay
	printf("\n\nTHe Play Class\n\n");
	 
	int yes=0,no=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0){
			yes++;
			totalplay++;					}
		if(strcmp(play,"no")==0){
			no++;totalplay++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF yes is %d\n",yes);
	printf("The Number oF no is %d\n",no);
	printf("The Number oF TOTAL PLAY is %d\n",totalplay);
	EntrophyPlay=entrophy(yes,no,totalplay);
	printf("The Entrophy is %f\n",EntrophyPlay);



// Now Calculating For OUTLOOK  Sunny(Yes NO); 
printf("\n\nTHe Outlook Sunny \n\n");		//same as playclass just to add extra compare and

	yes=0;no=0;totalSunny=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(outlook,"sunny")==0){
			yes++;
			totalSunny++;					}
		if(strcmp(play,"no")==0 && strcmp(outlook,"sunny")==0){
			no++;totalSunny++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF SUNNY yes is %d\n",yes);
	printf("The Number oF SUNNY no is %d\n",no);
	printf("The Number oF SUNNY TOTAL  is %d\n",totalSunny);
	EntrophySunny=entrophy(yes,no,totalSunny);		//function CALL
	
	temp1=isnan(EntrophySunny);						//to calculate ISNAN because log(0)*0 gives ERROR NAN(not a number)
	if(temp1==1)
		EntrophySunny=0;
		
	printf("The Entrophy of SUNNY is %f\n",EntrophySunny);		


// Now Calculating For OUTLOOK  Overcast(Yes NO);
printf("\n\nTHe Outlook Overcast \n\n"); 
yes=0;no=0;totalOvercast=0;temp1=0;
input=fopen("decisiontreeinput.txt","r");
fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(outlook,"overcast")==0){
			yes++;
			totalOvercast++;					}
		if(strcmp(play,"no")==0 && strcmp(outlook,"overcast")==0){
			no++;totalOvercast++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF OVERCAST yes is %d\n",yes);
	printf("The Number oF OVERCAST no is %d\n",no);
	printf("The Number oF OVERCAST TOTAL  is %d\n",totalOvercast);
	EntrophyOvercast=entrophy(yes,no,totalOvercast);
	
	temp1=isnan(EntrophyOvercast);
	if(temp1==1)
		EntrophyOvercast=0;
	
	
	
	printf("The Entrophy of OVERCAST is %f\n",EntrophyOvercast);


// Now Calculating For OUTLOOK  Rainy(Yes NO);
printf("\n\nTHe Outlook Rainy \n\n"); 
yes=0;no=0;totalRainy=0;temp1=0;
input=fopen("decisiontreeinput.txt","r");
fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(outlook,"rainy")==0){
			yes++;
			totalRainy++;					}
		if(strcmp(play,"no")==0 && strcmp(outlook,"rainy")==0){
			no++;totalRainy++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF Rainy yes is %d\n",yes);
	printf("The Number oF Rainy no is %d\n",no);
	printf("The Number oF Rainy TOTAL is %d\n",totalRainy);
	EntrophyRainy=entrophy(yes,no,totalRainy);
	
	temp1=isnan(EntrophyRainy);
	if(temp1==1)
		EntrophyRainy=0;
	
	printf("The Entrophy of Rainy is %f\n",EntrophyRainy);

//Average and Gain of Outlook	

printf("\nCalculate the average Entrophy information of Outlook\n");

totalOutlook=((totalSunny/(float)totalplay)*(EntrophySunny))+((totalOvercast/(float)totalplay)*(EntrophyOvercast))+((totalRainy/(float)totalplay)*(EntrophyRainy));
printf("Average Entropy of Outlook is %f\n",totalOutlook);
gainOutlook=EntrophyPlay-totalOutlook;
printf("Gain of Outlook is %f\n",gainOutlook);




// Now Calculating For Windy(Yes NO)   True; 
printf("\n\nTHe Windy of TRue \n\n");

	yes=0;no=0;totalWindyTrue=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(windy,"true")==0){
			yes++;
			totalWindyTrue++;					}
		if(strcmp(play,"no")==0 && strcmp(windy,"true")==0){
			no++;totalWindyTrue++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF Windy yes is %d\n",yes);
	printf("The Number oF Windy no is %d\n",no);
	printf("The Number oF TOTAL Windy is %d\n",totalWindyTrue);
	EntrophyWindyTrue=entrophy(yes,no,totalWindyTrue);
	
	temp1=isnan(EntrophyWindyTrue);
	if(temp1==1)
		EntrophyWindyTrue=0;
		
	printf("The Entrophy Wiindy True is %f\n",EntrophyWindyTrue);




// Now Calculating For Windy(Yes NO)   False; 
printf("\n\nTHe Windy False\n\n");

	yes=0;no=0;totalWindyFalse=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(windy,"false")==0){
			yes++;
			totalWindyFalse++;					}
		if(strcmp(play,"no")==0 && strcmp(windy,"false")==0){
			no++;totalWindyFalse++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF Windy FalSE yes is %d\n",yes);
	printf("The Number oF Windy falseno is %d\n",no);
	printf("The Number oF TOTAL Windy False is %d\n",totalWindyFalse);
	EntrophyWindyFalse=entrophy(yes,no,totalWindyFalse);
	
	temp1=isnan(EntrophyWindyFalse);
	if(temp1==1)
		EntrophyWindyFalse=0;
		
	printf("The Entrophy Windy False is %f\n",EntrophyWindyFalse);



//Average and Gain of Windy	

printf("\nCalculate the average Entrophy information of Windy\n");

totalWindy=((totalWindyFalse/(float)totalplay)*(EntrophyWindyFalse))+((totalWindyTrue/(float)totalplay)*(EntrophyWindyTrue));
printf("Average Entropy of Outlook is %f\n",totalWindy);
gainWindy=EntrophyPlay-totalWindy;
printf("Gain of Outlook is %f\n",gainWindy);




// Now Calculating For Windy(Yes NO)   True; 
printf("\n\nTHe Windy \n\n");

	yes=0;no=0;totalWindyTrue=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(windy,"true")==0){
			yes++;
			totalWindyTrue++;					}
		if(strcmp(play,"no")==0 && strcmp(windy,"true")==0){
			no++;totalWindyTrue++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF Windy yes is %d\n",yes);
	printf("The Number oF Windy no is %d\n",no);
	printf("The Number oF TOTAL Windy is %d\n",totalWindyTrue);
	EntrophyWindyTrue=entrophy(yes,no,totalWindyTrue);
	
	temp1=isnan(EntrophyWindyTrue);
	if(temp1==1)
		EntrophyWindyTrue=0;
		
	printf("The Entrophy Wiindy True is %f\n",EntrophyWindyTrue);




// Now Calculating For Humidity(Normal,high)   Normal; 
printf("\n\nTHe Humudity Normal\n\n");

	yes=0;no=0;totalHumidityNormal=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(humidity,"normal")==0){
			yes++;
			totalHumidityNormal++;					}
		if(strcmp(play,"no")==0 && strcmp(humidity,"normal")==0){
			no++;totalHumidityNormal++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF Humidity NORMAL yes is %d\n",yes);
	printf("The Number oF Humidity NORMALno is %d\n",no);
	printf("The Number oF TOTAL Humidity NORMAL is %d\n",totalHumidityNormal);
	EntrophyHumidityNormal=entrophy(yes,no,totalHumidityNormal);
	
	temp1=isnan(EntrophyHumidityNormal);
	if(temp1==1)
		EntrophyHumidityNormal=0;
		
	printf("The Entrophy of HUMIDITY Normal is %f\n",EntrophyHumidityNormal);


// Now Calculating For Humidity(Normal,high)   high; 
printf("\n\nTHe Humudity HIGH\n\n");

	yes=0;no=0;totalHumidityHigh=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(humidity,"high")==0){
			yes++;
			totalHumidityHigh++;					}
		if(strcmp(play,"no")==0 && strcmp(humidity,"high")==0){
			no++;totalHumidityHigh++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF humidity High yes is %d\n",yes);
	printf("The Number oF Humidity High no is %d\n",no);
	printf("The Number oF TOTAL HUMIDITY HIGH is %d\n",totalHumidityHigh);
	EntrophyHumidityHigh=entrophy(yes,no,totalHumidityHigh);
	
	temp1=isnan(EntrophyHumidityHigh);
	if(temp1==1)
		EntrophyHumidityHigh=0;
		
	printf("The Entrophy OF HUMDITY HIGH is %f\n",EntrophyHumidityHigh);



//Average and Gain of Humidity	

printf("\nCalculate the average Entrophy information of Windy\n");

totalHumidity=((totalHumidityNormal/(float)totalplay)*(EntrophyHumidityNormal))+((totalHumidityHigh/(float)totalplay)*(EntrophyHumidityHigh));
printf("Average Entropy of HUMIDITY is %f\n",totalHumidity);
gainHumidity=EntrophyPlay-totalHumidity;
printf("Gain of HUMIDITY is %f\n",gainHumidity);




// Now Calculating For Temp Hot(Yes NO); 
printf("\n\nTHe Temp Hot \n\n");

	yes=0;no=0;totalHot=0;temp1=0;
	input=fopen("decisiontreeinput.txt","r");
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(temp,"hot")==0){
			yes++;
			totalHot++;					}
		if(strcmp(play,"no")==0 && strcmp(temp,"hot")==0){
			no++;totalHot++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF Hot yes is %d\n",yes);
	printf("The Number oF Hot no is %d\n",no);
	printf("The Number oF TOTAL Hot is %d\n",totalHot);
	EntrophyHot=entrophy(yes,no,totalHot);
	
	temp1=isnan(EntrophyHot);
	if(temp1==1)
		EntrophyHot=0;
		
	printf("The HOT Entrophy is %f\n",EntrophyHot);


// Now Calculating For Temp MILD(Yes NO);
printf("\n\nTHe Temp MILD \n\n"); 
yes=0;no=0;totalMild=0;temp1=0;
input=fopen("decisiontreeinput.txt","r");
fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(temp,"mild")==0){
			yes++;
			totalMild++;					}
		if(strcmp(play,"no")==0 && strcmp(temp,"mild")==0){
			no++;totalMild++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF MILD yes is %d\n",yes);
	printf("The Number oF MILD no is %d\n",no);
	printf("The Number oF TOTAL MILD is %d\n",totalMild);
	EntrophyMild=entrophy(yes,no,totalMild);
	
	temp1=isnan(EntrophyMild);
	if(temp1==1)
		EntrophyMild=0;
	
	printf("The Entrophy MILD is %f\n",EntrophyMild);


// Now Calculating For Temp Cool(Yes NO);
printf("\n\nTHe Temp Cool \n\n"); 
yes=0;no=0;totalCool=0;temp1=0;
input=fopen("decisiontreeinput.txt","r");
fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);
		
	while(!feof(input)){
		fscanf(input,"%s",play);
				
		if(strcmp(play,"yes")==0 && strcmp(temp,"cool")==0){
			yes++;
			totalCool++;					}
		if(strcmp(play,"no")==0 && strcmp(temp,"cool")==0){
			no++;totalCool++;	}
	fscanf(input,"%s%s%s%s",outlook,temp,humidity,windy);	
		
	}	
	printf("The Number oF COLD yes is %d\n",yes);
	printf("The Number oF COLD no is %d\n",no);
	printf("The Number oF TOTAL COOL is %d\n",totalCool);
	EntrophyCool=entrophy(yes,no,totalCool);
	
	temp1=isnan(EntrophyCool);
	if(temp1==1)
		EntrophyCool=0;
	
	printf("The Entrophy is %f\n",EntrophyCool);

//Average and Gain of Temp

	printf("\nCalculate the average Entrophy information of Temp\n");

	totalTemp=((totalHot/(float)totalplay)*(EntrophyHot))+((totalMild/(float)totalplay)*(EntrophyMild))+((totalCool/(float)totalplay)*(EntrophyCool));
	printf("Average Entropy of Temp is %f\n",totalTemp);
	gainTemp=EntrophyPlay-totalTemp;
	printf("Gain of Temp is %f\n",gainTemp);

	 //calculating max gain
	if(gainHumidity>gainOutlook)
	maxGain=gainHumidity;
	else
	maxGain=gainOutlook;
	if(gainTemp>gainWindy){
		if(gainTemp>maxGain){
			maxGain=gainTemp;}}
	else{
		if(gainWindy>maxGain){
			maxGain=gainWindy;	}
		}
	printf("Maximum Gain is %f\n",maxGain);	
	
	
	
if(maxGain==gainHumidity){
	printf("Gain Humidity is node");}
if(maxGain==gainTemp){
	printf("Gain Temp is node");}
if(maxGain==gainOutlook){						//node is outlook
	printf("Gain Outlook is node\n");
	printf("\n\n\t\t\t\tOutLook\t\t\t\n");
	
	printf("\t\t/(sunny)\t|(overcast)\t\t\\(rainy)\t\t\n\n");
	
	//now calculating maximun of 3 number 
	
	if(gainHumidity>gainTemp){
		if(gainHumidity>gainWindy){
	
			printf("\tHUmidity\t\tYES\t\t\tWINDY\n\n");
			printf("\t/(high)\t\\(normal)\t\t\t/(false)\t\\(true)\n\n");
			printf("\tNO\tYES\t\t\t\tYES\t\tNO\n\n");
			}
		else
			printf("WINDY");	}
	else{
		if(gainTemp>gainWindy)
			printf("WINDY");
		else
			printf("Temp");	
	}
	}
if(maxGain==gainWindy){
	printf("Gain Windy is node");}
		
	return 0;
}

