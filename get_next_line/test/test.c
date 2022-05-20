#include	<stdio.h>

int	main(void)
{
	char *a = "yoloooo";
	char *b;

	b = a;
	printf("%s %s\n", a, b);
	a = NULL;
	printf("%s %s\n", a, b);
}
