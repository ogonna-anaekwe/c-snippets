#ifndef __decimal_to_binary_h__
#define __decimal_to_binary_h__

/**
 * Converts decimal to binary using bitwise operators.
 * Max decimal for reliable results: 9223372036854775807.
 * This is the max for a 64-bit signed int type.
 * @param decimal Number to be converted to binary.
 * @return char* - Binary representation of decimal number.
 */
char *decimal_to_binary(long decimal);

#endif //__decimal_to_binary_h__