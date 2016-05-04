#include <stdio.h>


#include <string.h>
void graphOUT(int x, int* y){
  
  FILE *pipe_out = popen("gnuplot","w");
  
  fputs("set terminal png\n", pipe_out);
  fputs("plot '-' u 1:2\n", pipe_out);
  int f = 0;
  for(f=0;f<x;f++){
    fprintf(pipe_out, "%i %i\n", x, y[x]);
  }
  fputs("e\n",pipe_out);
  pclose(pipe_out);

  
  return;
}

int pot(int* timeH, int* timeM, int* timeS, int* pump , int slice){
  graphOUT(slice,pump);
  return 0;  
}

int apot(int timeTotal, int* pump, int slice){ // WORKS
  int x;
  double Avg;
  for(x = 0; x <slice; x++){
    Avg = Avg + pump[x];
  }
  Avg = Avg/slice;
  //printf("Avg after count = %f\n",Avg);
  Avg = Avg/timeTotal;
  printf("Average pump over time RESULT = %lf\n", Avg);
 
  return 0;
}

int wlot(int slice, double* Water){
  int t;
  for(t = 0; t< slice; t++){
    printf("%lf",Water[t]);
  }
  FILE *pipe_out = popen("gnuplot","w"); //this graph uses special double version.
  
  
  fputs("set terminal png\n", pipe_out);
  fputs("plot '-' u 1:2\n", pipe_out);
  int x = 0;
  for(x=0;x<slice;x++){
    fprintf(pipe_out, "%i %lf\n", x, Water[x]);
    
  }
  fputs("e\n",pipe_out);
  pclose(pipe_out);
  return 0;
}

int aw(int timeTotal, double* Water, int slice){ //average water
  int x=0;
  double Avg=0.0;

  for(x=0; x <slice; x++){
    Avg = Avg + Water[x];
    printf("Avg = %lf \n", Avg);
  }
  printf("slice = %i\n",slice);
  Avg = Avg/slice; 
  printf("Timetot = %i\n",timeTotal);
  Avg = Avg/timeTotal;
  printf("Average Water over time RESULT = %lf\n", Avg);
  return 0;
}

int fsrot(int slice, int *fsr){ //method exists so additional functions can be added

  graphOUT(slice, fsr);
  return 0;
}

int TimeTot(int timeH, int timeM, int timeS){ //Unused due to to time slice being easier
  printf("timeH = %i\n", timeH);
  timeM = timeM + timeH *60;
  printf("timeM = %i\n", timeM);
  timeS = timeS + timeM *60;
  printf("timeS = %i\n", timeS);
  return timeS;
}



int main(int argc, char** argv){
  if(argc < 2 ){ //need to add check and make sure the arg matches.
    printf("Hello! This program takes a LogDataSet, a time slice, and a mode\n");
    printf("./CDM myData.txt 10 w\n");
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
  
  //printf("Validating file\n");
  if((logFile = fopen(argv[1], "r+"))==NULL){
    printf("File not valid\n");
    return(-1);
  }


 
  int TimeH[atoi(argv[2])]; //times are just place holders as time slices put more on the user.
  int TimeM[atoi(argv[2])];
  int TimeS[atoi(argv[2])];
  int Volt[atoi(argv[2])];
  int PumpPower[atoi(argv[2])];
  double Water[atoi(argv[2])]; 
  int Pf[atoi(argv[2])];;
  //format is [timeH timeM timeS volt poten water pf]                           
  //          [timeH timeM timeS volt
  //          
  //  
  //printf("Time slice%i\n",atoi(argv[2]));
  int IDs = atoi(argv[2]);
  int count =0;
  //  printf("Loading file...\n");
  //while(!feof(logFile)){
  int x;
  for(x= 0; x < IDs;x++){
    fscanf(logFile, "%i %i %i %i %i %lf %i \n", &TimeH[count], &TimeM[count], &TimeS[count], &Volt[count], &PumpPower[count], &Water[count], &Pf[count]); //reading in data, each count is a time slice
    count++;
  }
  int y;
  for(y = 0; y< IDs; y++){
    printf("Water at %i = %f\n",y,Water[y]);
  }
  
  if(strcmp(argv[3],"p")==0){
    pot(TimeH,TimeM,TimeS,PumpPower, IDs);
    
  }
  else if(strcmp(argv[3],"ap")==0){
    if(apot(IDs,PumpPower,IDs) != 0){
      printf("ERR");
    }
  }
  else if(strcmp(argv[3], "w")==0){
    wlot(IDs, Water);
    
  }
  else if(strcmp(argv[3], "aw")==0){
    printf("Average water level.\n");
    printf("IDs = %i\n",IDs);
    aw(IDs, Water, IDs); //Possible Glitch site, Requires further testing, May give grossly incorrect numbers.
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
  

  

  
  fclose(logFile);
}

