/*
 * ADC.c
 *
 *  Created on: 02.04.2019
 *      Author: Rafal
 */
#include "ADC.h"

// Tablica 2 elementowa przechowujaca dane odebrne z 2 kanalow
uint16_t Data[2];

// Uruchomienie konwersji przetwornika ADC z DMA
void ADC_start(){

	HAL_ADC_Start_DMA(&hadc1, Data, 2);
}
// Zwraca ostatnio pobrana probke z podanego kanalu
uint16_t ADC_GetSample(int nr_kanalu){

	if (nr_kanalu == 0 | nr_kanalu == 1)
		return Data[nr_kanalu];
}
