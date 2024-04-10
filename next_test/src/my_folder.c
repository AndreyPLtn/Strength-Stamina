#include "my_folder.h"

static mf_info_t _folders[MF_MAX_TRACKS] = {0};

void init_array(dynamic_array* arr) { // инициализирует динамический массив dynamic_array
    arr->data = 0; //указатель на данные
    arr->size = 0; //указатель на размер
    arr->capacity = 0; //указатель на вместимость 
} 

int mf_get_count_track(const mf_info_t *info) {
	int get_count_track = 0;
	for(int i = 0; i < MF_MAX_TRACKS; i++) {
		if(_folders[i].id_fold != 0) {
			get_count_track ++;
		}
	}
	return get_count_track; 
} //считает количество криков в структуре _folders, возвращает количество

int mf_get_info(int id, mf_info_t* info) { // Получаем информацию о треке
    if (id == 1) { //логика для крикотреков
        info->id_track; //можно присвоить № track и посмотреть его инф
        strcpy(info->id_fold, "Folder location");
        strcpy(info->id_coll, "Library");
        return 1; // Возвращаем 1 в случае успешного получения информации
    } else {
        return 0; // Возвращаем 0, если трек с заданным id не найден
    }
}

int mf_add(dynamic_array* arr, mf_info_t element) { //добавляем track
    if (arr->size >= arr->capacity) {
        arr->capacity = arr->capacity == 0 ? 1 : arr->capacity * 2; // Увеличивает вместимость
        arr->data = realloc(arr->data, arr->capacity * sizeof(mf_info_t)); // Перевыделение памяти
    }
    arr->data[arr->size++] = element;
	return 1; // успешное добавление
} // добавить элемент в динамический массив

int mf_delete(dynamic_array* arr, int index) { //удаление элемента
    if (index < 0 || index >= arr->size) {
        printf("Error\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
	return 1; //удаление успешно
} 

void mf_reset(mf_info_t* _folders, int id_track) { //функция сброса
    for (int i = 0; i < id_track; i++) {
        strcpy(_folders[i].id_track, "Default Folder");
        _folders[i].id_fold = 0;
		return 1; // успешно сброшено
    }
	return 0; // не сброшено
}
