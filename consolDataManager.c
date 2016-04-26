#include <stdio.h>
#include <string.h>
int pot(){
  printf("pump over timeslice\n");
  return 0;  
}

int apot(){
  printf("Average pump over time");
  return 0;
}

int wlot(int slice, int** pumpPower){
  return 0;
}

int fsrot(){
  return 0;
}
int TimeTot(int timeH, int timeM, int timeS){
  int total = 0;
  timeM = timeH *60;
  timeS = timeM *60;
  return total;
}



int main(int argc, char** argv){
  if(argc < 2 ){ //need to add check and make sure the arg matches.
    printf("Hello! This program takes a LogDataSet, a time slice, and a mode\n");
    printf("./CDM myData.txt 10 \n");
    printf(" MODES; \n p:  Pump (potentiometer) usage over time\n");
    printf(" ");
    printf("Results are an output... the time slice is in seconds!\n");
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
    printf("File not valid\n");
    return(-1);
  }

  //second valid input check goes here
  printf("%i\n", atoi(argv[2]));

  if(strcmp(argv[3],"p")==0){
    printf("Pump usage over time.\n");
  }
  else if(strcmp(argv[3],"ap")==0){
    printf("Average pump useage over time.\n"); //use over long time slices to determine pump performance.
  }
  else if(strcmp(argv[3], "w")==0){
    printf("Water level over time slice graph.\n"); //Suggested for a few days.
  }
  else if(strcmp(argv[3],"fsr")==0){
    printf("Fsr reading over time slice graph.\n"); //Suggested for small time slice,
  }
  else if(strcmp(argv[3], "b")==0){
    printf("Battery level over time-slice graph.\n");
  }
  else if(strcmp(argv[3], "ab")==0){
    printf("Average battery use over time.\n");//use over long time for battery performance.
  }
  else if(strcmp(argv[3], "aw")==0){
    printf("Average water use.\n");
  }
  else{
    printf("Not a valid modifier\n");
    return (-1);
  }
  /*
   *TODO:
   *FILE LOADING:
   *  LOADING: BROKEN!
   *Specific functions
   *  TIME: DONE
   *  FSR:
   *  W:
   *  P:
   *  B:
   *  
   *GRAPHING GNUPLOT
   *  FUNCTIONS: gnuplot set terminal png
   *    AB:
   *    AP:
   *    AW:
   */
  

  int TimeH[atoi(argv[2])];
  int TimeM[atoi(argv[2])];
  int TimeS[atoi(argv[2])];
  int Volt[atoi(argv[2])];
  int PumpPower[atoi(argv[2])];
  int Water[atoi(argv[2])]; 
  int Pf[atoi(argv[2])];;
  //format is [timeH timeM timeS volt poten water pf]                           
  //          [timeH timeM timeS volt
  //          
  //  

  
  int count =0;
    
  while(!feof(logFile)){
    fscanf(logFile, "%i %i %i %i %i %i %i \n", &TimeH[count], &TimeM[count], &TimeS[count], &Volt[count], &PumpPower[count], &Water[count], &Pf[count]); //reading in data, each count is a time slice
    count++;

  }
  printf("%i",count);
  int TT = TimeTot(TimeH[atoi(argv[2])], TimeM[atoi(argv[2])], TimeS[atoi(argv[2])]);

  
  fclose(logFile);
}

