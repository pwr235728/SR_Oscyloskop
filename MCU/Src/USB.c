/*
 * USB.c
 *
 *  Created on: 02.04.2019
 *      Author: Kurat
 */

#include "USB.h"


// Zmienne u¿ywane przy wysy³aniu
uint8_t DataToSend[64];
uint32_t MessageLength = 0;


// Zmienne u¿ywane przy odbieraniu
// Przechowuja odebrane dane i ich d³ugoœc
uint8_t ReceivedData[64];
uint32_t ReceivedDataLength;


void USB_SendSample(uint16_t sample) {

	// Wys³anie próbki i separatora
	MessageLength = sprintf(DataToSend, "%d;", sample);
	CDC_Transmit_FS(DataToSend, MessageLength);
}

void USB_ReceiveCallback(){

	// Funkcja wywo³ywana po odebraniu danych

}
