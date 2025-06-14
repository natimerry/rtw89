//
// Created by natimerry on 14/6/25.
//

#include <linux/module.h>
#include <linux/usb.h>
#include "rtw8852a.h"
#include "usb.h"

static const struct rtw89_driver_info rtw89_8852au_info = {
  .chip = &rtw8852a_chip_info,
  .variant = NULL,
  .quirks = NULL,
};


#define USB_VENDOR_ID_REALTEK           0x0BDA
#define USB_VENDOR_ID_ASUS              0x0B05
#define USB_VENDOR_ID_BUFFALO           0x0411
#define USB_VENDOR_ID_DLINK             0x2001
#define USB_VENDOR_ID_TPLINK            0x2357
#define USB_VENDOR_ID_ELECOM            0x056e

static struct usb_device_id rtw_8852au_id_table[] = {
        /*=== Realtek demoboard ===*/
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_REALTEK, 0x8832, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_REALTEK, 0x885A, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_REALTEK, 0x885C, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        /*=== ASUS USB-AX56 =======*/
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_ASUS, 0x1997, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_ASUS, 0x1a62, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        /*=== BUFFALO WI-U3-1200AX2(/N) =======*/
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_BUFFALO, 0x0312, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        /*=== D-Link DWA-X1850 ====*/
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_DLINK, 0x0141, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_DLINK, 0x3321, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        /*=== TP-Link AX1800 ===*/
        {USB_DEVICE_AND_INTERFACE_INFO(0x35bc, 0x0100, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_TPLINK, 0x013f, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_TPLINK, 0x0140, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        /*=== TP-Link Archer TX20UH ===*/
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_TPLINK, 0x0141, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        /*=== ELECOMWDC-X1201DU3 ===*/
        {USB_DEVICE_AND_INTERFACE_INFO(USB_VENDOR_ID_ELECOM, 0x4020, 0xff, 0xff, 0xff), .driver_info = (kernel_ulong_t)&rtw89_8852au_info},

        {}
};

MODULE_DEVICE_TABLE(usb, rtw_8852au_id_table);

static struct usb_driver rtw_8852au_driver = {
  .name = KBUILD_MODNAME,
  .id_table = rtw_8852au_id_table,
  .probe = rtw89_usb_probe,
  .disconnect = rtw89_usb_disconnect,
};

module_usb_driver(rtw_8852au_driver);


MODULE_AUTHOR("Soham Nandy <soham.nandy2006@gmail.com>");
MODULE_DESCRIPTION("Realtek 802.11ax wireless 8852AU driver");
MODULE_LICENSE("Dual BSD/GPL");
