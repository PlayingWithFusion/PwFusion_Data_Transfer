/***************************************************************************
* File Name: PwFusion_Data_Transfer.cpp
* Processor/Platform: PwFusion R3aktor M0 (tested)
* Development Environment: Arduino 2.1.1
*
* Designed to simplify I2C communication between a microcontroller and 
* a PwFusion I2C interface board
*
* Copyright � 2023 Playing With Fusion, Inc.
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
* Author		    Date		    Comments
* N. Johnson    2023Sep12   Original version
*
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source
* development by buying products from Playing With Fusion!
***************************************************************************/

#include "PwFusion_Data_Transfer.h"
#include <Arduino.h>
#include <Wire.h>

DataTransfer::DataTransfer() {}

void DataTransfer::begin(uint8_t adr, int numData) {
  _adr = adr;
  _numData = numData;
  Wire.begin();
}

int DataTransfer::getNumData() {
  return _numData;
}

uint8_t DataTransfer::getAdr() {
  return _adr;
}

// Read one byte of data from the specified i2c register
int DataTransfer::getData(uint8_t regAdr) {
  Wire.beginTransmission(_adr);
  Wire.write(regAdr);
  Wire.endTransmission();

  Wire.requestFrom(_adr, 1);
  while (Wire.available()) {
    return Wire.read();
  }
}