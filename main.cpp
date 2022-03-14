#include<stdio.h>

// E -> (E + E)
// E -> (E - E)
// E -> (E * E)
// E -> (E / E)
// E -> (E ^ E)
// E -> letter

char exp[400];
int pos;


int T(int *Tval)
{
if (exp[pos]>='0' && exp[pos]<='9')
   {
   *Tval=exp[pos]-'0';
   pos++;
   return 1;
   }
return 0;
}

int E()
{
  if (exp[pos] == '(')
  {
    pos++;
    if (E())
    {
      if (exp[pos] == '+' || exp[pos] == '-' || exp[pos] == '*' || exp[pos] == '/' || exp[pos] == '^')
      {
        char operador = exp[pos];
        pos++;
        if (E())
        {
          if (exp[pos] == ')')
          {
            pos++;
            printf("%c",operador);
            return 1;
          }
        }
      }
    }

    return 0;
  }
  else if ((exp[pos] >= 'a' && exp[pos] <= 'z') || (exp[pos] >= 'A' && exp[pos] <= 'Z'))
  {
    printf("%c",exp[pos]);
    pos++;
    return 1;
  }
  return 0;
}

int main() {

  int i, ne =0;
  
  scanf("%d",&ne);

  for(i =0; i<ne;i++){
    scanf("%s",exp);
    pos=0;
    E();
    printf("\n");
  }

  return 0;
}
