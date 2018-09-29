#pragma once
// textC3d is use to cripting whole signs from keyboard  at the expens of longer cript text.
#include "Cezar3d.h"

using namespace std;

// a:z (26) 0:9 (10) : ; < (3)     where:  : is alt  ; is shift  < is special
// 39
string textToC3D(string, const int);
string c3dToText(string text_in);


string textToC3D(string text_in, const int parametr = 10)
{
	string converted_text = "";
	char sign;

	for (int i = 0; i < text_in.length(); i++)
	{
		if (text_in[i] >= 0 && text_in[i] <= 9) { converted_text += ':'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 10 && text_in[i] <= 35) { converted_text += ':'; converted_text += static_cast<char>('a' + text_in[i]); }

		else if (text_in[i] >= 36 && text_in[i] <= 45) { converted_text += ';'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 46 && text_in[i] <= 47) { converted_text += ';'; converted_text += static_cast<char>('a' + text_in[i]); }
		else if ((text_in[i] >= 48 && text_in[i] <= 57) || (text_in[0] >= 97 && text_in[0] <= 122)) { converted_text += text_in[i]; }
		else if (text_in[i] >= 58 && text_in[i] <= 81) { converted_text += ';'; converted_text += static_cast<char>('c' + text_in[i]); }

		else if (text_in[i] >= 58 && text_in[i] <= 67) { converted_text += '<'; converted_text += ':'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 68 && text_in[i] <= 93) { converted_text += '<'; converted_text += ':'; converted_text += static_cast<char>('a' + text_in[i]); }

		else if (text_in[i] >= 94 && text_in[i] <= 96) { converted_text += '<'; converted_text += ';'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 123 && text_in[i] <= 129) { converted_text += '<'; converted_text += ';'; converted_text += static_cast<char>('3' + text_in[i]); }

		else if (text_in[i] >= 130 && text_in[i] <= 139) { converted_text += '<'; converted_text += '<'; converted_text += ':'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 140 && text_in[i] <= 165) { converted_text += '<'; converted_text += '<'; converted_text += ':'; converted_text += static_cast<char>('a' + text_in[i]); }

		else if (text_in[i] >= 166 && text_in[i] <= 175) { converted_text += '<'; converted_text += '<'; converted_text += ';'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 176 && text_in[i] <= 201) { converted_text += '<'; converted_text += '<'; converted_text += ';'; converted_text += static_cast<char>('a' + text_in[i]); }

		else if (text_in[i] >= 202 && text_in[i] <= 211) { converted_text += '<'; converted_text += '<'; converted_text += '<'; converted_text += ':'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 212 && text_in[i] <= 237) { converted_text += '<'; converted_text += '<'; converted_text += '<'; converted_text += ':'; converted_text += static_cast<char>('a' + text_in[i]); }

		else if (text_in[i] >= 238 && text_in[i] <= 247) { converted_text += '<'; converted_text += '<'; converted_text += '<'; converted_text += ';'; converted_text += static_cast<char>('0' + text_in[i]); }
		else if (text_in[i] >= 248 && text_in[i] <= 255) { converted_text += '<'; converted_text += '<'; converted_text += '<'; converted_text += ';'; converted_text += static_cast<char>('a' + text_in[i]); }

		else cout << "IMPOSIBLE\n";
	}
	converted_text = iCezar3D_Encrypt(converted_text, c3d::KEYTAB, parametr);

	return converted_text;
}

string c3dToText(string text_in, const int parametr = 10)
{
	string reconverted_text = "";

	iCezar3D_Decrypt(string const &msg_in, c3d::KEYTAB, parametr);

	return reconverted_text;
}

