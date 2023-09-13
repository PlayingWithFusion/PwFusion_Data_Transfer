/***************************************************************************
* File Name: PwFusion_Data_Transfer_Joystick_Example
* Processor/Platform: R3aktor (tested)
* Development Environment: Arduino 2.2.1
*
* Designed for use with with Playing With Fusion I2C Joystick
* interface board: IFB-40002
*
* Copyright © 2015-18 Playing With Fusion, Inc.
* SOFTWARE LICENSE AGREEMENT: This code is released under the MIT License.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
* **************************************************************************
* REVISION HISTORY:
* Author		  Date	    Comments
* N. Johnson  2023Sep12 Original Version
*
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source
* development by buying products from Playing With Fusion!
* **************************************************************************
* ADDITIONAL NOTES:
* This file contains functions to initialize and run a Playing With Fusion R3aktor in
* order to communicate with the I2C Joystick board. Funcionality is as described below:
*	- Configure R3aktor to receive information from the I2C Joystick board using the
*   PwFusion_Data_Transfer library
*	- Broadcast results to COM port
*  Circuit: (see Schematic.png)
*    R3aktor     -->  I2C Joystick
*    Qwiic pins  -->  Qwiic pins
***************************************************************************/
#include <PwFusion_Data_Transfer.h>

// Define the I2C address for the joystick
uint8_t ADR = 0x04;

// Initialize a new transfer object
DataTransfer transfer;

// Define the register positions of the data
uint8_t reg_VRX = 0x00;
uint8_t reg_VRY = 0x01;
uint8_t reg_SW = 0x02;

// Define the number of data points
int numData = 3;

void setup() {
  // Begin the transfer object on the specified address
  transfer.begin(ADR, numData);
  Serial.begin(9600);
}

void loop() {

  // Print out the data stored on each register of the Joystick
  Serial.print("VRX: ");
  Serial.print(transfer.getData(reg_VRX));
  Serial.print("   ");
  Serial.print("VRY: ");
  Serial.print(transfer.getData(reg_VRY));
  Serial.print("   ");
  Serial.print("SW: ");
  Serial.print(transfer.getData(reg_SW));
  Serial.println();
}
