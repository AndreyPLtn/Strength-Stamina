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

static mf_info_t* _folders = NULL; // Изменение на указатель

int num_tracks = 0;  // Переменная для хранения текущего количества треков

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

int mf_add(mf_info_t* mf_info) { // добавление нового 
    if (num_tracks == MF_MAX_TRACKS) { // проверка на заполненность в MF_MAX_TRACKS
        printf("Error: Not enough free space"); // выводит ошибку при недостающем места 
        return -1; // возврат -1
    }

    _folders = (mf_info_t*)realloc(_folders, (num_tracks + 1) * sizeof(mf_info_t)); // увеличение памяти на 1 элемент
    _folders[num_tracks] = *mf_info; // копирует инф-ю о новом num_track в последний элемент _folders
    num_tracks++; // +1 указывает на добавление нового num_tracks

    return num_tracks - 1; // Возвращаем индекс добавленного трека
}

int mf_delete(int id) { // удаляет трек из _folders с освобождением памяти
    if (id < 0 || id >= num_tracks) { // проверка id в указанном диапазоне
        printf("Invalid id"); // вывод ошибки
        return -1; // возвращает -1
    }

    for (int i = id; i < num_tracks - 1; i++) { // проверка id через i
        _folders[i] = _folders[i + 1]; // если id корректный 
    }
    num_tracks--; // уменьшает кол-во треков

    _folders = (mf_info_t*)realloc(_folders, num_tracks * sizeof(mf_info_t)); // уменьшает количество выделенной памяти для _folders
                                                                              // через функцию realloc
    return 0; // возврат 0 при успешном удалении
}

void mf_reset() {
    free(_folders); // Освобождаем память через функцию free
    _folders = NULL; // присваивание NULL (_folders не указывает на память)
    num_tracks = 0; // присваивает num_track нулевое значение
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
