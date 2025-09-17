# ARM7-LPC2138-LPC2148-SPI-Serial-Peripheral-Interface

## Overview

SPI (Serial Peripheral Interface) is a synchronous serial communication protocol used for short-distance communication between microcontrollers and peripherals like ADC, DAC, EEPROM, or sensors.
SPI has 4 main signals:
SCK → Serial Clock
MOSI → Master Out, Slave In
MISO → Master In, Slave Out
SSEL / CS → Slave Select
LPC2148 can operate SPI in Master mode or Slave mode.

Registers for SPI
Register	Purpose
S0SPCR	SPI Control Register (Enable, Master/Slave, CPOL/CPHA, data order)
S0SPSR	SPI Status Register (SPIF, WCOL)
S0SPDR	SPI Data Register (write to transmit / read received data)
PINSEL0/PINSEL1	Configure pins for SPI0 or SPI1
