SECTIONS
{
    . = 0x0000; /* 開始アドレス：必要に応じて変更 */
    
    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss COMMON)
    }
}
