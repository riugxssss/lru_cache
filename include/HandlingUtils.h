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

//Logging struct
typedef struct Log_info log_info;

void error_handler(int handle_code);

void logging_function(int MRUvalue, int LRUvalue);

//Clear the input stream to avoid incorrent reading or some printf bug
inline void clear_stdin(){
    while (getchar() != '\n' && getchar() != EOF);
}

