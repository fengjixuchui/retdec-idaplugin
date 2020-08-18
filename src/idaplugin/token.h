
#ifndef RETDEC_TOKEN_H
#define RETDEC_TOKEN_H

#include <string>

#include "utils.h"

/**
 * One element (lexical unit) in the decompiled source code.
 *
 * Closely related to:
 * https://github.com/avast/retdec/wiki/Decompiler-outputs#json-output-file-format
 */
struct Token
{
	enum class Kind
	{
		NEW_LINE = 0,
		WHITE_SPACE,
		PUNCTUATION,
		OPERATOR,
		ID_GVAR,
		ID_LVAR,
		ID_MEM,
		ID_LAB,
		ID_FNC,
		ID_ARG,
		KEYWORD,
		TYPE,
		PREPROCESSOR,
		INCLUDE,
		LITERAL_BOOL,
		LITERAL_INT,
		LITERAL_FP,
		LITERAL_STR,
		LITERAL_SYM,
		LITERAL_PTR,
		COMMENT,
	};

	Kind kind;
	ea_t ea;
	std::string value;

	Token();
	Token(Kind k, ea_t a, const std::string& v);

	const std::string& getKindString() const;
	const std::string& getColorTag() const;
};

std::vector<Token> parseTokens(const std::string& json, ea_t defaultEa);

#endif
