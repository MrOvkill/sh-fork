/*
 * Program : Fork
 * File : main.c
 * License : MIT
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int runfork(char* cmd)
{
  return system(cmd);
}

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    printf("Usage : %s <command>\n", argv[0]);
    return 0;
  }
  if(!strcmp("-v", argv[1]))
  {
    printf("Version 1.0\n");
    return 0;
  }
  if(!strcmp("-h", argv[1]))
  {
    printf("Usage : %s <command>\n", argv[0]);
    return 0;
  }
  pid_t self;
  self = fork();
  if(self < 0)
  {
    printf("Error!\n");
    return 1;
  }
  else if(self > 0)
  {
    return 0;
  }
  else
  {
    int i;
    int len = 0;
    for(i = 1; i < argc; i++)
    {
      len = len + strlen(argv[i]);
    }
    char* cmd = malloc(sizeof(char) * (len + ( argc - 1 )));
    for(i = 1; i < argc; i++)
    {
      strcat(cmd, argv[i]);
      if(i != argc-1)
      {
        strcat(cmd, " ");
      }
    }
    return runfork(cmd);
  }
  return 0;
}
