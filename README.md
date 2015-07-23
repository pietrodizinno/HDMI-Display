# HDMI-Display / HDMI to RGB Adapter
Universal HDMI/DVI Displays with Touch Panel based on TI TFP401 and Atmel ATmega32u4 (with Arduino Leonardo compatible Bootloader).

![HDMI-Display](https://raw.github.com/x893/HDMI-Display/master/pcb/HDMI-Display_v10-0603.jpg)
[![HDMI-Display](https://raw.github.com/watterott/HDMI-Display/master/pcb/HDMI-Display_v10.jpg)](http://www.watterott.com/en/HDMI-RGB-adapter-with-ATmega32U4-touch-controller)


## Shop
* [HDMI to RGB Adapter](http://www.watterott.com/en/HDMI-RGB-adapter-with-ATmega32U4-touch-controller)
* [40-Pin FFC-Extenter](http://www.watterott.com/en/40-Pin-FFC-extenter)
* [Bundle: HDMI Adapter + 5" 800x480 Display with Touchpanel](http://www.watterott.com/en/5-800x480-HDMI-Display-with-resistive-touch)
* [Bundle: HDMI Adapter + 7" 800x480 Display with Touchpanel](http://www.watterott.com/en/7-800x480-HDMI-Display-with-resistive-touch)
* Compatible TFT-Displays *(check jumper settings before connecting the screen)*:
  * [5" 800x480 Display with resitive Touchpanel](http://www.watterott.com/en/5-800x480-TFT-Display)
  * [7" 800x480 Display with resitive Touchpanel](http://www.watterott.com/en/7-800x480-TFT-Display)
  * [7" 800x480 Display with capacitive Touchpanel](http://www.watterott.com/en/7-inch-800x480-TFT-LCD-Display-with-capacitive-touch-panel)
  * [7" 1024x600 Display with capacitive Touchpanel](http://www.watterott.com/en/7-inch-1024x600-TFT-LCD-Display-with-capacitive-touch-panel) *(needs hardware modification on backlight circuit)*


## Features
* TI **TFP401A** HDMI to RGB Converter
* Pixel Rates up to 165MHz, 1080p and WUXGA (1920x1200) at 60Hz
* HDMI compatible (DVI, no Sound, no HDCP, no CEC)
* Atmel **ATmega32U4** Microcontroller to control Backlight and Touch Panel (USB HID Mouse)
* **EDID** EEPROM (24LC02B) for display settings
* LED Backlight Boost Regulator (up to 35V)
* 3.3V - 5V tolerant UART and I2C interface
* **Single 5V Power Supply** via MicroUSB connector


## Hardware and Software
* [Schematics/Layout + Guide](https://github.com/watterott/HDMI-Display/tree/master/pcb)
* [Firmware for ATmega32U4 Microcontroller](https://github.com/watterott/HDMI-Display/tree/master/src)
* [Displays Compatibility List](https://github.com/watterott/HDMI-Display/blob/master/docu/Displays.md)
* [FAQ (Frequently Asked Questions)](https://github.com/watterott/HDMI-Display/blob/master/docu/FAQ.md)
* [Enclosures (3D models)](https://www.thingiverse.com/search?q=watterott+display)
