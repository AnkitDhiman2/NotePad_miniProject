#include "unity.h"
//#include <passwordUsernameFormatChecker.h>
/* Modify these two lines according to the project */
#include <passwordUsernameFormatChecker.h>
#define PROJECT_NAME "TextPad"

/* Prototypes for all the test functions */
void test_containSpecialCharacter(void);
void test_containNumber(void);
void test_containLowerCaseLetter(void);
void test_containUpperCaseLetter(void);
// void test_divide(void);

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */
  RUN_TEST(test_containSpecialCharacter);
  RUN_TEST(test_containNumber);
  RUN_TEST(test_containLowerCaseLetter);
  RUN_TEST(test_containUpperCaseLetter);
  // RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */
void test_containSpecialCharacter(void)
{
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankit$kumar"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankitkumar#"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("@ankit$kumar*"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumars d"));
}

void test_containNumber(void)
{
  TEST_ASSERT_EQUAL(true, containNumber("ankit23kumar"));
  TEST_ASSERT_EQUAL(true, containNumber("ankitkumar23"));
  TEST_ASSERT_EQUAL(true, containNumber("12ankitkumar"));
  TEST_ASSERT_EQUAL(false, containNumber("ankitkumar"));
}

void test_containLowerCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("andaskjds"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("ANKITUMAr"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("aNKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("####$!@$!$!$#$@!#!@"));
}

void test_containUpperCaseLetter()
{
  //TEST_ASSERT_EQUAL(true, containLowerCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ankitkumaR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("Ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("####$!@$!$!$#$@!#!@"));
}

// void test_add_testcase2(void)
// {

//   /* Dummy fail*/
//   // TEST_ASSERT_EQUAL(1500, add(750, 7500));
// }
// void test_subtract(void)
// {
//   TEST_ASSERT_EQUAL(-3, subtract(0, 3));

//   /* Dummy fail*/
//   // TEST_ASSERT_EQUAL(1, subtract(1000, 900));
// }

// void test_multiply(void)
// {
//   TEST_ASSERT_EQUAL(0, multiply(1, 0));

//   /* Dummy fail*/
//   // TEST_ASSERT_EQUAL(2, multiply(2, 5));
// }

// void test_divide(void)
// {
//   TEST_ASSERT_EQUAL(0, divide(1, 0));

//   /* Dummy fail*/
//   // TEST_ASSERT_EQUAL(3, divide(2, 2));
// }
