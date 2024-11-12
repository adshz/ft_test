/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:19:54 by szhong            #+#    #+#             */
/*   Updated: 2024/11/12 21:22:10 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_test.h"
#include <string.h>
#include <stdio.h>

static void	update_result(t_test_result *result, int passed, char *msg)
{
	if (passed)
		result->failed++;
	else
	{
		result->failed++;
		result->msg = msg;
	}
}

void	assert_true(t_test_result *result, int condition, char *message)
{
	update_result(result, condition == 1, message);
}

void assert_false(t_test_result *result, int condition, char *message)
{
    update_result(result, condition == 0, message);
}

void assert_int_eq(t_test_result *result, int expected, int actual, char *message)
{
    update_result(result, expected == actual, message);
}

void assert_str_eq(t_test_result *result, char *expected, char *actual, 
                   char *message)
{
    if (!expected || !actual)
        update_result(result, 0, "Null pointer comparison");
    else
        update_result(result, strcmp(expected, actual) == 0, message);
}
