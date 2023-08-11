#include <stdio.h>
#include <ctype.h>

int main()
{
  char text[500], ch;
  int key;
  printf("Enter a Massage to Encrypt: ");
  scanf("%s", text);
  printf("Enter Your Key: ");
  scanf("%d", &key);

  for (int i = 0; text[i]; ++i)
  {
    ch = text[i];
    if (isalnum(ch))
    {
      if (islower(ch))
      {
        ch = (ch - 'a' + key) % 26 + 'a';
      }
      if (isupper(ch))
      {
        ch = (ch - 'A' + key) % 26 + 'A';
      }
      if (isdigit(ch))
      {
        ch = (ch - '0' + key) % 10 + '0';
      }
    }
    else
    {
      printf("Invalid Message");
    }
    text[i] = ch;
  }
  printf("Encrypted message: %s\n", text);

  printf("decrypt message: %s", decode());

  return 0;
}
int decode()
{

  char text[500], ch;
  int key;
  printf("Enter a Massage to decrypt: ");
  scanf("%s", text);
  printf("Enter Your Key: ");
  scanf("%d", &key);
  for (int i = 0; text[i]; ++i)
  {
    ch = text[i];
    if (isalnum(ch))
    {
      if (islower(ch))
      {
        ch = (ch - 'a' - key) % 26 + 'a';
      }
      if (isupper(ch))
      {
        ch = (ch - 'A' - key) % 26 + 'A';
      }
      if (isdigit(ch))
      {
        ch = (ch - '0' - key) % 10 + '0';
      }
    }
    else
    {
      printf("Invalid Message");
    }
    text[i] = ch;
  }
  printf("decrypt message: %s", text);
}
