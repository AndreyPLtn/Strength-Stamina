#include "my_folder.h"

static mf_info_t _folders[MF_MAX_TRACKS] = {0};

int mf_get_count_track(const mf_info_t *info) {
	int get_count_track = 0;
	for(int i = 0; i < MF_MAX_TRACKS; i++) {
		if(_folders[i].id_fold != 0) {
			get_count_track ++;
		}
	}
	return get_count_track; 
}

int mf_get_info(int id, mf_info_t* info) {
	struct stat info_struct;
		if (stat("path to file", &info_struct) == 0) {
			for(int i = 0; i < MF_MAX_TRACKS; i++) {
				if (_folders[i].id == id) {
					info->id_coll = _folders[i].size;
					info->id_fold = _folders[i].last_modified;
					info->id_track = _folders[i].id;
					return 1; // успешно заполнено
			}
		}
	}
	return 0; //track не найден - возвращаем 0
}

int mf_add(mf_info_t* mf_info) {
    if (num_tracks < MF_MAX_TRACKS) {
        _folders[num_tracks] = *mf_info;
        num_tracks++;
        return 1; // если успешно добавлено
    } else {
        return 0; // если достигнуто максимальное количество треков
    }
}

int mf_delete(int id_track) {
    for (int i = 0; i < num_tracks; i++) {
        if (_folders[i].id == id_track) {
            for (int j = i; j < num_tracks - 1; j++) {
                _folders[j] = _folders[j + 1];
            }
            num_tracks--;
            return 1; // успешно удалено
        }
    }
    return 0; // трек с указанным id не найден
}

void mf_reset() {}
