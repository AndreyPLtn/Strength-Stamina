#pragma once //директива для компилятора о включении в программу блока кода 1 раз 

#include <stdbool.h> 

#define MF_MAX_TRACKS 10  // максимальное количество элементов (криков) в своей папке

mf_info_t _folders[MF_MAX_TRACKS];
int num_tracks = 0; // текущее количество записей криков

// структура элемента (крика) Своей папки
typedef struct { 
	int id_coll;   // ид фонотеки
	int id_fold;   // ид папки
	int id_track; // ид крика
	int data; //ид данных
} mf_info_t;

 // динамический массив с элементами mf_info_t
typedef struct {
    mf_info_t* data; // Указатель на данные
    int size;        // Текущий размер
    int capacity;    // Вместимость
} dynamic_array;

void init_array(dynamic_array* arr) { // инициализирует динамический массив dynamic_array
	
};

/**
 * @brief получить количество криков в Своей папке
 *
 * @return int кол-во, -1 - файлов нет
 */
int mf_get_count_track(const mf_info_t *info);

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
int mf_add(dynamic_array* arr, mf_info_t element);

/**
 * @brief удалить элемент (крик) из Своей папки
 *
 * @param id номер элемента (крика)
 * @return int int 0 - успех, -1 - ошибка
 */
int mf_delete(dynamic_array* arr, int index);

/**
 * @brief сброс Своей папки (удаление всех элементов (криков))
 *
 */
void mf_reset(mf_info_t* _folders, int id_track);
