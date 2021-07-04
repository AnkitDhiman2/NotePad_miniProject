/** 
* @file passwordUsernameFormatChecker.h
*  functions to check the format of the password and username
*
*/
#ifndef __PASSWORD_USERNAME_FORMAT_CHECKER_H__
#define __PASSWORD_USERNAME_FORMAT_CHECKER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    bool numberOfCharacterisEnough;
    bool doesNotContainSpaces;
    bool containSpecialCharacter;
    bool containNumber;
    bool containUpperCaseLetter;
    bool containLowerCaseLetter;
} passwordChecklist;

typedef struct
{
    bool numberOfCharacterisEnough;
    bool doesNotContainSpaces;
    bool containSpecialCharacter;
} usernameChecklist;

/**
*  check if string contain special characters or not
* @param[in] string to check
* @return  true if string contains a special character otherwise returns false
*/
bool containSpecialCharacter(const char *str);

/**
* check if string contains number or not
* @param[in] string 
* @return  true if string contains a number otherwise returns false
*/
bool containNumber(const char *str);

/**
*  check if string contain lower case letter or not
* @param[in] string 
* @return  true if string contains a lower case otherwise returns false
*/
bool containLowerCaseLetter(const char *str);

/**
*  check if string contain upper case letter or not
* @param[in] string to check
* @return  true if string contains a upper case otherwise returns false
*/
bool containUpperCaseLetter(const char *str);

/**
* Password checker program basically checks if the password is valid or not based on password policies mention below:
* Password should not contain any space.
* Password should contain at least one digit(0-9).
* Password length should be between 8 to 15 characters.
* Password should contain at least one lowercase letter(a-z).
* Password should contain at least one uppercase letter(A-Z).
* Password should contain at least one special character ( @, #, %, &, !, $, etc….).
* @param[in] password 
* @return  a struct passwordChecklist  containing true or false according to given points
* @note for e.g if password format is correct function will return an array {true, true, true, true, true, true} one bool value for each check
*/
passwordChecklist PasswordFormatChecklist(const char *str);

/**
* Username should not contain any space.
* Username length should be between 4 to 15 characters.
* Username should not contain any special character ( @, #, %, &, !, $, etc….).
* @param[in] username
* @return  a struct usernameChecklist containing true or false according to given points
*/
usernameChecklist UserNameFormatChecklist(const char *str);

#endif /* #define __CALCULATOR_OPERATIONS_H__ */