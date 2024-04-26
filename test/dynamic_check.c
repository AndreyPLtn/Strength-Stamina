#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// использование динамического выделения памяти для _folders

#define MF_MAX_TRACKS 10 // максимальное количество элементов (криков) в своей папке

// структура элемента (крика) Своей папки
typedef struct {
	int id_coll;   // ид фонотеки
	int id_fold;   // ид папки
	int id_track;  // ид крика
} mf_info_t;

static mf_info_t* _folders = NULL;

int num_tracks = 0;  // Переменная для хранения текущего количества треков

int mf_get_count_track() {
    return num_tracks; // возвращает количество треков
}

int mf_get_info(int id, mf_info_t* info) {
    if (id < 0 || id >= num_tracks) {
        printf("Invalid id");
        return -1;
    }

    *info = _folders[id];
    return 0;
}

int mf_add(mf_info_t* mf_info) { // добавление нового крика 
    if (num_tracks == MF_MAX_TRACKS) {
        printf("Error: Not enough free space");
        return -1;
    }

    mf_info_t* temp = (mf_info_t*)realloc(_folders, (num_tracks + 1) * sizeof(mf_info_t)); // изменяет размер выделенной памяти для _folders
    if (temp == NULL) {
        printf("Memory reallocation error");
        return -1;
    }

    _folders = temp; // присваивает временную переменную в _folders (свидетельство успешного выделения памяти)
    _folders[num_tracks] = *mf_info;
    num_tracks++;

    return num_tracks - 1;
}

int mf_delete(int id) { // удаляет трек из _folders с освобождением памяти
    if (id < 0 || id >= num_tracks) {
        printf("Invalid id");
        return -1;
    }

    for (int i = id; i < num_tracks - 1; i++) { // проверка id через i
        _folders[i] = _folders[i + 1];
    }
    num_tracks--;

    _folders = (mf_info_t*)realloc(_folders, num_tracks * sizeof(mf_info_t)); // уменьшает количество выделенной памяти для _folders
        if (_folders == NULL) {
            printf("Delete error");
            return -1;
    }
    return 0;
}

void mf_reset() {
    free(_folders); // Освобождаем память через функцию free
    _folders = NULL;
    num_tracks = 0;
}

int main() {
    printf("start appn");

    // проверка
    mf_info_t track1 = {1, 2, 3};
    mf_add(&track1);

    mf_info_t track2;
    mf_get_info(0, &track2);

    mf_delete(0);

    mf_reset();

    return 0;
}
