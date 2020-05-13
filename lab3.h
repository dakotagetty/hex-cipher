char **createTitlesArray(char **titles, int numBooks);

char ***createFavoritesArray(char ***favorites, char **titles, int numFavorites);

int saveToFile(char *fileName, char **titles, char ***favorites, int numBooks, int numFavorites);
