
#include "unity.h"
#include "passwordUsernameFormatChecker.h"

void test_containSpecialCharacter(void);
void test_containNumber(void);
void test_containLowerCaseLetter(void);
void test_containUpperCaseLetter(void);
void test_passwordFormatChecklist(void);

void test_containSpecialCharacter(void)
{
    TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankit$kumar"));
    TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankitkumar#"));
    TEST_ASSERT_EQUAL(true, containSpecialCharacter("@ankit$kumar*"));
    TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumar"));
    TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumars d"));
    TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
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
    TEST_ASSERT_EQUAL(true, containLowerCaseLetter("ANKITKUMAR"));
    TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ankitkumaR"));
    TEST_ASSERT_EQUAL(true, containUpperCaseLetter("Ankitkumar"));
    TEST_ASSERT_EQUAL(false, containUpperCaseLetter("ankitkumar"));
    TEST_ASSERT_EQUAL(false, containUpperCaseLetter("####$!@$!$!$#$@!#!@"));
    TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
}

void test_passwordFormatChecklist(void)
{
    //test 1
    passwordChecklist checklist = PasswordFormatChecklist("@nkitKumar123");
    int expected[6] = {
        true,
        true,
        true,
        true,
        true,
        true};
    int actual[6] = {
        checklist.numberOfCharacterisEnough,
        checklist.doesNotContainSpaces,
        checklist.containSpecialCharacter,
        checklist.containNumber,
        checklist.containLowerCaseLetter,
        checklist.containUpperCaseLetter};
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected, actual, 2);

    //test 2
    checklist = PasswordFormatChecklist("@nkit Kumar123");
    int expected2[6] = {
        true,
        false,
        true,
        true,
        true,
        true};
    int actual2[6] = {checklist.numberOfCharacterisEnough,
                      checklist.doesNotContainSpaces,
                      checklist.containSpecialCharacter,
                      checklist.containNumber,
                      checklist.containLowerCaseLetter,
                      checklist.containUpperCaseLetter};
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected2, actual2, 6);

    // test 3
    checklist = PasswordFormatChecklist("ank");
    int expected3[6] = {
        false,
        true,
        false,
        false,
        true,
        false};
    int actual3[6] = {
        checklist.numberOfCharacterisEnough,
        checklist.doesNotContainSpaces,
        checklist.containSpecialCharacter,
        checklist.containNumber,
        checklist.containLowerCaseLetter,
        checklist.containUpperCaseLetter};
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected3, actual3, 6);

    //test 4
    checklist = PasswordFormatChecklist("123214341");
    int expected4[6] = {
        true,
        true,
        false,
        true,
        false,
        false};
    int actual4[6] = {
        checklist.numberOfCharacterisEnough,
        checklist.doesNotContainSpaces,
        checklist.containSpecialCharacter,
        checklist.containNumber,
        checklist.containLowerCaseLetter,
        checklist.containUpperCaseLetter};
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected4, actual4, 6);

    //test 5
    checklist = PasswordFormatChecklist(" ");
    int expected5[6] = {
        false,
        false,
        false,
        false,
        false,
        false};
    int actual5[6] = {
        checklist.numberOfCharacterisEnough,
        checklist.doesNotContainSpaces,
        checklist.containSpecialCharacter,
        checklist.containNumber,
        checklist.containLowerCaseLetter,
        checklist.containUpperCaseLetter};
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected5, actual5, 6);
}