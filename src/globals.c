#include "globals.h"

/**
 * Allocates a pointer to an integer for testing purposes.
 *
 * data_ptr - a pointer to a pointer to an integer. It will contain the
 *  address of the space allocated.
 * value - the integer value to store
 *
 * Returns a status
 */
status allocate_data(int **data_ptr, int value)
{
  *data_ptr = (int *) malloc(sizeof(int));

  if (data_ptr == NULL) {
    return ERROR;
  }

  **data_ptr = value;
  return SUCCESS;
}


/**
 * Free a pointer to an integer for testing purposes.
 *
 * data_ptr - a pointer to a pointer to an integer. It will be NULLed out.
 *
 * Returns a status
 */
status free_data(int **data_ptr)
{
  if (data_ptr == NULL) {
    return ERROR;
  }

  free(*data_ptr);
  *data_ptr = NULL;
  return SUCCESS;
}

/**
 * Tester helper that provides a standardized output out results.
 *
 * a - pointer to an integer or NULL, the variable value, value to test
 * compare - a function that takes two integer pointers and returns a boolean
 * b - pointer to an integer or NULL, the expected value, the control value
 * message - a string representing the expected behavior, no punctionation at
 *  the end
 *
 * Returns a status
 */
status expect(int *a, bool (*compare)(int *, int *), int *b, char *message)
{
  bool result;
  printf("%s: ", message);

  result = (*compare)(a, b);

  if (result == FALSE) {
    printf("failed\n");
    printf("\texpected %d, got %d.\n", *b, *a);
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

status expect_null(generic_ptr object_ptr, char *message)
{
  printf("%s: ", message);

  if (object_ptr != NULL) {
    printf("failed\n");
    printf("\texpected NULL, got %p.\n", object_ptr);
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

status expect_non_null(generic_ptr object_ptr, char *message)
{
  printf("%s: ", message);

  if (object_ptr == NULL) {
    printf("failed\n");
    printf("\texpected non NULL, got NULL.\n");
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

status expect_success(status s, char *message)
{
  printf("%s: ", message);

  if (s != SUCCESS) {
    printf("failed\n");
    printf("\texpected SUCCESS(0), got ERROR(1).\n");
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

status expect_error(status s, char *message)
{
  printf("%s: ", message);

  if (s != ERROR) {
    printf("failed\n");
    printf("\texpected ERROR(1), got SUCCESS(0).\n");
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

status expect_true(bool b, char *message)
{
  printf("%s: ", message);

  if (b != TRUE) {
    printf("failed\n");
    printf("\texpected TRUE(1), got FALSE(0).\n");
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

status expect_false(bool b, char *message)
{
  printf("%s: ", message);

  if (b != FALSE) {
    printf("failed\n");
    printf("\texpected FALSE(0), got TRUE(1).\n");
    return ERROR;
  }

  printf("passed.\n");
  return SUCCESS;
}

/**
 * Tester helper that checks equality.
 *
 * a - a pointer to integer
 * b - a pointer to integer
 *
 * Returns a bool representing equality
 */
bool to_be(int *a, int *b)
{
  if ((*a) == (*b)) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Tester helper that checks inequality.
 *
 * a - a pointer to integer
 * b - a pointer to integer
 *
 * Returns a bool representing inequality
 */
bool to_not_be(int *a, int *b)
{
  if ((*a) != (*b)) {
    return TRUE;
  }

  return FALSE;
}
