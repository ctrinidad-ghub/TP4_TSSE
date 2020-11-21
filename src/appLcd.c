#include "appLcd.h"

#define CHAR_MAX     10
#define BASE         10
#define ERROR_CODE   -1
#define PASS_CODE     0

char lcdSendIntFixedDigit( int64_t value, uint8_t dig, uint8_t dot )
{
   int8_t i,dig_r;
   char valueChar[CHAR_MAX];
   char lcdBuff[CHAR_MAX];

   if (dot >= dig) return ERROR_CODE;
   if (value < 0) return ERROR_CODE;

   int64ToString( value, valueChar, BASE );
   for (dig_r=0;dig_r<dig;dig_r++)
   {
	   if (*(valueChar+dig_r) == 0) break;
   }
   
   if ((dig_r > dig) || ((dig_r > (dig-1)) && dot > 0)) return ERROR_CODE;

   if (dot == 0) dot = dig;
   else dot = dig - dot - 1;
   
   for (i=0;i<dig;i++) lcdBuff[i] = ' ';

   for (i=0;i<dig;i++) {
	   if ((dig-i-1)<=(dig_r-1)) {
		   if (dot==i) { 
            lcdBuff[i] = '.'; 
            lcdBuff[i-1] = valueChar[dig_r-dig+i];
         }
         else if (i<dot) {
            if (dot==dig) lcdBuff[i] = valueChar[dig_r-dig+i];
            else lcdBuff[i-1] = valueChar[dig_r-dig+i];
         }
		   else if (i>dot) lcdBuff[i] = valueChar[dig_r-dig+i];
	   }
	   if ((dig-i-1)>(dig_r-1) && i>=dot) {
		   if (dot==i){ 
            lcdBuff[i] = '.'; 
            if (i!=0) lcdBuff[i-1] = '0';
         }
		   else lcdBuff[i] = '0';
	   }
   }

   for(i=0;i<dig;i++) lcdSendChar(lcdBuff[i]);
   
   return PASS_CODE;
}