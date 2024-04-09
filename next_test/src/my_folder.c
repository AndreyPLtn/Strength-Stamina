#include "my_folder.h"

static mf_info_t _folders[MF_MAX_TRACKS] = {0};

int mf_get_count_track(const mf_info_t *) {
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
					return 1; //успешно заполнено
			}
		}
	}
	return 0;//track не найден - возвращаем 0
}

int mf_add(mf_info_t* mf_info) {
	_folders[MF_MAX_TRACKS-1].id_track = mf_info -> id_track;
	return 1;//при успешном добавлении возвращается 1
}

int mf_delete(mf_info_t *info, int id_track) {
	for(int i = 0; i < MF_MAX_TRACKS; i++) {
		if (info[i].id_track == id_track) {
			info[i] = info[MF_MAX_TRACKS - 1];
            info[MF_MAX_TRACKS - 1].id_track = 0; // Устанавливаем маркер удаления
            return 1; //успешное удаление
		}
	}
	return 0; //элемент не найден
}

void mf_reset() {
	return;
}
