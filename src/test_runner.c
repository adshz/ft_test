/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:04:12 by szhong            #+#    #+#             */
/*   Updated: 2024/11/12 21:19:41 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_test.h"
#include <stdio.h>
#include <stdlib.h>

t_test_case	*test_create(char *name, t_test_func func)
{
	t_test_case *test;

	test = (t_test_case *)malloc(sizeof(t_test_case));
	if (!test)
		return (NULL);
	test->name = name;
	test->func = func;
	test->next = NULL;
	return (test);
}

void	test_add(t_test_case **suite, t_test_case *test)
{
	t_test_case	*current;

	if (!*suite)
	{
		*suite = test;
		return ;
	}
	current = *suite;
	while (current->next)
		current = current->next;
	current->next = test;
}

void test_run_suite(t_test_case *suite)
{
	t_test_result	result;
	t_test_case		*current;
	int				total_tests;
	int				total_passed;

	if (!suite)
		return ;
	current = suite;
	total_tests = 0;
	total_passed = 0;
	printf("\nRunning test suite...\n");
	while (current)
	{
		result.passed = 0;
		result.failed = 0;
		result.msg = NULL;
		printf("\nTest: %s\n", current->name);
		current->func(&result);
		if (result.failed == 0)
		{
			printf("%s✅✅✅✅ PASSED ✅✅✅✅%s\n", TEST_GREEN, TEST_RESET);
			total_passed++;
		}
		else
		{
			printf("%s❌❌❌❌ Failed ❌❌❌❌%s\n", TEST_RED, TEST_RESET);
			if (result.msg)
				printf("%s%s%s\n", TEST_RED, result.msg, TEST_RESET);
		}
		total_tests++;
		current = current->next;
	}
	printf("\nResults: %d/%d tests passed\n", total_passed, total_tests);
}

void test_cleanup(t_test_case *suite)
{
    t_test_case *current;
    t_test_case *next;

    current = suite;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
