# ft_test - a simple test framework

Core Features:
- Run individual test cases
- Group tests into test suites
- Display test results clearly
- Handle basic assertions
- Follow the Norm requirements


## Structure
```
shell/
├── tests/
│   ├── ft_test/              # Test framework library
│   │   ├── inc/
│   │   │   └── ft_test.h    # Framework header
│   │   └── src/
│   │       ├── assertions.c  # Test assertions
│   │       ├── test_runner.c # Test execution
│   │       └── utils.c       # Helper functions
│   ├── test_cases/          # Your test files
│   │   └── test_builtins.c  # Tests for shell builtins
│   ├── Makefile
│   └── test_main.c          # Main test runner
└── src/
    └── builtins/
        └── pwd.c            # Your shell code
```

## How to Write Tests

1. Create a test function:
```c
static void test_pwd_basic(t_test_result *result)
{
    char *pwd = ft_pwd();
    assert_true(result, pwd != NULL, "pwd should not return NULL");
    free(pwd);
}
```

2. Register your tests:
```c
void register_builtin_tests(t_test_case **suite)
{
    test_add(suite, test_create("PWD Basic Test", test_pwd_basic));
}
```

3. Add your test file to `tests/Makefile`:
```makefile
TEST_SRCS := test_main.c \
             test_cases/your_new_test.c
```

## Available Assertions
- `assert_true(result, condition, message)`
- `assert_false(result, condition, message)`
- `assert_int_eq(result, expected, actual, message)`
- `assert_str_eq(result, expected, actual, message)`

## How to Run Tests
```bash
# From project root
make test

# From tests directory
make run
```

## Common Issues
1. Missing includes? Add to ft_test.h
2. Linking errors? Check library order in Makefile
3. New test file not found? Add to TEST_SRCS in Makefile

## Tips
1. Always free allocated memory in tests
2. Use descriptive test names
3. One test function per behavior
4. Include both success and failure cases
