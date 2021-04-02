/* Copyright (c) 2021 Elisee Bangya.
 *
 * This program is the proprietary software of Elisee Bangya and/or its 
 * licensors, and may only be used, duplicated, modified or distributed 
 * pursuant to the terms and conditions of a separate, written license 
 * agreement executed between you and Elisee Bangya (an "Authorized 
 * License"). Except as set forth in an Authorized License, Elisee Bangya 
 * grants no license (express or implied), right to use, or waiver of any 
 * kind with respect to the Software, and Elisee Bangya expressly reserves 
 * all rights in and to the Software and all intellectual property rights 
 * therein. If you have no authorized license, then you have no right to use 
 * this software in any way, and should immediately notify Elisee Bangya 
 * and discontinuate all use of the software.
 */

/**
 * @addtogroup Main
 * @{
 **/

/**
 * @file main.c
 * @brief Power of two algorithm
 *
 * @date 02/04/2021
 *
 **/

/******************************************************************************
 * Included files
 ******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <stdio.h>  // NOLINT
#include <stdint.h>  // NOLINT

using namespace std;  // NOLINT


/******************************************************************************
 * Main
 ******************************************************************************/


/** 
 * @brief Parse user input
 * @param[in] dataIn input from user
 * @param[out] dataOut parsed data form user input
 * @return bool true if usefull data is detected 
 */
bool parseInput(char *dataIn, uint64_t *dataOut) {

  *dataOut=0;
  bool ret = false;

  while (*dataIn!='\0')
  {
    if ((*dataIn >= '0') && (*dataIn <= '9')){
      ret = true;
      *dataOut = (*dataOut)*10 + (*dataIn - 0x30);
    }
    dataIn++;
  }
  std::cout << "   valeur parsée : " << *dataOut << endl;
  return ret; 
}


/**
 * @brief Main of the programm
 */
int main(int argc, char** argv) {
  int  nOne=0; 
  uint64_t number  = (uint64_t) malloc(sizeof(uint64_t));
  char *input = (char *) malloc(4*sizeof(char));

  while (1) {
    do {
      std::cout << endl << "-> Saisissez un nombre : ";
      std::cin >> input;
      std::cout << "   valeur saisie : " << input << endl;
    } while(!parseInput(input, &number));

    nOne=0; 
    
    /** Une puissance de 2 est caractérisée 
     * par le fait qu'un seul des bits le 
     * constituant est à 1. On considère 64bits
     */
    if (number > 1)
      for (int i=0; i<64; i++)
        nOne += (number >> i) &0x01;

    std::cout << "   " << number << ((nOne == 1) ? " est": " n'est pas") << " multiple de 2" ;
  }

  free(&number);
  free(input);

  return 0;
}