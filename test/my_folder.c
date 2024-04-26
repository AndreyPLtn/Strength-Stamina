#include "my_folder.h"

static mf_info_t _folders[MF_MAX_TRACKS] = {0}; // объявление статического массива _folders размером MF_MAX_TRACKS с нулевым значением

int num_tracks = 0; // Переменная для хранения текущего количества треков

int mf_get_count_track() {
    return num_tracks; // возвращает количество треков
}

int mf_get_info(int id, mf_info_t* info) {
    if (id < 0 || id >= num_tracks) { // проверка id в диапазоне
        printf("Invalid id");
        return -1;
    }

    *info = _folders[id]; // при совпадении копирует id из _folders в info
    return 0;
}

int mf_add(mf_info_t* mf_info) { // добавление нового крика 
    if (num_tracks == MF_MAX_TRACKS) {
        printf("Error: Not enough free space");
        return -1;
    }

    _folders[num_tracks] = *mf_info; // информация о крике копируется в _folders[] с индексом num_tracks через указатель mf_info 
    num_tracks++;

    return num_tracks - 1;
}

int mf_delete(int id) { // удаление крика по id
    if (id < 0 || id >= num_tracks) {
        printf("Invalid id");
        return -1;
    }

    for (int i = id; i < num_tracks - 1; i++) {
        _folders[i] = _folders[i + 1]; // сдвиг 
    }
    num_tracks--;

    return 0;
}

void mf_reset() { 
    num_tracks = 0; // сброс
}
