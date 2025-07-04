// *******************************************************************************************
// *******************************************************************************************
//
//      Name :      mouse.c
//      Purpose :   Handle USB Mouse Reports
//      Date :      3rd July 2025
//      Author :    Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************
// *******************************************************************************************

#define LOCALS
#include "input_module.h"

#define INP_MOUSE_XMAX      (1280)
#define INP_MOUSE_YMAX      (960)

static int16_t xMouse = INP_MOUSE_XMAX / 2;
static int16_t yMouse = INP_MOUSE_YMAX / 2;
static int16_t buttons = 0;

/**
 * @brief      Handle mouse reports
 *
 * @param      r     USB Mouse report.
 */
void INPProcessMouseReport(USBREPORT *r) {

    int16_t dx = (r->data[1] << 8) | (r->data[0]);
    int16_t dy = (r->data[3] << 8) | (r->data[2]);

    int16_t x = xMouse+dx;
    int16_t y = yMouse+dy;
    if (x < 0) x = 0;
    if (x >= INP_MOUSE_XMAX) x = INP_MOUSE_XMAX-1;
    if (y < 0) y = 0;
    if (y >= INP_MOUSE_YMAX) y = INP_MOUSE_YMAX-1;

    xMouse = x;
    yMouse = y;

    buttons = 0;
    if (r->data[6]) buttons |= 0x01;
    if (r->data[7]) buttons |= 0x02;
    if (r->data[8]) buttons |= 0x04;
}

/**
 * @brief      Get the current mouse status. All of these pointers may be NULL
 *
 * @param      px        store x pos here
 * @param      py        store y pos here
 * @param      pButtons  store buttons here
 */
void INPGetMouseStatus(int16_t *px,int16_t *py,int16_t *pButtons) {
    if (px != NULL) *px = xMouse;
    if (py != NULL) *py = yMouse;    
    if (pButtons != NULL) *pButtons = buttons;
}