/*
 * USB.c
 *
 *  Created on: 02.04.2019
 *      Author: Kurat
 */

#include "USB.h"


// Zmienne u�ywane przy wysy�aniu
uint8_t DataToSend[64];
uint32_t MessageLength = 0;


// Zmienne u�ywane przy odbieraniu
// Przechowuja odebrane dane i ich d�ugo�c
uint8_t ReceivedData[64];
uint32_t ReceivedDataLength;


void USB_SendSample(uint16_t sample) {

	// Wys�anie pr�bki i separatora
	MessageLength = sprintf(DataToSend, "%d;", sample);
	CDC_Transmit_FS(DataToSend, MessageLength);
}

void USB_ReceiveCallback(){

	// Funkcja wywo�ywana po odebraniu danych

}
