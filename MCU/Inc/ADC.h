/*
 * ADC.h
 *
 *  Created on: 02.04.2019
 *      Author: Michal
 */

#ifndef ADC_H_
#define ADC_H_

// Uruchomienie konwersji przetwornika ADC z DMA
void ADC_start();
// Zwraca ostatnio pobrana wartosc z kanalu 0 lub 1
uint16_t ADC_GetSample(int);


#endif /* ADC_H_ */
