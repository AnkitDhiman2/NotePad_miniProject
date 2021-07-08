#include "unity.h"
#include "passwordUsernameFormatChecker.h"
#include "masterAccountFunctions.h"
#define PROJECT_NAME "TextPad"

/* Prototypes for all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/
void test_containSpecialCharacter(void);
void test_containNumber(void);
void test_containLowerCaseLetter(void);
void test_containUpperCaseLetter(void);
void test_passwordFormatCheck(void);
void test_usernameFormatCheck(void);

/********************************
 * Filename -> masterAccountFunctions.c
*/
void test_userAccountExist(void);
void test_createMasteUserAccount(void);
void test_verifyMasterUserAccount(void);
void test_deleteMasterUserAccount(void);
void test_modifyMasterUsername(void);
void test_modifyMasterPassword(void);
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown() {}

/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */

  /********************************
 * Filename -> passwordUsernameFormatChecker.c
 */
  RUN_TEST(test_containSpecialCharacter);
  RUN_TEST(test_containNumber);
  RUN_TEST(test_containLowerCaseLetter);
  RUN_TEST(test_containUpperCaseLetter);
  RUN_TEST(test_passwordFormatCheck);
  RUN_TEST(test_usernameFormatCheck);

  /********************************
 * Filename -> masterAccountFunctions.c
*/
  RUN_TEST(test_userAccountExist);
  RUN_TEST(test_createMasteUserAccount);
  RUN_TEST(test_verifyMasterUserAccount);
  RUN_TEST(test_deleteMasterUserAccount);
  RUN_TEST(test_modifyMasterUsername);
  RUN_TEST(test_modifyMasterPassword);
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/
void test_containSpecialCharacter(void)
{
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankit$kumar"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankitkumar#"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("@ankit$kumar*"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumars d"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("asdfsad"));
}

void test_containNumber(void)
{
  TEST_ASSERT_EQUAL(true, containNumber("ankit23kumar"));
  TEST_ASSERT_EQUAL(true, containNumber("ankitkumar23"));
  TEST_ASSERT_EQUAL(true, containNumber("12ankitkumar"));
  TEST_ASSERT_EQUAL(false, containNumber("ankitkumar"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FS23D$#$@!#!@"));
}

void test_containLowerCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("andaskjds"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("ANKITUMAr"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("aNKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("####$!@$!$!$#$@!#!@"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$er#$@!#!@"));
}

void test_containUpperCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ankitkumaR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("Ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("####$!@$!$!$#$@!#!@"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
}

void test_passwordFormatCheck(void)
{
  TEST_ASSERT_EQUAL(true, passwordFormatCheck("@nkitKumar123"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("nk"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("asdfasdfsdafasdfasdfaf"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("@nkitKumar"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("ankit$umar123"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("@NKITKUMAR123"));
}

void test_usernameFormatCheck()
{
  TEST_ASSERT_EQUAL(true, usernameFormatCheck("ankit123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@nkitKumar123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("nk"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("asdfasdfsdafasdfasdfaf"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@nkitKumar"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("ankit$umar123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@NKITKUMAR123"));
}

/********************************
 * Filename -> masterAccountFunctions.c
*/
void test_userAccountExist(void)
{
  deleteMasterUserAccount();
  TEST_ASSERT_EQUAL(false, masterUserAccountExist());

  createMasterUserAccount("AnkitKumar", "Ankit123");
  TEST_ASSERT_EQUAL(true, masterUserAccountExist());
}

void test_createMasteUserAccount(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, createMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(NULL_PTR, createMasterUserAccount(NULL, NULL));
}

void test_verifyMasterUserAccount(void)
{
  createMasterUserAccount("AnkitKumar", "Ankit123");
  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnshulKumar", "Ankit12334"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar", "Ankit123232312"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar2323", "Ankit123"));

  createMasterUserAccount("RandomUSERNMAE@#@$!@#", "RandomPassword@#$#@");

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("RandomUSERNMAE@#@$!@#", "RandomPassword@#$#@"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnshulKumar", "Ankit12334"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar", "Ankit123232312"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar2323", "Ankit123"));
}

void test_deleteMasterUserAccount(void)
{
  createMasterUserAccount("Ankit123", "Ankit123");
  TEST_ASSERT_EQUAL(SUCCESS, deleteMasterUserAccount());

  TEST_ASSERT_EQUAL(FAILURE, deleteMasterUserAccount());
}

void test_modifyMasterPassword(void)
{
  createMasterUserAccount("old_username", "old_password");

  TEST_ASSERT_EQUAL(SUCCESS, modifyMasterPassword("new_password"));

  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("old_username", "old_password"));

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("old_username", "new_password"));
}

void test_modifyMasterUsername(void)
{
  createMasterUserAccount("old_username", "old_password");

  TEST_ASSERT_EQUAL(SUCCESS, modifyMasterUsername("new_username"));

  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("old_username", "old_password"));

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("new_username", "old_password"));
}