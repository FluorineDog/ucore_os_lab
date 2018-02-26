#ifndef __BOOT_ASM_H__
#define __BOOT_ASM_H__

/* Assembler macros to create x86 segments */

/* Normal segment */
#define SEG_NULLASM \
	.word 0, 0;       \
	.byte 0, 0, 0, 0

// dog: base => base + limit

// low 4 bytes
// dog: base15-0|limit15-0|
// dog: 31....16|15......0|

// high 4 bytes
// dog: G = granularity => always set => 4KB
// dog: D = default operand size => never set => 16-bits 
// dog: L = long-mode-segment => never set => 16-bits 
// dog: AVL => always set => available 
// dog: limit
// dog: P = 1 => segment present
// dog: DPL=10b=2 descriptor level
// dog: S = 0 => system descriptor(1 for code/data)
// type: combination of STA_*
// 
// dog: base31-24|G  D  L AVL|limit19-16|P DPL S| type |base 23...16|
//               |1  0  0  1 |          |1 10  0|      |            |
// dog: 31.....24|23.......20|19......16|15...13|11...8|7..........0|
#define SEG_ASM(type, base, lim)                  \
	.word(((lim) >> 12) & 0xffff), ((base)&0xffff); \
	.byte(((base) >> 16) & 0xff), (0x90 | (type)),  \
			(0xC0 | (((lim) >> 28) & 0xf)), (((base) >> 24) & 0xff)

/* Application segment type bits */
#define STA_X 0x8	// Executable segment
#define STA_E 0x4	// Expand down (non-executable segments)
#define STA_C 0x4	// Conforming code segment (executable only)
#define STA_W 0x2	// Writeable (non-executable segments)
#define STA_R 0x2	// Readable (executable segments)
#define STA_A 0x1	// Accessed

#endif /* !__BOOT_ASM_H__ */
