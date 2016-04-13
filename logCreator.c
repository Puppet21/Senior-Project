#include <stdio.h>
/*This program transfers the Libery Cup's raw data into 
 *
 *
 *
 *
 */

int voltCheck(int volt){
  return 0;
}
int potenCheck(int poten){
  return 0;
}
int waterCheck(int water){
  return 0;
}
int purgeCheck(int pf){
  if(pf != 1 || pf != 0){
    return -1;
  }
  else{
    return pf;
  }
}





int main(int argc, char **argv){
  if(argc != 2){
    printf("Hello! This program takes a valid Liberty Cup data file as imput and nothing else.\n");
    printf("./logCreator myData.txt\n");
    printf("Results are a file.");
    return 0;
  }
  FILE *dataFile;
  dataFile = fopen(argv[1], "r");
  int time, volt, poten, water, pf;
  //format is [time volt poten water pf]
  //          [time volt poten water pf]
  //          [time volt poten water pf]
  //          [time volt poten water pf]...
  fscanf(dataFile, "%i %i %i %i %i", &time, &volt, &poten, &water, &pf); 
  
  
  
  fclose(dataFile);
}

