#pragma once
#include "include/zl_type_string.h"

zl_string_t*
zl_string_init(char* str) {

	// get string details
	const size_t size = sizeof(str);
	const size_t length = strlen(str);

	// allocate buffer
	zl_string_t* buffer = (zl_str*)malloc(sizeof(zl_str) + size + 1);
	if (buffer == NULL) {
#ifdef ZL_DEBUG
		fprintf(stderr, "[*] zl_string_init : error allocating memory");
#endif
		return NULL;
	}

	// set size and copy string to buffer
	buffer->size = size;
	buffer->length = length;
	strcpy(buffer->buffer, str);

	if (buffer == NULL)
		buffer->buffer[0] = '\0';
	else
		buffer->buffer[length] = '\0';

	return buffer;
}

bool
zl_string_free(zl_string_t* str) {

	// free string struct & check operation
	free(str);
	str = NULL;
	if (str == NULL)
	{
#ifdef ZL_DEBUG
		fprintf(stderr, "[*] zl_str_free : error freeing memory\n");
#endif
		return FALSE;
	}

	return TRUE;
}

bool
zl_string_cat(zl_string_t** str, char* cat_str) {

	// get new string size details
	char* temp = strcat((*str)->buffer, cat_str);
	size_t new_size = strlen(temp) + 1;
	size_t length = (*str)->length + strlen(cat_str);

	// update string len & size details
	if ((*str)->size != new_size) {

		(*str)->size = new_size;
		(*str)->length = length;
	}

	// concat string
	strcpy(&(*str)->buffer[new_size], temp);
	(*str)->buffer[new_size] = '\0';

	return TRUE;
}

bool
zl_string_cmp(zl_string_t* str, zl_string_t* str2) {

	// string compare buffers
	const int result = strcmp(str->buffer, str2->buffer);
	if (result != 0)
		return FALSE;

	return TRUE;
}

zl_string_t*
zl_string_cpy(zl_string_t* str)
{
	// allocate buffer
	zl_string_t* buffer = (zl_string_t*)malloc(sizeof(zl_string_t*));
	if (buffer == NULL) return NULL;
	// copy values and string buffer
	*buffer = *str;
	strcpy(buffer->buffer, str->buffer);
	return buffer;
}

bool
zl_string_insert(zl_string_t** str, uint pos, char* insert_str)
{
	if (str == NULL || insert_str == NULL) {
#ifdef ZL_DEBUG
		fprintf(stderr, "[zl] zl_str_ins : null value\n");
#endif
		return FALSE;
	}
	// create temp buffer
	char* temp = "\0";
	// copy start text
	strncpy(temp, (*str)->buffer, pos);
	int length = strlen(temp);
	// copy insert text
	strcpy(temp + length, insert_str);
	length += strlen(insert_str);
	// copy end text
	strcpy(temp + length, (*str)->buffer + pos);

	// update string len + size
	(*str)->size = sizeof(temp);
	(*str)->length = strlen(temp);

	// copy temp buffer over
	strcpy(&(*str)->buffer, temp);
	return TRUE;
}

bool
zl_string_is_null(zl_string_t* str) {

	// check length of string
	if (str->length != 0)
		return FALSE;

	return TRUE;
}

bool
zl_string_is_number(zl_string_t* str)
{
	if (str->buffer == NULL) return FALSE;

	// iterate over string & examine each char for alpha
	for (char* temp = str->buffer; *temp != '\0'; temp++) {
		if (isalpha(temp))
			return FALSE;
	}

	return TRUE;
}

bool
zl_string_is_sub_char(zl_string_t* str, char c)
{
	return strchr(str->buffer, c);
}

char*
zl_string_replace(zl_string_t** str, const char* target, const char* replace)
{
	char* p;
	int final_size = 0;
	const int search_size = strlen(target);

	// count how many occurrences
	for (p = strstr((*str)->buffer, (*str)->buffer);
		p != NULL;
		p = strstr(p + search_size, (*str)->buffer))
		final_size++;

	// final size
	final_size = (strlen(replace) - search_size) * final_size + strlen((*str)->buffer);

	// new subject with new size
	char* new_subject = (char*)malloc(final_size);

	// set it to blank
	strcpy(new_subject, "");

	// the start position
	char* old = (*str)->buffer;

	for (p = strstr((*str)->buffer, target);
		p != NULL; p = strstr(p + search_size, target))
	{
		// move ahead and copy some text from original subject , from a certain position
		strncpy(new_subject + strlen(new_subject), old, p - old);

		// move ahead and copy the replacement text
		strcpy(new_subject + strlen(new_subject), replace);

		// the new start position after this search match
		old = p + search_size;
	}

	// copy the part after the last search match
	strcpy(new_subject + strlen(new_subject), old);
	// copy new
	strcpy((*str)->buffer, new_subject);

	return new_subject;
}

char*		// todo
zl_string_tokenize(zl_string_t* str, char delim)
{
	uint token_count;
	char* tokens[] = NULL, piece[] = NULL;
	char* token = strtok(str, delim);
	do {
		strcpy(tokens[token_count], token);
		piece = strtok(NULL, str);
		token_count++;
	} while (piece != NULL);

	while (piece != NULL) {
		strcpy(tokens[token_count], piece);
		piece = strtok(NULL, str);
	}
	return tokens;
}

char*
zl_string_trim(zl_string_t** str)
{
	char* part = (*str)->buffer;
	int len = strlen(part);
	// trim lead & tail whitespace
	// saving ptr by moving to beginning
	while (isspace(part[len - 1])) part[--len] = 0;
	while (*part && isspace(*part)) ++part; --len;
	// update string len & size
	(*str)->size = sizeof(part);
	(*str)->length = strlen(part);
	memmove(&(*str)->buffer, part, (len + 1));

	return part;
}