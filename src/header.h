#include <stdint.h>
#include <stdbool.h>
#include "gc.h"

/// The data type holding information of memory segment
typedef struct head header;


/// returns the size of the header
/// \returns sizeof(struct head)
size_t header_struct_size();

/// Checks if header holds a format string
/// \param head the header
/// \returns true if header holds format string else false
bool header_is_format_string(header* head);

/// Sets the header to hold the given format string
/// \param heap the heap
/// \param head the header
/// \param format_string the null-terminated formatstring containing only the characters '*', 'i', 'f', 'c', 'l' or 'd'
void header_set_format_string(heap_t* heap, header* head, char* format_string);

/// get the headers format string
/// \param head the header
/// \returns the formatstring that the header holds
char* header_get_format_string(header* head);

/// Checks if header holds a forwarding adress
/// \param head the header
/// \returns true if header holds forwarding adress else false
bool header_is_forward(header* head);


/// Sets the header to hold the given forwarding adress
/// \param heap the heap
/// \param forward_adress a pointer to the copied struct
void header_set_forward(header* head, void* forward_adress);

/// get the headers forwarding adress
/// \param head the header
/// \returns the pointer to the copied struct
void* header_get_forward(header* head);

/// Checks if header describes a data struct without pointers
/// \param head the header
/// \returns true if header describes a data struct
bool header_is_data(header* head);

/// Sets the header to hold the byte size of a struct
/// \param heap the heap
/// \param the byte size of the data structure
void header_set_data(header* head, size_t size);

/// get the byte size of the allocated structure
/// \param head the header
/// \returns the byte size of the allocated structure, or return -1 if not valid header
size_t header_get_allocated_size(header* head);

