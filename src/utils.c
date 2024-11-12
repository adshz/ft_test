/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:22:38 by szhong            #+#    #+#             */
/*   Updated: 2024/11/12 21:29:12 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_test.h"
#include <stdio.h>

/* string utilities */
char	*test_strdup(const char *str)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* Memory utilities */
void	*test_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t	i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char )c;
		i++;
	}
	return (b);
}

/* Output Formatting */
void	test_print_divider(void)
{
	printf("\n-----------------------------------------\n");
}

void	test_print_summary(int total, int passed)
{
	float	percentage;

	percentage = (float)passed / total * 100;
	test_print_divider();
	printf("Test Summary:\n");
	printf("Total Tests: %d\n", total);
	printf("Passed: %d (%.f%%)\n", passed, percentage);
	printf("Failed: %d\n", total - passed);
	test_print_divider();
}
