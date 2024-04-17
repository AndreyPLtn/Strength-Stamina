#include "my_folder.h"

static mf_info_t _folders[MF_MAX_TRACKS] = {0}; // объявление статического массива _folders размером MF_MAX_TRACKS с нулевым значением

int num_tracks = 0; // Переменная для хранения текущего количества треков

int mf_get_count_track() {
    return num_tracks; // возвращает количество треков
}

int mf_get_info(int id, mf_info_t* info) {
    if (id < 0 || id >= num_tracks) { // проверка id в диапазоне
        printf("Invalid id"); // при не соответствии выводит ошибку
        return -1; // возвращает -1
    }

    *info = _folders[id]; // при совпадении копирует id из _folders в info
    return 0; // возвращает 0 при успехе
}

int mf_add(mf_info_t* mf_info) { // добавление нового крика 
    if (num_tracks == MF_MAX_TRACKS) { // проверка на максимальное значение криков
        printf("Error: Not enough free space");
        return -1; // выводит -1 при отсутствии места
    }

    _folders[num_tracks] = *mf_info; // информация о крике копируется в _folders[] с индексом num_tracks через указатель mf_info 
    num_tracks++; // увеличение счетчика на 1 после копирования

    return num_tracks - 1; // возврат присвоенного индекса
}

int mf_delete(int id) { // удаление крика по id
    if (id < 0 || id >= num_tracks) { // проверка в диапазоне 0 - количество криков
        printf("Invalid id");
        return -1; // выводит -1 при ошибке
    }

    for (int i = id; i < num_tracks - 1; i++) {
        _folders[i] = _folders[i + 1]; // сдвиг 
    }
    num_tracks--; // -1 у количества крика (свидетельство успешного удаления)

    return 0; // возврат 0 при успешном удалении
}

void mf_reset() { 
    num_tracks = 0; // сброс
}
