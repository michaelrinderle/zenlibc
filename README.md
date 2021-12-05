#Zenlibc
portable c library for embedded systems

# TYPES

+ ZL_HASH

```
zl_hash_t*      zl_hash_init();
bool			zl_hash_append(zl_hash_t* map, char* key, void* data);
bool			zl_hash_remove(zl_hash_t* map, char* key);
bool			zl_hash_free(zl_hash_t* map);
uint			zl_hash_key(char* key);
zl_hashkv_t*    zl_hash_search_key(zl_hash_t* map, char* key);
void			zl_hash_print_map(zl_hash_t* hmap);
```

+ ZL_LIST

```
zl_list_t*		zl_list_init(zl_list_type type);
zl_node_t*		zl_list_init_node(void* node_data);
zl_node_t*		zl_list_append(zl_list_t* list, void* data);
bool			zl_list_free(zl_list_t* list);
zl_node_t*		zl_list_first(zl_list_t* list);
zl_node_t*		zl_list_last(zl_list_t* list);
zl_node_t*		zl_list_get(zl_list_t* list, uint index);
zl_node_t*		zl_list_insert(zl_list_t* list, void* node_data, uint index);
bool			zl_list_remove(zl_list_t* list, uint index);
uint			zl_list_length(zl_list_t* list);
uint			zl_list_size(zl_list_t* list);
char*			zl_list_to_string(zl_node_t* head);
```

+ ZL_STRING

```
zl_string_t*    zl_string_init(char* str);
bool			zl_string_free(zl_string_t* str);
bool			zl_string_cat(zl_string_t** str, char* cat_str);
bool		    zl_string_compare(zl_string_t* str, zl_string_t* str2);
zl_string_t*    zl_string_copy(zl_string_t* str);
bool			zl_string_insert(zl_string** str, uint pos, char* insert_str);
bool			zl_string_is_null(zl_string* str);
bool			zl_string_is_number(zl_string* str);
bool			zl_string_is_sub_char(zl_string* str, char c);
char*			zl_string_repace(zl_string** str, const char* target, const char* replace);
char*			zl_str_tokenize(zl_string* str, char delim);
char*			zl_str_trim(zl_string** str);
```