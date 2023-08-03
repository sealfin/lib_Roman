This C library for converting Roman numeral strings to integers, and vice versa, was developed for [my solution](http://AModernPrometheus.WordPress.com/2023/02/27/329-roman-arithmetic/) to the "[Roman Arithmetic](http://www.CodeAbbey.com/index/task_view/roman-arithmetic)" (#329) problem posed by [CodeAbbey](http://www.CodeAbbey.com/).

(This library is based, to a limited degree, on [the Pascal library of (almost) the same name](http://GitHub.com/sealfin/Pascal/blob/master/lib_seal_Roman.pas) I developed (at the time of writing) ten years ago (or thereabouts) - but only "_to a limited degree_", as I had difficulty understanding how that earlier library functioned when I tried to re-read its source code when developing this library...)

This library is known to function correctly using:

1. Mac OS 9.2.2 (International English):
	1. Leonardo IDE 3.4.1;
	2. Metrowerks CodeWarrior IDE 2.1 (Discover Programming Edition);
2. Mac OS X 10.4.11:
	- gcc 4.0.1.

Using this library is straightforward; the following source code snippet demonstrates converting a Roman numeral string (`"MCMLXXXIII"`) into its equivalent integer (`1983`) and, provided that no error occurred, printing that integer to `stdout`:

	unsigned short us;
	if( f_RomanNumeralsToUnsignedShort( "MCMLXXXIII", &us ) == k_RomanNumeralsToUnsignedShortError_None )
	  printf( "%u\n", ( unsigned int )us );

And the following source code snippet demonstrates converting an integer (`1983`) into its equivalent Roman numeral string (`"MCMLXXXIII"`) and, provided that no error occurred, printing that Roman numeral string to `stdout`:

	t_RomanNumeralsFromUnsignedShort Rn = f_UnsignedShortToRomanNumerals( 1983 );
	if( Rn.m_error == k_UnsignedShortToRomanNumeralsError_None )
	{
	  printf( "%s\n", Rn.m_RomanNumerals );
	  free( Rn.m_RomanNumerals );
	}

Note that although converting an integer into its equivalent Roman numeral string will always result in a number in "standard form" -

> "The numerals for 4 (IV) and 9 (IX) are written using "subtraction notation",<sup>[5]</sup> where the first symbol (I) is _subtracted_ from the larger one (V, or X), thus avoiding the clumsier IIII and VIIII.<sup>[k]</sup>
> Subtraction notation is also used for 40 (XL), 90 (XC), 400 (CD) and 900 (CM).<sup>[6]</sup>
> These are the only subtractive forms in standard use."[^1]

[^1]: Roman numerals
	Retrieved on the 6<sup>th</sup> of February, 2023, from
	Wikipedia
	<`[http://en.Wikipedia.org/wiki/Roman_numerals](http://en.Wikipedia.org/wiki/Roman_numerals)`>

\- an oversight - that I may or may not correct in a future version of this library - means that a Roman numeral string need not be in "standard form" to be converted into its equivalent integer; eg., a number in "standard form" should contain a maximum of one instance of the character `'D'`, but this library will convert the Roman numeral string `"DDCMLXXXIII"` into its equivalent integer `1983` without error.
