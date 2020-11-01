/*** 
 * @Author: Xu.WANG
 * @Date: 2020-10-19 00:02:51
 * @LastEditTime: 2020-10-19 00:38:25
 * @LastEditors: Xu.WANG
 * @Description: 
 * @FilePath: \CodeRepo\include\macro.h
 */
#pragma once
#define BIT_SET(byte, nbit) ((byte) |= (1 << (nbit)))
#define BIT_CLEAR(byte, nbit) ((byte) &= ~(1 << (nbit)))
#define BIT_FLIP(byte, nbit) ((byte) ^= (1 << (nbit)))
#define BIT_CHECK(byte, nbit) ((byte) & (1 << (nbit)))

#define BIT_LS(val, nbit) (val << nbit)
#define BIT_RS(val, nbit) (val >> nbit)