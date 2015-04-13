#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE 128


int count=0;
int number=1;
//prototypes
int check(char alpha, char word[20]);
int num(char alpha,char token[count], char word[12]);

int main(int argc, char const *argv[])
{
  FILE *pf;
  int x=0; // x is trueif x =1 false if x=0.
  
  pf = fopen("dict.txt","r");

  char word[20];
  char buffer[BUFFER_SIZE];
  //int count =0;

  printf("enter the length of your word\n");
  scanf("%zd",&count);
  count++;

  printf("now enter the alphabets given to you for guessing? \n");
  scanf("%s", word);

  if(pf !=NULL)
    {
      while(fgets(buffer, BUFFER_SIZE, pf) != NULL)
	{
	  char *token = strtok(buffer,".,:;?!\t\n");
	  while(token != NULL)
	    {
	      // printf("size=%zd word=%s\n", strlen(token), token);
	      //if buffer matches print it and its our answer.
	      // now main thing starts here.
	      if( strlen(token) == count )
		{
		  //now check here if the word contains all the alphabets in the string we entered then print it.
		  //printf("size = %zd word:%s\n", strlen(token)-1, token);
		  x=1;
		  // start work here.
		  for (int i=0; i<count-1; i++)
		    {
		      x= num(token[i], token, word);
		      if(x==0)
			break;

		      //printf("%d",i);
		      x = check(token[i], word);
		      if(x==0)
			break;
		    }
		  if(x==1)
		    {
		      printf("%d %s\n",number,token);
		      number++;
		    }
		  //printf("\n");
		}


	      token = strtok(NULL, ".,:;?!\n");
	    }
	}
    }
  
  //printf("deepak = %zd",strlen("deepak"));
  printf("count = %d\n",count-1);
  printf("word : %s\n", word);
  //printf("%d\n",strlen("zoo"));
  
  fclose(pf);

  //printf("\n %d ",check('x',"sdfsa"));
  if(num('g', "bridge", "qtnseykfaaoh" ) == 1)
    printf("\npossible\n");
  else
    printf("\n NO NO\n");  
  printf("\n\n");
  return 0;
}


int check(char alpha, char word[20])
{
  int i;
  for(i=0; i<12; i++)
    {
      if(word[i] == '\n' )
	{
	  return 1;
	}
      else if(word[i] == alpha)
	{
	  return 1;
	}
    }
  return 0;
}

int num(char alpha, char token[count], char word[12])
{
  int x_token=0;
  int x_word=0;
  for(int i=0; i<count; i++)
    {
      if(alpha == token[i])
	x_token++;
    }
  
  for(int j=0; j<12; j++)
    {
      if(alpha == word[j])
	x_word++;
    }
  if(x_token <= x_word)
    return 1;
  return 0;
}
