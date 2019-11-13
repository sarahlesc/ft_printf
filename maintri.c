#include "printf.h"

int		ft_printf(const char *,...);
int i = 42;
unsigned int u = 42;
char c = 'c';
char *s = "123456789";


int     main(void)
{
	int *ptr = malloc(1);
	int *ptr2 = NULL;
/*

//printf("|%015c|\n", c);
//printf("|%015s|\n", s);
//printf("|%015p|\n", ptr);
printf("|%015d|\n", i);
printf("|%015i|\n", i);
printf("|%015x|\n", i);
printf("|%015X|\n", i);
printf("|%015u|\n", u);
printf("|%015%|\n");

*/




	printf("    TEST i\n\n\n");



printf("|%d|", 	printf("|%.0i|\n", 0));
printf("|%d|\n", 	ft_printf("|%.0i|\n", 0));
printf("|%d|", 	printf("|%.i|\n", 0));
printf("|%d|\n", 	ft_printf("|%.i|\n", 0));
printf("|%d|", 	printf("|%5.0i|\n", 0));
printf("|%d|\n", 	ft_printf("|%5.0i|\n", 0));
printf("|%d|", 	printf("|%5.i|\n", 0));
printf("|%d|\n", 	ft_printf("|%5.i|\n", 0));
printf("|%d|", 	printf("|%-5.0i|\n", 0));
printf("|%d|\n", 	ft_printf("|%-5.0i|\n", 0));





	printf("    TEST u\n\n\n");





printf("|%d|", 	printf("|%5.0u|\n", 0));
printf("|%d|\n", 	ft_printf("|%5.0u|\n", 0));
printf("|%d|", 	printf("|%5.u|\n", 0));
printf("|%d|\n", 	ft_printf("|%5.u|\n", 0));
printf("|%d|", 	printf("|%-5.0u|\n", 0));
printf("|%d|\n", 	ft_printf("|%-5.0u|\n", 0));



printf("    TEST x\n\n\n");






printf("|%d|", 	printf("|%.0x|\n", 0));
printf("|%d|\n", 	ft_printf("|%.0x|\n", 0));
printf("|%d|", 	printf("|%.x|\n", 0));
printf("|%d|\n", 	ft_printf("|%.x|\n", 0));
printf("|%d|", 	printf("|%5.0x|\n", 0));
printf("|%d|\n", 	ft_printf("|%5.0x|\n", 0));
printf("|%d|", 	printf("|%5.x|\n", 0));
printf("|%d|\n", 	ft_printf("|%5.x|\n", 0));
printf("|%d|", 	printf("|%08.5x|\n", 34));
printf("|%d|\n", 	ft_printf("|%08.5x|\n", 34));
printf("|%d|", 	printf("|%08.5x|\n", 0));
printf("|%d|\n", 	ft_printf("|%08.5x|\n", 0));
printf("|%d|", 	printf("|%08.3x|\n", 8375));
printf("|%d|\n", 	ft_printf("|%08.3x|\n", 8375));



printf("    TEST p\n\n\n");




printf("|%d|", 	printf("|%p|\n", "yo"));
printf("|%d|\n", 	ft_printf("|%p|\n", "yo"));
printf("|%d|", 	printf("|%p|\n", NULL));
printf("|%d|\n", 	ft_printf("|%p|\n", NULL));
printf("|%d|", 	printf("|%p|\n", ""));
printf("|%d|\n", 	ft_printf("|%p|\n", ""));
printf("|%d|", 	printf("|%p|\n", ptr));
printf("|%d|\n", 	ft_printf("|%p|\n", ptr));
printf("|%d|", 	printf("|%-p|\n", "yo"));
printf("|%d|\n", 	ft_printf("|%-p|\n", "yo"));
printf("|%d|", 	printf("|%-p|\n", NULL));
printf("|%d|\n", 	ft_printf("|%-p|\n", NULL));
printf("|%d|", 	printf("|%-p|\n", ""));
printf("|%d|\n", 	ft_printf("|%-p|\n", ""));
printf("|%d|", 	printf("|%-p|\n", ptr));
printf("|%d|\n", 	ft_printf("|%-p|\n", ptr));
printf("|%d|", 	printf("|%-15p|\n", "yo"));
printf("|%d|\n", 	ft_printf("|%-15p|\n", "yo"));
printf("|%d|", 	printf("|%-15p|\n", NULL));
printf("|%d|\n", ft_printf("|%-15p|\n", NULL));
printf("|%d|", printf("|%-15p|\n", ""));
printf("|%d|\n", 	ft_printf("|%-15p|\n", ""));
printf("|%d|", 	printf("|%-15p|\n", ptr));
printf("|%d|\n", 	ft_printf("|%-15p|\n", ptr));
printf("|%d|", 	printf("|%*p|\n", 0, "yo"));
printf("|%d|\n", 	ft_printf("|%*p|\n", 0, "yo"));
printf("|%d|", 	printf("|%*p|\n", 0, NULL));
printf("|%d|\n", 	ft_printf("|%*p|\n", 0, NULL));
printf("|%d|", 	printf("|%*p|\n", 0, ""));
printf("|%d|\n", 	ft_printf("|%*p|\n", 0, ""));
printf("|%d|", 	printf("|%*p|\n", 0, ptr));
printf("|%d|\n", 	ft_printf("|%*p|\n", 0, ptr));
printf("|%d|", 	printf("|%*p|\n", 15, "yo"));
printf("|%d|\n", 	ft_printf("|%*p|\n", 15, "yo"));
printf("|%d|", 	printf("|%*p|\n", 15, NULL));
printf("|%d|\n", 	ft_printf("|%*p|\n", 15, NULL));
printf("|%d|", 	printf("|%*p|\n", 15, ""));
printf("|%d|\n", 	ft_printf("|%*p|\n", 15, ""));
printf("|%d|", 	printf("|%*p|\n", 15, ptr));
printf("|%d|\n", 	ft_printf("|%*p|\n", 15, ptr));
printf("|%d|", 	printf("|%.p|\n", "yo"));
printf("|%d|\n", 	ft_printf("|%.p|\n", "yo"));
printf("|%d|", 	printf("|%.p|\n", NULL));
printf("|%d|\n", 	ft_printf("|%.p|\n", NULL));
printf("|%d|", printf("|%.p|\n", ""));
printf("|%d|\n", 	ft_printf("|%.p|\n", ""));
printf("|%d|", 	printf("|%.p|\n", ptr));
printf("|%d|\n", 	ft_printf("|%.p|\n", ptr));
printf("|%d|", 	printf("|%15p|\n", "yo"));
printf("|%d|\n", 	ft_printf("|%15p|\n", "yo"));
printf("|%d|", 	printf("|%15p|\n", NULL));
printf("|%d|\n", 	ft_printf("|%15p|\n", NULL));
printf("|%d|", 	printf("|%15p|\n", ""));
printf("|%d|\n", 	ft_printf("|%15p|\n", ""));
printf("|%d|", 	printf("|%15p|\n", ptr));
printf("|%d|\n", 	ft_printf("|%15p|\n", ptr));


}