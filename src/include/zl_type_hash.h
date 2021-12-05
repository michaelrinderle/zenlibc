#ifndef ZL_TYPE_HASH_H
#define ZL_TYPE_HASH_H
#ifdef __cplusplus
extern "C" {
#endif

#include "zenlibc.h"

	typedef enum {
		STR_HASH_TYPE,
		INT_HASH_TYPE,
		FLOAT_HASH_TYPE,
		VOID_HASH_TYPE,
	} zl_hash_type;

	typedef struct zl_hashkv_t {
		char* key;
		zl_any_t value;
	} zl_hashkv_t, zl_hashkv;

	typedef struct zl_hash_t {
		uint table_size;
		uint size;
		zl_hashkv_t* table;
	} zl_hash_t, zl_hash;

	extern API  zl_hash_t*		ZLCALL	zl_hash_init();
	extern API  bool			ZLCALL	zl_hash_append(zl_hash_t* map, char* key, void* data);
	extern API  bool			ZLCALL	zl_hash_remove(zl_hash_t* map, char* key);
	extern API  bool			ZLCALL	zl_hash_free(zl_hash_t* map);
	extern API  uint			ZLCALL	zl_hash_key(char* key);
	extern API  zl_hashkv_t*	ZLCALL	zl_hash_search_key(zl_hash_t* map, char* key);
	extern API  void			ZLCALL	zl_hash_print_map(zl_hash_t* hmap);

#ifdef __cplusplus
}
#endif
#endif //  ZL_TYPE_HASH_H