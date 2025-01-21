#include <stdio.h>


int checkLeap(int year)
{
    return (year %4 ==0 && (year % 100 || year % 400 == 0))?1:0;
}


int oddDayesInCenturyYear(int centuries)
{
    //1947
    int noCentury = (centuries/100);//19
    int leapCentury = noCentury/4;//4
    
    //in one century there are 1 odd days;
    int oddDays = ((noCentury * 5) + leapCentury) % 7;
    return oddDays; 
}

int oddDayesInYears(int years)
{
    //46
    int noLeap = years/4;//11
    int oddLeapDays = (noLeap*2)%7;
    int oddNormalDays = ((years - noLeap)*1)%7;
    int oddDays = (oddLeapDays + oddNormalDays)%7;

    return oddDays;
}

int oddDayesInDate(int day,int month,int year)
{
    int oddDays=0;

    for(int i=1;i<month;i++)
    {
        
        switch(i)
        {
            case 1:oddDays += 31%7; break;//Jan
            case 2:oddDays += checkLeap(year)?29 % 7:28 % 7; break;
            case 3:oddDays += 31%7;break;//March
            case 4:oddDays += 30%7;break;//April
            case 5:oddDays += 31%7;break;//May
            case 6:oddDays += 30%7;break;//Jun
            case 7:oddDays += 31%7;break;//July
            case 8:oddDays += 31%7;break;//Aug
            case 9:oddDays += 30%7;break;//Sep
            case 10:oddDays += 31%7;break;//Oct
            case 11:oddDays += 30%7;break;//Nov
            case 12:oddDays += 31%7;break;//Dec

        }
    }

    oddDays += day;
    
    oddDays %= 7;
  
    oddDays= (oddDays+oddDayesInCenturyYear((year / 100)*100)+oddDayesInYears(year % 100)-1)%7;
    
    return oddDays;

}


char * getDay(int day,int month,int year)
{
    char *Days[]={"Sunday","Monday","Tuesday","Wednesday","Thusday","Friday","Satarday"};
    
    return Days[oddDayesInDate(day,month,year)];
}


int castToInterger(char *str)//12
{
    int num=0;
    for(int i=0;*(str+i)!='\0';i++)
    {
        num = (num * 10) +(*(str+i)-'0');  //1
    }
    return num;
}


void main(int no, char **arg)
{
    if(no ==4)
    {
    	int day=castToInterger(arg[1]);
    	int month=castToInterger(arg[2]);
    	int year=castToInterger(arg[3]);
    	int ckday;
    	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    		ckday=31;
    	else if(month == 2)
    	{
    		if(checkLeap(year))
    			ckday=29;
    		else
    			ckday=28;
    	}
    	else
    		ckday=30;
    	
    	if(day>0 && day <= ckday && month >0 && month <=12)
		    printf("\n\t%s\n\n",getDay(day,month,year));
		else
			printf("\n\tTry again with valid date\n\n");
	}
    else
    printf("\n\tUse %s <day> <month> <year>  [ENTER]\n\n",arg[0]);
}
