/*
 * USB.h
 *
 *  Created on: 02.04.2019
 *      Author: Kurat
 */

#ifndef USB_H_
#define USB_H_

#include "usb_device.h"

// Funkcja wysy³aj¹ca probki
void USB_SendSample(uint8_t sample);
void USB_SendSamples(uint8_t samples[], uint32_t length);
// Callback wywolywany przy odbieraniu danych
void USB_ReceiveCallback();

#endif /* USB_H_ */
