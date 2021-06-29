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

bool *PasswordFormatChecklist(char *str)
{
    bool checklist[6];

    if (strlen(str) >= 8 && strlen(str) <= 14)
        checklist[0] = true;
    else
        checklist[0] = false;
}