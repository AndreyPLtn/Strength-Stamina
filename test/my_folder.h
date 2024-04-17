#pragma once

#include <stdbool.h>

#define MF_MAX_TRACKS 10  // максимальное количество элементов (криков) в своей папке

// структура элемента (крика) Своей папки
typedef struct {
	int id_coll;   // ид фонотеки
	int id_fold;   // ид папки
	int id_track;  // ид крика
} mf_info_t;

/**
 * @brief получить количество криков в Своей папке
 *
 * @return int кол-во, -1 - файлов нет
 */
int mf_get_count_track();

/**
 * @brief заполнить структуру элемента (крика) Своей папки
 *
 * @param id номер элемента (крика)
 * @param info структура элемента (крика)
 * @return int 0 - заполнить структуру удалось, -1 - ошибка
 */
int mf_get_info(int id, mf_info_t* info);

/**
 * @brief добавить элемент (крик) в Свою папку
 *
 * @param mf_info структура элемента (крика)
 * @return int 0 - успех, -1 - ошибка
 */
int mf_add(mf_info_t* mf_info);

/**
 * @brief удалить элемент (крик) из Своей папки
 *
 * @param id номер элемента (крика)
 * @return int int 0 - успех, -1 - ошибка
 */
int mf_delete(int id);

/**
 * @brief сброс Своей папки (удаление всех элементов (криков))
 *
 */
void mf_reset();
