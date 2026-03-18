/* LRU cache made in C 
 *
 * Copyright (C) 2026 A Riugxss <riugxs@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "double_linked_list.h"


//Slots informations
typedef struct slot_info {
    int key;
    node_infos_t *address;
    int status: 2;
}slot_info_t;

//Hash table informations
typedef struct hash_table{
    int UsedSlot;
    int MaxSlot; 
    struct slot_info **associativearr;
} hash_table_t;

hash_table_t *hash_table_create(int MaxSlot);

void hash_table_delete(hash_table_t *ptr, int key);

void hash_table_insert(hash_table_t *ptr, int key, node_infos_t *NewMRU);

void hash_table_free(hash_table_t *ptr);

node_infos_t *hash_table_search(int key, hash_table_t *ptr);

float hash_table_load_factor(int n, int m);

