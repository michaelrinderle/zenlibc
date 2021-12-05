#ifndef ZL_TYPE_STRING_H
#define ZL_TYPE_STRING_H
#ifdef __cplusplus
extern "C" {
#endif

#include "zenlibc.h"

	typedef struct zl_string_t {
		size_t size;
		size_t length;
		char buffer[];
	}  zl_string_t, zl_string;

	extern API  zl_string_t*	ZLCALL	zl_string_init(char* str);
	extern API  bool			ZLCALL	zl_string_free(zl_string_t* str);
	extern API  bool			ZLCALL	zl_string_cat(zl_string_t** str, char* cat_str);
	extern API  bool			ZLCALL	zl_string_compare(zl_string_t* str, zl_string_t* str2);
	extern API  zl_string_t*	ZLCALL	zl_string_copy(zl_string_t* str);
	extern API  bool			ZLCALL	zl_string_insert(zl_string** str, uint pos, char* insert_str);
	extern API  bool			ZLCALL	zl_string_is_null(zl_string* str);
	extern API  bool			ZLCALL	zl_string_is_number(zl_string* str);
	extern API  bool			ZLCALL	zl_string_is_sub_char(zl_string* str, char c);
	extern API  char*			ZLCALL	zl_string_repace(zl_string** str, const char* target, const char* replace);
	extern API  char*			ZLCALL	zl_str_tokenize(zl_string* str, char delim);
	extern API  char*			ZLCALL	zl_str_trim(zl_string** str);


#ifdef __cplusplus
}
#endif
#endif // ZL_TYPE_STRING_H
