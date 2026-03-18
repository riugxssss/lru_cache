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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "lru_usage.h"
#include "HandlingUtils.h"

#define LRU_CACHE_CAPACITY 100
#define MENU_EXIT          99

static void print_menu(void) {
    printf("\nMenu:\n");
    printf("1) PUT\n");
    printf("2) GET\n");
    printf("3) PRINT CACHE\n");
    printf("4) MAKE LOG\n");
    printf("99) EXIT\n");
    printf("Choice: ");
}

static int read_int(const char *prompt, int *out) {
    printf("%s", prompt);
    if (scanf("%d", out) != 1) {
        clear_stdin();
        return -1;
    }
    return 0;
}

int main(void) {
    lru_cache_t *cache = lru_cache_create(LRU_CACHE_CAPACITY);
    if (!cache) {
        perror("lru_cache_create");
        return EXIT_FAILURE;
    }

    printf("=== LRU CACHE TEST ===\n");
    printf("Capacity: %d\n", LRU_CACHE_CAPACITY);

    int choice = 0;
    int key = 0;
    int value = 0;

    while (choice != MENU_EXIT) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            clear_stdin();
            continue;
        }

        switch (choice) {
        case 1:
            if (read_int("Key: ", &key) < 0 ||
                read_int("Value: ", &value) < 0) {
                printf("Invalid input\n");
                break;
            }

            lru_cache_put(key, value, cache);
            printf("PUT (%d, %d)\n", key, value);
            break;

        case 2:
            if (read_int("Key: ", &key) < 0) {
                printf("Invalid input\n");
                break;
            }

            value = lru_cache_get(key, cache);
            if (value >= 0) {
                printf("GET key=%d -> value=%d\n", key, value);
            } else {
                printf("Key %d not found\n", key);
            }
            break;

        case 3:
            lru_cache_print(cache);
            break;

        case 4:
            lru_cache_make_logs(cache);
            printf("Log generated\n");
            break;

        case MENU_EXIT:
            printf("Exiting...\n");
            break;

        default:
            printf("Unknown choice\n");
            break;
        }
    }

    lru_cache_clear(cache);
    return EXIT_SUCCESS;
}
