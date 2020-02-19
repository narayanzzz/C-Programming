#include <stdio.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
typedef int(*FuncPtr)(int,int);
int compute(FuncPtr,int,int);
FuncPtr* select(char);
int evaluateArray(char, int, int);

int main(void)
{

  //Declaring the Function pointer
  int(*fptr)(int,int);

  //Assigning the address of add function to fptr function pointer
  fptr = add;

  printf("%d\n",fptr(20,10));

  printf("%d\n",compute(add,3,4));
  printf("%d\n",compute(sub,10,5));

  printf("%d",evaluateArray('+', 10, 50));
}

int add(int a,int b)
{
  return a+b;
}

int sub(int a,int b)
{
  return a-b;
}
int mul(int a,int b)
{
  return a*b;
}

//Funcion that takes function parameter
int compute(FuncPtr fptr,int a,int b)
{
  return fptr(a,b);
}


//Function that returns function parameter
FuncPtr* select(char x)
{
  switch(x)
  {
    case '+':
    {
      return add;
      break;
    }
    case '-':
    {
      return sub;
      break;
    }
  }
}

int evaluateArray(char opcode, int num1, int num2)
{
  FuncPtr ptr = select(opcode);
  return ptr(num1,num2);
}