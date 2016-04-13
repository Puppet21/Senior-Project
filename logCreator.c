#include <stdio.h>

int main(int argc, char **argv){
  if(argc != 2){
    printf("Hello! This program takes a valid Liberty Cup data file as imput and nothing else.\n");
    printf("./logCreator myData.txt\n");
    return 0;
  }
  FILE *dataFile;
  dataFile = fopen(argv[1], "r");
  int time, volt, poten, water, pf;
  fscanf(dataFile, "%i %i %i %i %i", &time, &volt, &poten, &water, &pf);
  fclose(dataFile);
}
