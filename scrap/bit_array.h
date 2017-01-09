#ifndef __array_h__
#define __array_h__

/// \file bit_array.h
///
/// \author Magnus Gustafsson
/// \author Sebastian Nödtvedt
/// \version 1.0
/// \date 2016-12-16
/// \bug None known


#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

struct bit_array{
  int8_t *bit_array;
};


/// Creates the bit array
/// \param size of the array
/// \return the bit array
int8_t *new_bit_array(int bit_size);

/// Sets a desired bit to 1
/// \param pointer to the bit array and desired index
/// \return a edited version of the bit array
void bit_array_set_one(int8_t *bit_a, int index);


/// Sets a desired bit to 0
/// \param pointer to the bit array and the desired index
/// \return a edited version of the bit array
void bit_array_set_zero(int8_t *bit_a, int index);

/// Returns if the desired index is either 1 or 0
/// \param pointer to the bit array and the desired index
/// \return simply returns a 1 or 0 depending on the index
bool bit_array_get(int8_t *bit_a, int index);

#endif
