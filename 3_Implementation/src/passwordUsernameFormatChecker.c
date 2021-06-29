#include <passwordUsernameFormatChecker.h>

bool containSpecialCharacter(char *str)
{
    bool flag = false;

    for (int i = 0; i < strlen(str); i++)
    {
        //checking each character of the string for special character.
        if (str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*' || str[i] == '(' || str[i] == ')' || str[i] == '-' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == ':' || str[i] == ';' || str[i] == '"' || str[i] == '\'' || str[i] == '<' || str[i] == '>' || str[i] == '.' || str[i] == '/' || str[i] == '?' || str[i] == '~' || str[i] == '`')
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool containNumber(char *str)
{

    bool flag = false;

    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool containLowerCaseLetter(char *str)
{
    bool flag = false;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool containUpperCaseLetter(char *str)
{
    bool flag = false;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

passwordChecklist PasswordFormatChecklist(char *str)
{
    passwordChecklist checklist;

    //Passsword length shoud be between 8 and 14
    if (strlen(str) >= 8 && strlen(str) <= 14)
    {
        checklist.numberOfCharacterisEnough = true;
    }
    else
    {
        checklist.numberOfCharacterisEnough = false;
    }

    //Password should not contain any spaces;
    if (strchr(str, ' ') == NULL)
    {
        checklist.doesNotContainSpaces = true;
    }
    else
    {
        checklist.doesNotContainSpaces = false;
    }

    //Password Should contain special Characters
    if (containSpecialCharacter(str))
    {
        checklist.containSpecialCharacter = true;
    }
    else
    {
        checklist.containLowerCaseLetter = false;
    }

    //password should contain lowercaseletter
    if (containLowerCaseLetter(str))
    {
        checklist.containLowerCaseLetter = true;
    }
    else
    {
        checklist.containLowerCaseLetter = false;
    }

    //password should contain uppercase letter
    if (containUpperCaseLetter(str))
    {
        checklist.containUpperCaseLetter = true;
    }
    else
    {
        checklist.containUpperCaseLetter = false;
    }

    return checklist;
}