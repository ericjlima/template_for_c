#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef GLOBALS_H
#define GLOBALS_H
  typedef enum { FALSE=0, TRUE=1 } bool;
  typedef enum { SUCCESS=0, ERROR=1 } status;
  typedef void *generic_ptr;

  /**
   * Test Framework
   */
  status allocate_data(int **data_ptr, int value);
  status free_data(int **data_ptr);

  /**
   * Test Framework: Expectations
   */
  status expect(int *a, bool (*compare)(int *a, int *b), int *b, char *message);
  status expect_null(generic_ptr object_ptr, char *message);
  status expect_non_null(generic_ptr object_ptr, char *message);
  status expect_success(status s, char *message);
  status expect_error(status s, char *message);
  status expect_true(bool b, char *message);
  status expect_false(bool b, char *message);

  /**
   * Test Framework: Comparison Functions
   */
  bool  to_be(int *a, int *b);
  bool  to_not_be(int *a, int *b);
#endif
