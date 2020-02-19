struct page_directory_entry {
    uint32_t present        :1  ;//Page present in memory
    uint32_t rw             :1  ;//Read-only if clear, R/W is set
    uint32_t user           :1  ;//Superviser only if clear
    uint32_t writethru      :1  ;//Cache this directory as write-thru only
    uint32_t cachedisabled  :1  ;//Disable cache on this page table?
    uint32_t accessed       :1  ;//Superviser level only if clear
    uint32_t pagesize       :1  ;//Has the page been accessed since the last refresh?
    uint32_t ignored        :2  ;//Has the page been written to since the last refresh?
    uint32_t os_specific    :3  ;//Almalgation of unused and reserved bits
    uint32_t frame          :20 ;//Frame address (shifted right 12 bits)
};

struct page {
    uint32_t present        :1  ;//Page present in memory
    uint32_t rw             :1  ;//Read only if clear, read/write if set
    uint32_t user           :1  ;//Superviser level only if clear
    uint32_t accessed       :1  ;//Has the page been accessed since the last refresh?
    uint32_t dirty          :1  ;//Has the page been written to since the last refresh?
    uint32_t unused         :7  ;//Amalgamation of unused and reserved bits
    uint32_t frame          :20 ;//Frame address ()shifted right 12 bit)
};
