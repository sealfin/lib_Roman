#ifndef lib_Roman_h

#define lib_Roman_h

#include "coding competition common.h"

typedef enum
{
  k_RomanNumeralsToUnsignedShortError_None = 0,
  k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_Is_NULL,
  k_RomanNumeralsToUnsignedShortError_p_unsignedShort_Is_NULL,
  k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_IsZeroCharactersInLength,
  k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_ContainsANonRomanNumeralCharacter,
  k_RomanNumeralsToUnsignedShortError_value_IsGreaterThan3999
}
t_RomanNumeralsToUnsignedShortError;

#ifdef __cplusplus
extern "C"
{
#endif

t_RomanNumeralsToUnsignedShortError f_RomanNumeralsToUnsignedShort( const char * const p_RomanNumerals, unsigned short * const p_unsignedShort );

#ifdef __cplusplus
}
#endif

typedef enum
{
  k_UnsignedShortToRomanNumeralsError_None = 0,
  k_UnsignedShortToRomanNumeralsError_p_IsLessThan1,
  k_UnsignedShortToRomanNumeralsError_p_IsGreaterThan3999
}
t_UnsignedShortToRomanNumeralsError;

typedef struct t_RomanNumeralsFromUnsignedShort_struct
{
  t_UnsignedShortToRomanNumeralsError m_error;
  char *m_RomanNumerals;
}
t_RomanNumeralsFromUnsignedShort;

#ifdef __cplusplus
extern "C"
{
#endif

t_RomanNumeralsFromUnsignedShort f_UnsignedShortToRomanNumerals( unsigned short p );

#ifdef __cplusplus
}
#endif

#endif
