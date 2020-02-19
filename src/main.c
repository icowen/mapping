#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "structure.h"
   
struct page_directory_entry page_directory[1024] __attribute__((aligned(4096)));
struct page_directory_entry page_table[1024] __attribute__((aligned(4096)));

int main() {
    for(int i = 0; i < sizeof(page_directory)/4; i++) {
        page_directory[i].present = 0;
        page_directory[i].rw = 0;
        page_directory[i].user = 0;
        page_directory[i].writethru = 0;
        page_directory[i].cachedisabled = 0;
        page_directory[i].accessed = 0;
        page_directory[i].pagesize = 0;
        page_directory[i].ignored = 0;
        page_directory[i].os_specific = 0;
        page_directory[i].frame = 0;
    }
    //memset(page_directory, 0, 4096);
    page_directory[0].present = 1;
    page_directory[0].rw = 1;
    page_directory[0].frame = (int)page_table >> 12;
    for(int i = 1; i < sizeof(page_table)/4; i++) {
        page_table[i].frame = i;
        page_table[i].present = 1;
        page_table[i].rw = 1;
    }

    asm("mov %0,%%cr3"
        :
        :"r"(page_directory)
        :); 

    asm("mov %cr0, %eax\n"
        "or $0x80000001,%eax\n"
        "mov %eax,%cr0");

    return 0;
}

