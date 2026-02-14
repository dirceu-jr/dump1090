#include "rtl-sdr.h"
#include <stddef.h>
#include <string.h>

int rtlsdr_get_device_count(void) {
    return 0;
}

const char* rtlsdr_get_device_name(uint32_t index) {
    return "Mock RTL-SDR";
}

int rtlsdr_get_device_usb_strings(uint32_t index, char *vendor, char *product, char *serial) {
    if (vendor) strcpy(vendor, "MockVendor");
    if (product) strcpy(product, "MockProduct");
    if (serial) strcpy(serial, "123456");
    return 0;
}

int rtlsdr_open(rtlsdr_dev_t **dev, uint32_t index) {
    *dev = (rtlsdr_dev_t *)1; // Non-NULL value
    return 0;
}

int rtlsdr_close(rtlsdr_dev_t *dev) {
    return 0;
}

int rtlsdr_set_tuner_gain_mode(rtlsdr_dev_t *dev, int manual) {
    return 0;
}

int rtlsdr_get_tuner_gains(rtlsdr_dev_t *dev, int *gains) {
    if (gains) {
        gains[0] = 0;
    }
    return 1;
}

int rtlsdr_set_tuner_gain(rtlsdr_dev_t *dev, int gain) {
    return 0;
}

int rtlsdr_get_tuner_gain(rtlsdr_dev_t *dev) {
    return 0;
}

int rtlsdr_set_freq_correction(rtlsdr_dev_t *dev, int ppm) {
    return 0;
}

int rtlsdr_set_agc_mode(rtlsdr_dev_t *dev, int on) {
    return 0;
}

int rtlsdr_set_center_freq(rtlsdr_dev_t *dev, uint32_t freq) {
    return 0;
}

int rtlsdr_set_sample_rate(rtlsdr_dev_t *dev, uint32_t rate) {
    return 0;
}

int rtlsdr_reset_buffer(rtlsdr_dev_t *dev) {
    return 0;
}

int rtlsdr_read_async(rtlsdr_dev_t *dev, rtlsdr_read_async_cb_t cb, void *ctx, uint32_t buf_num, uint32_t buf_len) {
    return 0;
}
