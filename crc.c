#include "crc.h"

unsigned int cal_crc(char *ptr, char len) {
    unsigned char i;
    unsigned int crc=0;
    while(len--!=0) {
        for(i=0x80; i!=0; i/=2) {
            if((crc&0x8000)!=0) {crc*=2; crc^=0x1021;} /* 余式 CRC 乘以 2 再求 CRC */
            else crc*=2;
            if((*ptr&i)!=0) crc^=0x1021; /* 再加上本位的 CRC */
        }
        ptr++;
    }
    return crc;
}