/*
 * lib.c
 *
 * Created: 08/09/2012 10:19:47 PM
 *  Author: K. C. Lee
 * Copyright (c) 2016 by K. C. Lee
 
 	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.

	If not, see http://www.gnu.org/licenses/gpl-3.0.en.html
 */ 


#include "serial.h"

void NewLine(void)
{
  Putchar('\x0d');
  Putchar('\x0a');
 }

void Space(void)
{
  Putchar(' ');
 }

void FillSpc(char n)
{ 
	for(;n;n--)
     Space();
 }

char ToUpper(char ch)
{ 
  return(((ch<'a')||(ch>'z'))?ch:ch&0x5f);
 }

char IsWhiteSpc(char ch)
{ 
	return ((ch==' ')||(ch=='\t'));
 }

// Hex to int

uint8_t Hex(char ch)
{ 
	if ((ch>='0') && (ch<='9'))
    return(ch-'0');
  else 
  { ch &=0x5f;
    if ((ch>='A') &&(ch<='F'))
      return(ch-'A'+10);
   }
  return(0);
 }

void Puthex(uint8_t n)
{ 
	Putchar((n<10)?n+'0':n-10+'A');
 }

void Puthex2(uint8_t n)
{ Puthex(n>>4);
  Puthex(n & 0x0f);
 }

void Puthex4(uint16_t n)
{ 
	Puthex2(n>>8);
  Puthex2(n & 0xff);
 }

// Print string from program space
uint8_t Puts(char *s)
{ uint8_t i, ch;

  for(i=0;(ch=*s++);i++)
  {  
   if(ch=='\n')
     NewLine();
   else 
     Putchar(ch);
   }
   return(i);
 }
