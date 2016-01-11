#ifndef CONFIG_H
#define CONFIG_H

//***** Select your Display and Touchpanel here ******
#define DISPLAY_TYPE            DISPLAY_480x272 // DISPLAY_480x272 DISPLAY_800x480 DISPLAY_800x480HY DISPLAY_1024x600HY
#define TOUCHPANEL_TYPE         TOUCHPANEL_NONE // TOUCHPANEL_NONE TOUCHPANEL_RESISTIVE TOUCHPANEL_FT5x06

/*
  Watterott electronic display configurations:
  5" with res. touch: DISPLAY_800x480 + TOUCHPANEL_RESISTIVE
  7" with res. touch: DISPLAY_800x480 + TOUCHPANEL_RESISTIVE
  7" with cap. touch: DISPLAY_800x480HY or DISPLAY_1024x600HY + TOUCHPANEL_FT5x06
*/

// General Settings
//#define DEBUG             1 // set debugg output level (0=nothing, 1=minimal...)
#define ORIENTATION       0 // orientation (0x1=invert x, 0x2=invert y, 0x4=swap axes, 0x8=map to screen coordinates)
#define SCREENSAVERTIME 180 // seconds timeout (0...65535, 0=always on)
#define BRIGHTNESS      255 // backlight brightness (0..255)
#define LOOPTIME         16 // 16 = 60 Hz polling interval
#define TOUCHMAX      4095L // maximal touch/mouse position

#define QUOTE(name)     #name
#define STR(macro)      QUOTE(macro)
#define VERSION_STRING  "1.10"
#define INFO_STRING     "HDMI-Display\nVersion: " VERSION_STRING " (" __DATE__ ")\nTFT: " STR(SCREEN_WIDTH) "x" STR(SCREEN_HEIGHT)"\nTouch: " STR(TOUCHPANEL_TYPE) "\nhttps://github.com/watterott/HDMI-Display"

// Display Types
#define DISPLAY_480x272          1 //  480 x  272 (TFT043-3)
#define DISPLAY_640x480          2 //  640 x  480
#define DISPLAY_720x480          3 //  720 x  480
#define DISPLAY_800x480          4 //  800 x  480 (TFT050-3, HY5-LCD-HD, TFT070-4, HY7-LCD)
#define DISPLAY_800x480_720x480  5 //  800 x  480 with 720x480 (480p) fallback (TFT050-3, HY5-LCD-HD, TFT070-4, HY7-LCD)
#define DISPLAY_800x480HY        6 //  800 x  480 (HY070CTP capacitive touchpanel)
#define DISPLAY_800x600          7 //  800 x  600
#define DISPLAY_1024x600         8 // 1024 x  600
#define DISPLAY_1024x600HY       9 // 1024 x  600 (HY070CTP-HD capacitive touchpanel)
#define DISPLAY_1024x768        10 // 1024 x  768
#define DISPLAY_1280x720        11 // 1280 x  720
#define DISPLAY_1280x768        12 // 1280 x  768
#define DISPLAY_1280x800        13 // 1280 x  800
#define DISPLAY_1280x1024       14 // 1280 x 1024

// Touchpanel Types
#define TOUCHPANEL_NONE         1 // No Touchpanel present
#define TOUCHPANEL_RESISTIVE    2 // Resitive
#define TOUCHPANEL_FT5x06       3 // Capacitive FT5x06 (HY070CTP)

// check configurations
#if TOUCHPANEL_TYPE == TOUCHPANEL_NONE
#  undef SCREENSAVERTIME
#  define SCREENSAVERTIME 0
#  define TPC_X0 0    // not needed - touchpanel calibration x0
#  define TPC_X1 0    // not needed - touchpanel calibration x1
#  define TPC_Y0 0    // not needed - touchpanel calibration y0
#  define TPC_Y1 0    // not needed - touchpanel calibration y1
#elif TOUCHPANEL_TYPE == TOUCHPANEL_RESISTIVE
#  define TPC_X0 80   // touchpanel calibration x0
#  define TPC_X1 930  // touchpanel calibration x1
#  define TPC_Y0 825  // touchpanel calibration y0
#  define TPC_Y1 160  // touchpanel calibration y1
#elif TOUCHPANEL_TYPE == TOUCHPANEL_FT5x06
#  define TPC_X0 0    // not needed - touchpanel calibration x0
#  define TPC_X1 0    // not needed - touchpanel calibration x1
#  define TPC_Y0 0    // not needed - touchpanel calibration y0
#  define TPC_Y1 0    // not needed - touchpanel calibration y1
#else
#  error "Please select a TOUCHPANEL_TYPE"
#endif

#if DISPLAY_TYPE == DISPLAY_480x272
#  define SCREEN_WIDTH   480
#  define SCREEN_HEIGHT  272
#elif DISPLAY_TYPE == DISPLAY_640x480
#  define SCREEN_WIDTH   640
#  define SCREEN_HEIGHT  480
#elif DISPLAY_TYPE == DISPLAY_720x480
#  define SCREEN_WIDTH   720
#  define SCREEN_HEIGHT  480
#elif DISPLAY_TYPE == DISPLAY_800x480 || \
      DISPLAY_TYPE == DISPLAY_800x480_720x480 || \
      DISPLAY_TYPE == DISPLAY_800x480HY
#  define SCREEN_WIDTH   800
#  define SCREEN_HEIGHT  480
#elif DISPLAY_TYPE == DISPLAY_800x600
#  define SCREEN_WIDTH   800
#  define SCREEN_HEIGHT  600
#elif DISPLAY_TYPE == DISPLAY_1024x600 || \
      DISPLAY_TYPE == DISPLAY_1024x600HY
#  define SCREEN_WIDTH   1024
#  define SCREEN_HEIGHT  600
#elif DISPLAY_TYPE == DISPLAY_1024x768
#  define SCREEN_WIDTH   1024
#  define SCREEN_HEIGHT  768
#elif DISPLAY_TYPE == DISPLAY_1280x720
#  define SCREEN_WIDTH   1280
#  define SCREEN_HEIGHT  720
#elif DISPLAY_TYPE == DISPLAY_1280x768
#  define SCREEN_WIDTH   1280
#  define SCREEN_HEIGHT  768
#elif DISPLAY_TYPE == DISPLAY_1280x800
#  define SCREEN_WIDTH   1280
#  define SCREEN_HEIGHT  800
#elif DISPLAY_TYPE == DISPLAY_1280x1024
#  define SCREEN_WIDTH   1280
#  define SCREEN_HEIGHT  1024
#else
#  error "Please select a DISPLAY_TYPE"
#endif

#ifndef SWAP
#define SWAP(x,y) do{ (x)=(x)^(y); (y)=(x)^(y); (x)=(x)^(y); }while(0)
#endif

// IO ports
#define LED_1           5 // first LED PC6
#define LED_2          13 // second LED PC7
#define BACKLIGHT       9 // backlight control PB5
#define SW_1       (1<<5) // switch PD5
#define INT             4 // touch interrupt PD4
#define SW_1_SETUP() PORTD |= SW_1; DDRD &= ~SW_1 // set input
#define SW_1_PRESSED() (!(PIND & SW_1)) // switch pressed?

// Touchpanel analog inputs 
#define AXM            A1 // touch X- PF6
#define AXP            A3 // touch X+ PF4
#define AYM            A2 // touch Y- PF5
#define AYP            A0 // touch Y+ PF7

// External EDID EEPROM
#define EEPROMSIZE 128  // size in bytes
#define EEPROMADDR 0x50 // I2C address

#endif //CONFIG_H
