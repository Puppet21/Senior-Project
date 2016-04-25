#include <stdio.h>
#include <string.h>
int pot(){
  printf("pump over timeslice");
  return 0;  
}

int apot(){
  printf("Average pump over time");
  return 0;
}

int wlot(int slice, int** pumpPower){
  return 0;
}





int main(int argc, char** argv){
  if(argc < 2 ){ //need to add check and make sure the arg matches.
    printf("Hello! This program takes a LogDataSet, a time slice, and a mode\n");
    printf("./CDM myData.txt 10 \n");
    printf(" MODES; \n");
    printf(" ");
    printf("Results are an output... the time slice is in seconds!");
    return 0;
  }
  FILE *logFile;
  /*
   * This system takes a time slice in seconds set by the user, and does the function.
   * The algorythim is as such, the program takes the users time slice and performs
   * the set function over that set of time, revealing a graph.
   *
   */
  
  
  if((logFile = fopen(argv[1], "r+"))==NULL){
    printf("File not valid");
    return(-1);
  }
  //second valid input check goes here

  if(strcmp(argv[3],"p")==0){
    printf("Pump usage over time");
  }
  else if(strcmp(argv[3],"ap")==0){
    printf("Average pump useage over time"); //use over long time slices to determine pump performance.
  }
  else if(strcmp(argv[3], "w")==0){
    printf("Water level over time slice graph"); //Suggested for a few days.
  }
  else if(strcmp(argv[3],"fsr")==0){
    printf("Fsr reading over time slice graph"); //Suggested for small time slice,
  }
  else if(strcmp(argv[3], "b")==0){
    printf("Battery level over time-slice graph");
  }
  else if(strcmp(argv[3], "ab")==0){
    printf("Average battery use over time");//use over long time for battery performance.
  }
  else if(strcmp(argv[3], "aw")==0){
    printf("Average water use.");
  }
  else{
    printf("Not a valid modifier");
    return (-1);
  }
  /*
   *TODO
   *FILE LOADING
   *Specific functions
   *  TIME:
   *
   *GRAPHING.
   *
   */
  

  int timeH, timeM, timeS, volt, pumpPower, water, pf = 0;
  //format is [timeH timeM timeS volt poten water pf]                           
  //          
  //          
  //           
  
  while(!feof (logFile)){
    fscanf(logFile, "%i %i %i %i %i %i %i \n", &timeH, &timeM, &timeS, &volt, &pumpPower, &water, &pf);
    printf("%i", timeH);
  }


  
  fclose(logFile);
}
