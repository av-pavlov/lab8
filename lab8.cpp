#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

using namespace std;

long long size, count, fcount;

void dfs()
{
    DIR* dp = opendir(".");
	struct dirent *res;       // структура для данных записи каталога

	while ((res = readdir(dp)) != NULL) {
	    if (strcmp(res->d_name, ".")==0 || strcmp(res->d_name, "..")==0)
            continue;
        struct stat info;    // структура для данных записи stat
        stat(res->d_name, &info); // получаем данные в структуру info
        if (S_ISDIR(info.st_mode)) {  // если это каталог...
            cout << "DIR ";
            fcount++;
        } else {
            size += info.st_size;
            count++;
        }
	}
    closedir(dp);
}

int main()
{
	dfs();
	cout << count << " files, " << fcount << " dirs, " << size << " bytes.\n";
    return 0;
}

