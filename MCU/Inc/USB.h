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
void USB_SendSample(uint16_t sample);

// Callback wywolywany przy odbieraniu danych
void USB_ReceiveCallback();

#endif /* USB_H_ */
