# esp32-audio-routing-orbits-from-pulsar
This script routes four orbits from pulsar, renders them in super collider, reads decibel data and translates said data into a float value on an ESP32 DEV1.  These float values are then displayed as volume meters on an OLED display.

DEPENDANCIES-----------------------------------------------------------------------------------------------------------

This repository requires a preinstalled version of supercollider and tidal, as well as a functional pulsar environment. Ensure the com USB port used is set to 115200 Baud Rate in computer settings to avoid latency issues. 

HARDWARE---------------------------------------------------------------------------------------------------------------

Both an ESP32 DEV1 and OLED I2C IIC SSD1306 display are required to accurately dislay float values. 

ESP32:https://www.amazon.com/ELEGOO-ESP-WROOM-32-Development-Bluetooth-Microcontroller/dp/B0D8T53CQ5?pd_rd_w=wu98v&content-id=amzn1.sym.ee712ce2-a9c3-4a22-98cf-9cc28befa7f3&pf_rd_p=ee712ce2-a9c3-4a22-98cf-9cc28befa7f3&pf_rd_r=NQ1ZWA3SP5JWZCG3090N&pd_rd_wg=P3pku&pd_rd_r=852b8d03-15a0-42d3-a922-8df1b83a124a&pd_rd_i=B0D8T53CQ5&psc=1&ref_=pd_basp_d_rpt_ba_s_0_4_t

OLED Display: https://www.amazon.com/Hosyond-Display-Self-Luminous-Compatible-Raspberry/dp/B09T6SJBV5?pd_rd_w=XBZns&content-id=amzn1.sym.ee712ce2-a9c3-4a22-98cf-9cc28befa7f3&pf_rd_p=ee712ce2-a9c3-4a22-98cf-9cc28befa7f3&pf_rd_r=Q4615CBXZC0YNPDZJA93&pd_rd_wg=qk6wH&pd_rd_r=402ef8db-8549-4575-b9d5-0ce6f547d710&pd_rd_i=B09T6SJBV5&ref_=pd_basp_d_rpt_ba_s_0_3_cp_t&th=1

FUNCTIONALITY-------------------------------------------------------------------------------------------------------

Two scripts are required to run this program. The super collider client processes and sends volume data, and the INO script converts this data into visual level meters. This device is designed to render volume data coming out of four separate audio orbits for debugging or monitoring purposes. 
