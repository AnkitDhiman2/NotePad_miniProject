#include "passwordUsernameFormatChecker.h"

bool containSpecialCharacter(const char *str)
{
    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        //checking each character of the string for special character.
        if (str[index] == '!' ||
            str[index] == '@' ||
            str[index] == '#' ||
            str[index] == '$' ||
            str[index] == '%' ||
            str[index] == '^' ||
            str[index] == '&' ||
            str[index] == '*' ||
            str[index] == '(' ||
            str[index] == ')' ||
            str[index] == '-' ||
            str[index] == '{' ||
            str[index] == '}' ||
            str[index] == '[' ||
            str[index] == ']' ||
            str[index] == ':' ||
            str[index] == ';' ||
            str[index] == '"' ||
            str[index] == '\'' ||
            str[index] == '<' ||
            str[index] == '>' ||
            str[index] == '.' ||
            str[index] == '/' ||
            str[index] == '?' ||
            str[index] == '~' ||
            str[index] == '`')
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool containNumber(const char *str)
{

    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        if (isdigit(str[index]))
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool containLowerCaseLetter(const char *str)
{
    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        if (str[index] >= 'a' && str[index] <= 'z')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool containUpperCaseLetter(const char *str)
{
    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        if (str[index] >= 'A' && str[index] <= 'Z')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

passwordChecklist PasswordFormatChecklist(const char *password)
{
    passwordChecklist checklist;

    //Passsword length shoud be between 8 and 14
    if (strlen(password) >= 8 && strlen(password) <= 14)
    {
        checklist.numberOfCharacterisEnough = true;
    }
    else
    {
        checklist.numberOfCharacterisEnough = false;
    }

    //Password should not contain any spaces;
    if (strchr(password, ' ') == NULL)
    {
        checklist.doesNotContainSpaces = true;
    }
    else
    {
        checklist.doesNotContainSpaces = false;
    }

    //Password Should contain special Characters
    if (containSpecialCharacter(password))
    {
        checklist.containSpecialCharacter = true;
    }
    else
    {
        checklist.containSpecialCharacter = false;
    }

    //password should contain lowercaseletter
    if (containLowerCaseLetter(password))
    {
        checklist.containLowerCaseLetter = true;
    }
    else
    {
        checklist.containLowerCaseLetter = false;
    }

    //password should contain uppercase letter
    if (containUpperCaseLetter(password))
    {
        checklist.containUpperCaseLetter = true;
    }
    else
    {
        checklist.containUpperCaseLetter = false;
    }

    return checklist;
}

usernameChecklist UserNameFormatChecklist(const char *username)
{
    usernameChecklist checklist;

    // username length should be between 4 and 15
    if (strlen(username) >= 4 && strlen(username) <= 15)
    {
        checklist.numberOfCharacterisEnough = true;
    }
    else
    {
        checklist.numberOfCharacterisEnough = false;
    }

    //username should not contain any spaces
    if (strchr(username, ' ') == NULL)
    {
        checklist.doesNotContainSpaces = true;
    }
    else
    {
        checklist.doesNotContainSpaces = false;
    }

    // username should not contain any special characters
    if (containSpecialCharacter(username))
    {
        checklist.containSpecialCharacter = false;
    }
    else
    {
        checklist.containSpecialCharacter = true;
    }

    return checklist;
}