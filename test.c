#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(){
	int do_test;
	int disp;

	do_test = 1;
	disp = 1;
	if (do_test){
		if (disp) ft_putstr("test with no input\n");
		assert(ft_printf("") == 0);
	}
	do_test = 1;
	if (do_test){
		if (disp) ft_putstr("[abcde] : [");
		ft_printf("abcde");
		// assert(ft_printf("abcde") == 5);
		if (disp) ft_putendl("]");
	}
	do_test = 1;
	if (do_test)
	{
		if (disp) ft_putstr("[42] : [");
		assert(ft_printf("%d", 42) == 2);
		if (disp) ft_putendl("]");

		if (disp) ft_putstr("[c] : [");
		assert(ft_printf("%c", 'c') == 1);
		if (disp) ft_putendl("]");

		if (disp) ft_putstr("[str] : [");
		assert(ft_printf("%s", "str") == 3);
		if (disp) ft_putendl("]");
	}
	do_test = 0;
	if (do_test){
		if (disp) ft_putstr("[1.567] : [");
		ft_printf("%d", 1.567);
		if (disp) ft_putendl("]");

		if (disp) ft_putendl("");
	}

	// if (do_test){
	// 	disp = 1;
		// ft_printf ("Characters: %c %c \n", 'a', 65);
		// ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
		// ft_printf ("Preceding with blanks: %10d \n", 1977);
		// ft_printf ("Preceding with zeros: %010d \n", 1977);
		// ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
		// ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
		// ft_printf ("Width trick: %*d \n", 5, 10);
		// ft_printf ("%s \n", "A string");

		// output
		// Characters: a A
		// Decimals: 1977 650000
		// Preceding with blanks:       1977
		// Preceding with zeros: 0000001977
		// Some different radices: 100 64 144 0x64 0144
		// floats: 3.14 +3e+000 3.141600E+000
		// Width trick:    10
		// A string

	/*
		char *ptr = "Hello world!";
		char *np = 0;
		int i = 5;
		unsigned int bs = sizeof(int)*8;
		int mi;
		char buf[80];

		mi = (1 << (bs-1)) + 1;
		printf("%s\n", ptr);
		printf("printf test\n");
		printf("%s is null pointer\n", np);
		printf("%d = 5\n", i);
		printf("%d = - max int\n", mi);
		printf("char %c = 'a'\n", 'a');
		printf("hex %x = ff\n", 0xff);
		printf("hex %02x = 00\n", 0);
		printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
		printf("%d %s(s)%", 0, "message");
		printf("\n");
		printf("%d %s(s) with %%\n", 0, "message");
		sprintf(buf, "justif: \"%-10s\"\n", "left"); printf("%s", buf);
		sprintf(buf, "justif: \"%10s\"\n", "right"); printf("%s", buf);
		sprintf(buf, " 3: %04d zero padded\n", 3); printf("%s", buf);
		sprintf(buf, " 3: %-4d left justif.\n", 3); printf("%s", buf);
		sprintf(buf, " 3: %4d right justif.\n", 3); printf("%s", buf);
		sprintf(buf, "-3: %04d zero padded\n", -3); printf("%s", buf);
		sprintf(buf, "-3: %-4d left justif.\n", -3); printf("%s", buf);
		sprintf(buf, "-3: %4d right justif.\n", -3); printf("%s", buf);

		 * this should display (on 32bit int machine) :
		 *
		 * Hello world!
		 * printf test
		 * (null) is null pointer
		 * 5 = 5
		 * -2147483647 = - max int
		 * char a = 'a'
		 * hex ff = ff
		 * hex 00 = 00
		 * signed -3 = unsigned 4294967293 = hex fffffffd
		 * 0 message(s)
		 * 0 message(s) with %
		 * justif: "left      "
		 * justif: "     right"
		 *  3: 0003 zero padded
		 *  3: 3    left justif.
		 *  3:    3 right justif.
		 * -3: -003 zero padded
		 * -3: -3   left justif.
		 * -3:   -3 right justif.
	*/
	// }
	printf("\ntest ok\n");
}