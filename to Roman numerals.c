#include "lib_Roman.h"
#include "seal_stringConcatenation_C.h"

static char *f_DigitToRomanNumerals( unsigned short p_digit, const char p_character, const char p_character_multipleOf5, const char p_character_multipleOf10 )
{
  char string[ 5 ];
  size_t length_of_string = 0;
  char *string_to_return;

  if(( p_digit == 9 ) || ( p_digit == 4 ))
  {
    string[ 0 ] = p_character;
    string[ 1 ] = ( p_digit == 9 )?p_character_multipleOf10:p_character_multipleOf5;
    length_of_string = 2;
  }
  else
  {
    if( p_digit >= 5 )
    {
      string[ 0 ] = p_character_multipleOf5;
      length_of_string = 1;
      p_digit -= 5;
    }
    while( p_digit > 0 )
    {
      string[ length_of_string ++ ] = p_character;
      p_digit --;
    }
  }
  string[ length_of_string ] = '\0';
  string_to_return = ( char* )M_malloc_WithErrorChecking( sizeof( char ) * ( length_of_string + 1 ), "string_to_return" );
  strcpy( string_to_return, string );
  return string_to_return;
}

static char *f_ValueToRomanNumerals( unsigned short * const p_value, const unsigned short p_divisor, const char * const p_characters, const char * const p_string )
{
  char *string_to_return, *string = f_DigitToRomanNumerals( *p_value / p_divisor, p_characters[ 0 ], p_characters[ 1 ], p_characters[ 2 ] );

  if( p_string == NULL )
    string_to_return = string;
  else
  {
    string_to_return = f_seal_ConcatenateStrings_C(( char* )p_string, string, NULL );
    free( string );
  }
  *p_value %= p_divisor;
  return string_to_return;
}

t_RomanNumeralsFromUnsignedShort f_UnsignedShortToRomanNumerals( unsigned short p )
{
  t_RomanNumeralsFromUnsignedShort to_return;
  unsigned short value;
  char *string = NULL, *new_string;

  to_return.m_error = k_UnsignedShortToRomanNumeralsError_None;
  to_return.m_RomanNumerals = NULL;

  if( p < 1 )
  {
    to_return.m_error = k_UnsignedShortToRomanNumeralsError_p_IsLessThan1;
    return to_return;
  }

  if( p > 3999 )
  {
    to_return.m_error = k_UnsignedShortToRomanNumeralsError_p_IsGreaterThan3999;
    return to_return;
  }

  value = p / 1000;
  if( value > 0 )
  {
    size_t length_of_string = 0;

    string = ( char* )M_malloc_WithErrorChecking( sizeof( char ) * ( value + 1 ), "string" );
    while( value > 0 )
    {
      string[ length_of_string ++ ] = 'M';
      value --;
    }
    string[ length_of_string ] = '\0';
  }
  p %= 1000;

  new_string = f_ValueToRomanNumerals( &p, 100, "CDM", string );
  if( string != NULL )
    free( string );
  string = new_string;

  new_string = f_ValueToRomanNumerals( &p, 10, "XLC", string );
  free( string );
  string = new_string;

  new_string = f_DigitToRomanNumerals( p, 'I', 'V', 'X' );
  if( strlen( new_string ) > 0 )
  {
    char *concatenated_string = f_seal_ConcatenateStrings_C( string, new_string, NULL );

    free( string );
    string = concatenated_string;
  }
  free( new_string );

  to_return.m_RomanNumerals = string;
  return to_return;
}
