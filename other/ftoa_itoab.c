#include <stdio.h>
#include <string.h>
 
/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 
 */
char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }
 
	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;
 
	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );
 
	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}
 
char * ftoa(float f, char * buffer, int decimal_figures)
{
    char * result = buffer;
    if (f<0) {
        *buffer++ = '-';
        f = -f;
    }
 
    float power = 1.0;
    
    for (int i=0; i<decimal_figures; i++) {
        power *= 10;   
    }
    
    int integral = (int)f;
    int decimal = (int)((f -integral)*power);
    
    itoa(integral, buffer, 10);
    char * p_decimal = buffer + strlen(buffer);
    *p_decimal ++ = '.';
    itoa(decimal, p_decimal, 10);
    
    return result;
}
 
int main()
{
    char buffer[30];
    
    for (int i=4; i>0; i--) {
        puts(ftoa(12.34567, buffer, i));
    }
    
    for (int i=4; i>0; i--) {
        puts(ftoa(-12.34567, buffer, i));
    }
    
    puts (ftoa(0.0, buffer, 3));
    puts (ftoa(1.2, buffer, 3));
 
    return 0;
}