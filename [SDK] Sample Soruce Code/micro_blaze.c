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
    BRAM = 0;
    print("[MB] Initialized\n\r");

    while(i++ < 10){
        BRAM ++;
        Xil_DCacheInvalidate();
        xil_printf("[MB] PS_DDR = %i\n\r", PS_DDR);
        xil_printf("[MB] BRAM = %i\n\r", BRAM);
        sleep(1);
    }

    cleanup_platform();
    return 0;
}
