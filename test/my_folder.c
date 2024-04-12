#include "my_folder.h"

static mf_info_t _folders[MF_MAX_TRACKS] = {0}; // начальное количество 

int mf_get_count_track() { // показывает количество id_track в _folders
	return sizeof(_folders) / sizeof(_folders[0]); // количество _folders делится на размер 1 _folders
}

int mf_get_info(int id, mf_info_t* info) { // получаем инф-ю о id_track с определенным id в массиве _folders
	if (id < 0 || id >= MF_MAX_TRACKS) { // перебирает id в пределах 0 - MF_MAX_TRACKS
        printf("Invalid id"); // если id вне диапазона выводит ошибку
        return -1; // возращает -1
    }

    *info = _folders[id]; // (оператор разыменовывания) если id корректныйй, копирует инф-ю с id из _folders в info  
    return 0; // возврат 0 при успехе
}

int mf_add(mf_info_t* mf_info) { // добавление новой инф-и о id_track, возврат index или -1
    for (int i = 0; i < MF_MAX_TRACKS; i++) { // перебирает элементы 0 - MF_MAX_TRACKS
        if (_folders[i].id_track == 0) { // проверка свободного id_track
            _folders[i] = *mf_info; // если id_track свободен, копирует инф-ю в этот элемент
            return i; // возвращает index этого элемента
        }
    }
    printf("Error: Not enough free space"); // при отсутствии свободных элементов
    return -1; // возврат -1 при ошибке
}

int mf_delete(int id) { // проверяет id в диапазоне 0 - MF_MAX_TRACKS
    if (id < 0 || id >= MF_MAX_TRACKS) { // id недействителен = ошибка
        printf("Invalid id"); 
        return -1; // возврат -1 при ошибке
    }

    _folders[id].id_track = 0; // при существующем id - делает элемент пустым
    return 0; // после возвращает 0
}

void mf_reset() { // обнуление id_track во всех _folders
    for (int i = 0; i < MF_MAX_TRACKS; i++) {
        _folders[i].id_track = 0; // присваивание 0 для id_track во всех _folders
    }
}