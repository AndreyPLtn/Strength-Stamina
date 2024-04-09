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
/*
Информация по файловой системе
*/
int mf_get_info(int id, mf_info_t* info) {
	struct stat info_struct {
		stat("path to file", &info_struct);
		for(int i = 0; i <=MF_MAX_TRACKS; i++)
		info->mf_info_t.id_coll= _folders[i].size;
		info->mf_info_t.id_fold = _folders[i].last_modified;
		info->mf_info_t.id_track = _folders[i].id;
	}
	return 0;
}

int mf_add(mf_info_t* mf_info) {
	_folders[MF_MAX_TRACKS-1].id_coll=mf_info->size;
	_folders[MF_MAX_TRACKS-1].id_fold=mf_info->last_modified;
	_folders[MF_MAX_TRACKS-1].id_track=mf_info->info;
	return 0;
}

int mf_delete(int id) {
	for(int i=0; i<MF_MAX_TRACKS; i++){
		if(_folders[i].id_fold==id){
			_folders[i]=_folders[MF_MAX_TRACKS-1];
		break;
		}
	}
	return 0;
}
void mf_reset() {
	return;
}