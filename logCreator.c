#include <stdio.h>
#include <stdbool.h>
/*
 *This program transfers the Libery Cup's raw data into 
 *data for the consol data manager.
 *
 */




/*
 *timeCheck confirms the time, making sure the device is used, and records the correct time
 *timeH(hours) are held in a 0 - 24 hour time zone
 *timeM(minutes) are held in a 0 - 60 
 *timeS(seconds) are held in a 0 - 60
 * each are checked seperatly.
 *
 */
bool timeCheck(int timeH, int timeM, int timeS){
  if( timeH <= 24 || timeH >= 0 ){
    if(timeM <= 60 || timeM >= 0){
      if(timeS <=60 || timeM >= 0){
	return true;
      }
      return false;
    }
    return false;
  }
  
}

/*
 *voltCheck confirms the voltage parameter recieved by the ARDUINO.
 *the voltage parameter is recived from the FSR connected to the arduino.
 *It can give any number between 1023 and 0, 1023 being "off" 0 being "on"
 *voltCheck accepts voltages between 1023mv and 0mv
 *voltCheck returns the (milli)voltage or -1 if its invalid
 *
 */

int voltCheck(int volt){
  if(volt >= 12){
    return -1;
  }
  else if(volt < 0){
    return -1;
  }
  else{
    return volt;
  }
}

/*
 *potenCheck confirms the input intercepted from the pump
 *The potentiameter gives between 0V and 5V
 *The meter must be multiplied to actualy get the value the pump gained
 *the pump has a maximum of 24v, so it has been mapped, multiplying the # by 4
 *the Mapped number is returned.
 */

int potenCheck(int poten){
  int map = poten*4;
  if(poten >= 25 ||  poten < 0){ //check if it is in unsafe/unacceptable range
    return -1;
  }
  else{
    return map;
  }
}


/*
 *waterCheck takes in the volume of water in liters
 *the maximum capacity of the water is 2 liters.
 *returns the volume if it is within limits
 *
 */


int waterCheck(int water){
  if(water > 2 || water < 0){
    return -1;
  }
  else{
    return water;
  }
}

/*
 *Purge flag, if it is flagged then the line of data is removed
 *
 */
bool purgeCheck(int pf){
  if(pf == 0){
    return false;
  }
  else{
    return true;
  }
}








int main(int argc, char **argv){
  if(argc != 2){
    printf("Hello! This program takes a valid Liberty Cup data file as imput and nothing else.\n");
    printf("./logCreator myData.txt\n");
    printf("Results are a file.");
    return 0;
  }
  FILE *logFile;
  FILE *dataFile;
  logFile = fopen(argv[1], "r");
  int timeH, timeM, timeS, volt, poten, water, pf = 0;
  //format is [timeH timeM timeS volt poten water pf]
  //          [timeH timeM timeS volt poten water pf]
  //          [timeH timeM timeS volt poten water pf]
  //          [timeH timeM timeS volt poten water pf]
  while(!feof (logFile)){
  fscanf(logFile, "%i %i %i %i %i %i %i \n", &timeH, &timeM, &timeS, &volt, &poten, &water, &pf); 
  printf("%i", timeH);
  }
  
  
  
  fclose(logFile);
}

