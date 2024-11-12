/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:53:43 by szhong            #+#    #+#             */
/*   Updated: 2024/11/12 21:29:32 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_TEST_H
# define FT_TEST_H

# include <stdlib.h>
# include <unistd.h>

// Colour code for display test output
# define TEST_GREEN "\033[0;32m"
# define TEST_RED "\033[0;31m"
# define TEST_RESET "\033[0m"

/*
** Test Message Struct
*/
typedef struct s_test_result
{
	int	passed;
	int	failed;
	char *msg;
}	t_test_result;

/*
** Test Function Pointer
*/
typedef void (*t_test_func)(t_test_result *result);

/*
* Test Case Struct 
*
*/
typedef struct s_test_case
{
	char *name;
	t_test_func func;
	struct s_test_case *next;
}	t_test_case;

/* Core Functionalities */
t_test_case	*test_create(char *name, t_test_func func);
void		test_add(t_test_case **suite, t_test_case *test);
void		test_run_suite(t_test_case *suite);
void		test_cleanup(t_test_case *suite);

/* Assertion Functions*/
void	assert_true(t_test_result *result, int condition, char *msg);
void	assert_false(t_test_result *result, int condition, char *msg);
void	assert_int_eq(t_test_result *result, int expected, int actual, char *msg);
void	assert_str_eq(t_test_result *result, char *expected, char *actual, char *msg);

/*
** Utility functions
*/
char         *test_strdup(const char *str);
void         *test_memset(void *b, int c, size_t len);
void         test_print_divider(void);
void         test_print_summary(int total, int passed);

#endif
