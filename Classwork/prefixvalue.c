#include<stdio.h>
#include<ctype.h>
// #include<string.h>
#include <string.h>

#define MAX 10
float st[MAX];
int top=-1;

float pop(float st[]);
void push(float st[],float val);
float evaluatepostfixexp(char exp[]);





void main()
{
 float val;
 char exp[100];
//  clrscr();
    
 printf("\n Enter any prefix expression: ");
   gets(exp);
//    strrev(exp);
   int k=0;
   char exp2[100];
   for(int i=strlen(exp) - 1;i>=0;i--){
       exp2[k++]=exp[i];
   }
    exp2[k]='\0';
    val=evaluatepostfixexp(exp2);
    printf("\n The corresponding value of prefix expression is: %0.2f",val);
}


float evaluatepostfixexp(char exp[])
{
     int i=0;
     float op1,op2,value;


     while(exp[i]!='\0')
     {

           if(isdigit(exp[i]))
           
              push(st,(float)(exp[i]-'0'));
            
           else
           {
              op2=pop(st);
              op1=pop(st);
               

              switch(exp[i])
              {

                 case '+':

                          value=op1+op2;
                          break;

                 case '-':

                          value=op1-op2;
                          break;

                 case '/':

                          value=op1/op2;
                          break;

                 case '*':

                          value=op1*op2;
                          break;

                 case '%':

                          value=(int)op1%(int)op2;
                          break;

             }  
              push(st,value);
        
          }
           i++;
     }
      return(pop(st));
}



void push(float st[],float val)
{
  if(top==(MAX-1))
   printf("\nStack overflow");

   else
   {
    top++;
    st[top]=val;
   }
}

float pop(float st[])
{
  float val=-1;
  if(top==-1)
   printf("\nStack underflow");
  
  else
  {
    val=st[top];
    top--;
  }

   return val;
}