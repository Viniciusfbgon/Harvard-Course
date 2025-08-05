#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_char(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!check_char(argv[1]))
    {
        printf("Key must contain 26 unique characters.\n");
    }
bool check_char(string key);
{
    int length;
    length = strlen(key);

    if (length != 26)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        key[i] = toupper(key[i]);
        for (int j = i+1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
}
    return true;

}
