#include <iostream>
#include <string>

#include "text_util.h"


namespace nwacc
{
	/*
	*\Brief Adds new line when string length reaches max length without breaking words.
	* Takes string and wraps the words at the designated width
	*\param source is file input and width is the max line length
	*\return the string after it is wraped.
	*/
	std::string word_wrap(std::string source, size_t width)
	{
		std::string whitespace = " ";
		std::size_t  curr_index = width - 1;
		std::size_t  size_to_elim;
		while (curr_index < source.length())
		{
			curr_index = source.find_last_of(whitespace, curr_index + 1);
			if (curr_index == std::string::npos)
			{
				source.insert(curr_index, "\n");
			}
			else {
				curr_index = source.find_last_not_of(whitespace, curr_index);
			}

			if (curr_index == std::string::npos)
			{
				source.insert(curr_index, "\n");
			}
			else {
				size_to_elim = source.find_first_not_of(whitespace, curr_index + 1) - curr_index - 1;
				source.replace(curr_index + 1, size_to_elim, "\n");
				curr_index += (width + 1); //due to the recently inserted "\n"
			}

		}
		return source;
	}
	
	/*
	*\Brief adds spaces to pad the wrapped lines.
	* Searches text for punctuation and adds spaces if the string is smaller than max width.
	*\param text is the file input to be formatted.
	*\return void.
	*/

	void pad_after_punct(std::string& text)
	{
		auto pos = -1;
		if (text.length() < max_size)
		{
			pos = text.find_first_of(punct);
			while (pos != std::string::npos)
			{
				text.insert(pos, " ");
				pos = text.find_first_of(punct, pos + add_pos);
			}
			if (text.length() < max_size && text.length() > min_size)
			{
				while (text.length() < max_size)
				{
					pos = text.find_first_of(' ');
					while (pos != std::string::npos && text.length() < max_size)
					{
						if (!(isspace(text[pos - 1])))
						{
							text.insert(pos, "  ");
							pos = text.find_first_of(' ', pos + add_pos);
						}
					}
				}
			}
		}
	}
}