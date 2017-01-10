/**
 * bmp.h
 *
 * Computer Science 50
 * Problem Set 4
 *
 * BMP-related data types based on Microsoft's own.
 */

#include <stdint.h>

/**
 * Common Data Types 
 *
 * The data types in this section are essentially aliases for C/C++ 
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */
typedef struct 
{ 
    WORD   bfType;      // 2 Bytes
    DWORD  bfSize;      // 4 Bytes
    WORD   bfReserved1; // 2 Bytes
    WORD   bfReserved2; // 2 Bytes
    DWORD  bfOffBits;   // 4 Bytes
} __attribute__((__packed__)) 
BITMAPFILEHEADER;       // 14 Bytes => 14 Bytes * 8bits = 112 Bits

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the 
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */
typedef struct
{
    DWORD  biSize;              // 4
    LONG   biWidth;             // 4
    LONG   biHeight;            // 4
    WORD   biPlanes;            // 2
    WORD   biBitCount;          // 2
    DWORD  biCompression;       // 4
    DWORD  biSizeImage;         // 4
    LONG   biXPelsPerMeter;     // 4
    LONG   biYPelsPerMeter;     // 4
    DWORD  biClrUsed;           // 4
    DWORD  biClrImportant;      // 4
} __attribute__((__packed__))
BITMAPINFOHEADER;               // 36 +4 = 40 Bytes * 8 = 320 Bits
                                // 112 Bits + 320 Bits = 432 Bits / 8 = 54 Bytes 
                                // ab 0x36 ist die Dateiinhalt


/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */
typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
