#include "lib_Roman.h"

static unsigned short f_RomanNumeralToValue( const char p )
{
  size_t i = 0;
  const char * const Roman_numeral = "IVXLCDM";
  const unsigned short value[ 7 ] = { 1, 5, 10, 50, 100, 500, 1000 };

  for( ; i < 7; i ++ )
    if( p == Roman_numeral[ i ] )
      return value[ i ];
  return 0;
}

typedef struct t_SubtractiveNotationError_struct
{
  bool m_errorOccurred;
  char m_character;
}
t_SubtractiveNotationError;

static t_SubtractiveNotationError f_SubtractiveNotation( const char * const p_string, const size_t p_characterIndex, unsigned short * const p_value )
{
  t_SubtractiveNotationError error;

  *p_value = 0;
  error.m_errorOccurred = false;
  if( p_characterIndex + 1 >= strlen( p_string ))
    return error;

  {
    const char left_character = p_string[ p_characterIndex ];
    const unsigned short left_value = f_RomanNumeralToValue( left_character );

    if( left_value == 0 )
    {
      error.m_errorOccurred = true;
      error.m_character = left_character;
      return error;
    }

    {
      const char right_character = p_string[ p_characterIndex + 1 ];
      const unsigned short right_value = f_RomanNumeralToValue( right_character );

      if( right_value == 0 )
      {
        error.m_errorOccurred = true;
        error.m_character = right_character;
        return error;
      }

      {
        size_t i = 0;
        const char *right_Roman_numeral = "VXLCDM", *left_Roman_numeral = "IIXXCC";

        for( ; i < 6; i ++ )
          if(( right_character == right_Roman_numeral[ i ] ) && ( left_character == left_Roman_numeral[ i ] ))
          {
            *p_value = right_value - left_value;
            return error;
          }
      }
    }
  }

  return error;
}

t_RomanNumeralsToUnsignedShortError f_RomanNumeralsToUnsignedShort( const char * const p_RomanNumerals, unsigned short * const p_unsignedShort )
{
  if( p_RomanNumerals == NULL )
    return k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_Is_NULL;

  if( p_unsignedShort == NULL )
    return k_RomanNumeralsToUnsignedShortError_p_unsignedShort_Is_NULL;

  {
    const size_t Roman_numerals_length = strlen( p_RomanNumerals );

    if( Roman_numerals_length == 0 )
      return k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_IsZeroCharactersInLength;

    {
      size_t i = 0;
      unsigned short value = 0;

      while( i < Roman_numerals_length )
      {
        t_SubtractiveNotationError error;
        unsigned short addition;

        error = f_SubtractiveNotation( p_RomanNumerals, i, &addition );
        if( error.m_errorOccurred )
          return k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_ContainsANonRomanNumeralCharacter;

        if( addition != 0 )
          i ++;
        else
        {
          addition = f_RomanNumeralToValue( p_RomanNumerals[ i ] );
          if( addition == 0 )
            return k_RomanNumeralsToUnsignedShortError_p_RomanNumerals_ContainsANonRomanNumeralCharacter;
        }
        value += addition;
        if( value > 3999 )
          return k_RomanNumeralsToUnsignedShortError_value_IsGreaterThan3999;

        i++;
      }

      *p_unsignedShort = value;
      return k_RomanNumeralsToUnsignedShortError_None;
    }
  }
}
