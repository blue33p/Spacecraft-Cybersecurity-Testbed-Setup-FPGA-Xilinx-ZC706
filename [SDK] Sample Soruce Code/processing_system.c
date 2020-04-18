#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

#include <unistd.h>
#include <xil_cache.h>
#define PS_DDR (*(volatile u32 *)(0x10000000)) // 0x00100000 ~ 0x3fffffff
#define BRAM (*(volatile u32 *)(0x40000000)) // 0x40000000 ~ 0x40001fff
int main()
{
	int i = 0;
    init_platform();
    PS_DDR = 0;
    BRAM = 0;
    print("[PS] Initialized\n\r");
    while(i++ < 10){
        PS_DDR++;
    	Xil_DCacheFlush();
        xil_printf("[PS] PS_DDR = %i\n\r", PS_DDR);
        xil_printf("[PS] BRAM = %i\n\r", BRAM);
        sleep(1);
    }
    cleanup_platform();
    return 0;
}
