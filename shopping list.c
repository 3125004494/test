#include <stdio.h>
#include <stdlib.h>
#include<string.h>
double parse_discount(char *discount_str);//将折扣字符串转化为对应的折扣系数
 
int main()
{
	FILE *file=fopen("prices.txt","r");
	
	if(!file){
		printf("failed to open the text!\n");
		return 1;
	}
	
	double price,total=0.0;
	char discount[20];
	while(fscanf(file,"%lf %s",&price,discount)==2){
		double factor;
		factor=parse_discount(discount);
		total+=price*factor;
	}
	
	fclose(file);
	printf("total price:%d\n",(int)total/100*100+100);
	return 0;
}
 
 
 double parse_discount(char *discount_str)
{

	if(strcmp(discount_str,"half")==0){
		return 0.5;
	}
	else if(strstr(discount_str,"%")!=NULL){
		double value;
		sscanf(discount_str,"%lf%%",&value);
		return value/100.0;
	}
	return 1.0;
}	 
  
