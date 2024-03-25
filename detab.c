#include <stdio.h>
int main() {
	
	int c; 		/* storage variable for character read */
	int abs_pos=0;	/* column position for each line */
	int count, i;	/* count for number of spaces added, variable 'i' for counting number of spaces required */
		
	while ( (c = getchar()) != EOF) {
		switch (c) {
			case 9:		/* case for tabs */
				count = 0;
				for (i=0; i < (8 - (abs_pos % 8)); i++) {
					putchar(' ');	
					count++;
				}
				abs_pos += count;
				break;		
			case '\n':		/* case for next line key */
				putchar('\n');
				abs_pos = 0;
				break;
			case '\r':		/* case for return key */
				putchar('\r');
				abs_pos = 0;
				break;
			case '\b':		/* case for backspace */
				putchar('\b');	
				abs_pos--;	
				if (abs_pos <0) {	 
					abs_pos=0;
				}	
				break;
			default:		/* default case */
				putchar(c);	
				abs_pos++;
			}
	}
	return 0;
}
