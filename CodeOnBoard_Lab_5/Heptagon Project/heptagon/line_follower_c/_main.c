/* --- Generated the 9/4/2025 at 0:21 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. feb. 12 16:7:4 CET 2025) --- */
/* --- Command line: /home/jayesh/.opam/4.03.0/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Line_follower__main_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int sen0;
  int sen1;
  int sen2;
  int sen3;
  int sen4;
  int ir_d_front;
  int leftforwardDetection;
  int leftbackwardDetection;
  int rightforwardDetection;
  int rightbackwardDetection;
  int beacon;
  int second;
  Line_follower__main_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Line_follower__main_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%d", &sen0)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen3)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen4)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_d_front)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &leftforwardDetection)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &leftbackwardDetection)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &rightforwardDetection)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &rightbackwardDetection)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &beacon)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &second)==EOF)) {
      return 0;
    };;
    Line_follower__main_step(sen0, sen1, sen2, sen3, sen4, ir_d_front,
                             leftforwardDetection, leftbackwardDetection,
                             rightforwardDetection, rightbackwardDetection,
                             beacon, second, &_res, &mem);
    printf("%d\n", _res.v_l);
    printf("%d\n", _res.v_r);
    printf("%d\n", _res.dir);
    printf("%d\n", _res.cnt);
    fflush(stdout);
  };
  return 0;
}

