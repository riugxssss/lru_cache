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

//Main struct for the DLL
typedef struct double_l_list {
    struct node_infos *head;  
    struct node_infos *tail;  
    int n_nodes;
}double_l_list_t;

//Node struct with extra record (key)
typedef struct node_infos {
    int value;
    struct node_infos *prev;
    struct node_infos *next;
    int key;
}node_infos_t;

double_l_list_t *d_linkedlist_create();

node_infos_t *d_linkedlist_insert_node(double_l_list_t *headptr, int value, int key);

void d_linkedlist_remove_lru(double_l_list_t *headptr);

void d_linkedlist_print(double_l_list_t *headptr);

void d_linkedlist_free(double_l_list_t *headptr); 

int d_linkedlist_getLRU(double_l_list_t *headptr);

int d_linkedlist_getMRU(double_l_list_t *headptr);

void d_linkedlist_move_to_head(node_infos_t *NewMRU, double_l_list_t*headptr);

int d_linkedlist_getLRU_key(double_l_list_t *ptr);

