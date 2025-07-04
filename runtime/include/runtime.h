// *******************************************************************************************
// *******************************************************************************************
//
//      Name :      runtime.h
//      Purpose :   Runtime header
//      Date :      4th July 2025
//      Author :    Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************
// *******************************************************************************************

#pragma once

#include "common_module.h"
#include "dvi_module.h"

#include <SDL.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <errno.h>

#define AS_SCALE 	(2)

void TESTApplication(void);

void SYSOpen(bool muteSound);
int SYSPollUpdate(void);
void SYSClose(void);
void SYSRectangle(SDL_Rect *rc,int colour);
SDL_Surface *SYSGetSurface(void);

void RNDRender(SDL_Surface *surface);
void KBDProcessEvent(int scanCode,int modifiers,bool isDown);

void CTLFindControllers(void);

void SOUNDOpen(void);
void SOUNDClose(void);
void SOUNDPlay(void);
void SOUNDStop(void);
