#ifndef TEXT_UTIL_H_
#define TEXT_UTIL_H_

namespace nwacc
{
	/*
	* Max size of the line the inputed string will be printed on
	*/
	const size_t max_size = 40;
	/*
	* Minimum size of the string to add spaces in order to pad lines.
	*/
	const size_t min_size = 20;
	/*
	* Punctuation marks searched for to pad string with spaces
	*/
	const std::string punct = ".,?;!";
	/*
	* Integer value added to the current positon to add spaces
	*/
	const int add_pos = 2;

	/*
	*\Brief Adds new line when string length reaches max length without breaking words.
	* Takes string and wraps the words at the designated width
	*\param source is file input and width is the max line length
	*\return the string after it is wraped.
	*/
	std::string word_wrap(std::string source, std::size_t width);

	/*
	*\Brief adds spaces to pad the wrapped lines.
	* Searches text for punctuation and adds spaces if the string is smaller than max width.
	*\param text is the file input to be formatted.
	*\return void.
	*/
	void pad_after_punct(std::string& text);

}
#endif