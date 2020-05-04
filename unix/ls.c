#include "ls.h"
#include "apue.h"

void readdir_recursive(const char *dirname, int depth) {
	DIR	*dp;
	struct dirent *dirp;

	if (0 != depth && (0 == strcmp(dirname, ".") || 0 == strcmp(dirname, ".."))) {
		err_msg("errno");
		return;
	}

	if ((dp = opendir(dirname)) == NULL)
		err_sys("can't open %s", dirname);

	while ((dirp = readdir(dp)) != NULL) {
		if (dirp->d_name[0] == '.') {
			continue;
		}

		prefix_output(depth + 1);
		printf("%s\n", dirp->d_name);

		if (4 == dirp->d_type) {
			char dir_path[100];
			snprintf(dir_path, sizeof(dir_path), "%s/%s", dirname, dirp->d_name);
			readdir_recursive(dir_path, depth + 1);
		}
	}

	closedir(dp);
}

void prefix_output(int depth) {
	while (depth > 0) {
		if (depth == 1)
			printf("├── ");
		else
			printf("│   ");
		--depth;
	}
}
