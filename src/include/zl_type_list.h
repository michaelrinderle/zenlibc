#ifndef ZL_TYPE_LIST_H
#define ZL_TYPE_LIST_H
#ifdef __cplusplus
extern "C" {
#endif

#include "zenlibc.h"

	typedef enum {
		STR_LIST_TYPE,
		INT_LIST_TYPE,
		FLOAT_LIST_TYPE,
		VOID_LIST_TYPE,
	} zl_list_type;

	typedef struct zl_node_t {
		zl_any_t data;
		size_t size;
		struct zl_node_t* prev;
		struct zl_node_t* next;
	} zl_node_t, zl_node;

	typedef struct zl_list_t {
		int length;
		zl_list_type type;
		struct zl_node_t* first;
		struct zl_node_t* last;
	} zl_list_t, zl_list;

	extern API zl_list_t*	ZLCALL	zl_list_init(zl_list_type type);
	extern API zl_node_t*	ZLCALL	zl_list_init_node(void* node_data);
	extern API zl_node_t*	ZLCALL	zl_list_append(zl_list_t* list, void* data);
	extern API bool			ZLCALL	zl_list_free(zl_list_t* list);
	extern API zl_node_t*	ZLCALL	zl_list_first(zl_list_t* list);
	extern API zl_node_t*	ZLCALL	zl_list_last(zl_list_t* list);
	extern API zl_node_t*	ZLCALL	zl_list_get(zl_list_t* list, uint index);
	extern API zl_node_t*	ZLCALL	zl_list_insert(zl_list_t* list, void* node_data, uint index);
	extern API bool			ZLCALL	zl_list_remove(zl_list_t* list, uint index);
	extern API uint			ZLCALL	zl_list_length(zl_list_t* list);
	extern API uint			ZLCALL	zl_list_size(zl_list_t* list);
	extern API char*		ZLCALL	zl_list_to_string(zl_node_t* head);

#ifdef __cplusplus
}
#endif
#endif // ZL_TYPE_LIST_H