#pragma once
#include "include/zl_type_list.h"

zl_list_t*
zl_list_init(zl_list_type type) {
	zl_list_t* list = (zl_list_t*)malloc(sizeof(zl_list_t*));
	list->length = 0;
	list->first = NULL;
	list->last = NULL;
	list->type = type;
	return list;
}

zl_node_t*
zl_list_init_node(void* node_data) {
	zl_node_t* new_node = (zl_node_t*)malloc(sizeof(zl_node_t));
	if (new_node == NULL) {
		fprintf(stderr, "[*] problem allocating list node");
		return NULL;
	}
	new_node->data = node_data;
	new_node->size = sizeof(node_data);
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

zl_node_t*
zl_list_append(zl_list_t* list, void* data) {
	// check if index is incorrect
	zl_node_t* new_node;
	zl_node_t* last_node;
	// create node
	new_node = zl_list_init_node(data);
	if (new_node != NULL) {
		// check for empty list
		if (list->length == 0) {
			list->first = new_node;
			list->last = new_node;
			// incr list length
			list->length++;
			return new_node;
		}
		// get last node on list
		last_node = list->last;
		// point last node to new node
		last_node->next = new_node;
		// point back
		new_node->prev = last_node;
		// correct list incr list length
		list->last = new_node;
		list->length++;
		return new_node;
	}
	return NULL;
}

bool
zl_list_free(zl_list_t* list) {
	zl_node_t* del = NULL;
	zl_node_t* first = NULL;
	// assign addr of first node
	first = list->first;
	// loop thru list to free each node
	while (first != NULL) {
		// copy first node to temp
		del = first;
		// mv to next in list
		first = first->next;
		// free the allocd mem
		free(del);
		del = NULL;
	}
	// free out list
	list = NULL;
	free(list);

	return (list == NULL) ? TRUE : FALSE;
}

zl_node_t*
zl_list_first(zl_list_t* list) {
	// redundant but explicit
	return list->first;
}

zl_node_t*
zl_list_last(zl_list_t* list) {
	// redundant but explicit
	return list->last;
}

zl_node_t*
zl_list_get(zl_list_t* list, uint index) {
	zl_node_t* current = list->first;
	uint node_size = current->size;
	uint node_count = 0;
	if (index > node_size) {
		fprintf(stderr, "[*] supplied index out of range");
		return NULL;
	}
	// move through list
	while (current != NULL) {
		if (node_count == index) {
			return current;
		}
		// move to next in list until index
		current = current->next;
		node_count++;
	}
	fprintf(stderr, "[*] issue locating list");

	return NULL;
}

zl_node_t*
zl_list_insert(zl_list_t* list, void* node_data, uint index) {
	zl_node_t* current = list->first;
	zl_node_t* new_node;
	zl_node_t* temp;
	zl_node_t* next;
	size_t data_size = sizeof(node_data);
	uint node_count = 0;
	// append if index greater than list length
	if (index >= list->length) {
		new_node = zl_list_append(list, node_data);
		if (new_node == NULL) {
			fprintf(stderr, "[*] could not create to insert");
			return NULL;
		}
		list->length++;
		return new_node;
	}
	// create node
	new_node = zl_list_init_node(node_data);
	if (new_node == NULL) {
		fprintf(stderr, "[*] could not create to insert");
		return NULL;
	}
	// mv list to insert node into list at index
	while (current != NULL) {
		if (node_count == index) {
			// swap around on beginning insert
			if (node_count == 0) {
				temp = current;
				next = current->next;
				current = new_node;
				current->next = temp;
				temp->next = next;
			}
			else
			{
				// move current back, insert & link next
				temp = current;
				next = current->next;
				current = new_node;
				current->next = next;
				temp->next = current;
			}
			list->length++;
			return new_node;
		}
		// move to next node and incr
		current = current->next;
		node_count++;
	}
	if (new_node == NULL) {
		fprintf(stderr, "[*] could not create to insert");
	}

	return NULL;
}

bool
zl_list_remove(zl_list_t* list, uint index) {
	zl_node_t* prev, * next, * current = list->first;
	uint node_count = 0;
	// index check
	if (index > list->length) {
		fprintf(stderr, "[*] incorrect index number");
		return false;
	}
	while (current != NULL) {
		if (node_count == index) {
			// break list on index
			if (current->prev == NULL) {
				// beginning check
				next = current->next;
				next->prev = NULL;
				current = next;
			}
			else if (current->next == NULL) {
				// end check
				prev = current->prev;
				prev->next = NULL;
				current = prev;
			}
			else {
				// break list
				prev = current->prev;
				next = current->next;
				// link list back together
				prev->next = next;
				next->prev = next;
				free(current);
			}
			// decr list length
			list->length--;
			return true;
		}
		current = current->next;
		node_count++;
	}

	return false;
}

uint
zl_list_length(zl_list_t* list) {
	zl_node_t* first_node = list->first;
	uint length = 0;
	while (first_node != NULL) {
		length++;
		first_node = first_node->next;
	}

	return length;
}

uint
zl_list_size(zl_list_t* list) {
	zl_node_t* first_node = list->first;
	uint size = 0;
	while (first_node != NULL) {
		size += sizeof(first_node->data);
		first_node = first_node->next;
	}

	return size;
}

char*
zl_list_to_string(zl_node_t* head) {
	// todo : make dynamic function
	return (char*)head->next;
}