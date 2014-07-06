#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//レシピデータのディレクトリパス
const char *RECIPEDATAPATH ="./recipe-data/";

int main(int argc, char const *argv[])
{
	
	char fileName[30];
	FILE *recipeFile;

	strcpy(fileName,RECIPEDATAPATH);
	strcat(fileName,argv[1]);


	char recipe[20];

	//エラーの場合は異常終了
	if((recipeFile = fopen(fileName,"r")) == NULL){
		printf("file can't open \n");
		exit(EXIT_FAILURE);
	}


	while (fgets(recipe, 20, recipeFile)){
		printf("%s",recipe);
	}
	

	fclose(recipeFile);
	return 0;
}