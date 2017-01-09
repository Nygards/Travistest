#ifndef __code_convension_h__
#define __code_convension_h__


/// \file code_convention.h
///
/// \author Magnus Gustafsson
/// \author Sebastian Nödtvedt
/// \version 1.0
/// \date 2016-12-14
/// \bug None known


/// get string with hello + name
/// \param name of person
/// \returns greating String with name
char *hello_name(char *name);


/// Explenation of what function does
/// \param a is ...
/// \param b is ...
/// \returns true if a is greater then b else false
/// \see hello_name, other_file.h
bool bigger_then(int a, int b);

/// Explenation of what function does
/// \returns true if a is greater then b else false
void *get_pointer();

#endif
