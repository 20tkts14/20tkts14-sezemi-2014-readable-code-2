#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXREADBYTE 256 //読み込み可能な文字数
#define MAXWORDS 10 //読み込み可能な単語数

//レシピデータのディレクトリパス
const char *RECIPEDATAPATH ="./recipe-data/";


int main(int argc, char const *argv[])
{
	
	char fileName[MAXREADBYTE];
	FILE *recipeFile;

	strcpy(fileName,RECIPEDATAPATH);
	strcat(fileName,argv[1]);

	char recipe[MAXWORDS][MAXREADBYTE]; //レシピ名を読み込む配列

	//エラーの場合は異常終了
	if((recipeFile = fopen(fileName,"r")) == NULL){
		printf("file can't open \n");
		exit(EXIT_FAILURE);
	}


	int i = 0;
	while (fgets(recipe[i], MAXREADBYTE, recipeFile)){
		printf("%d:%s",(i + 1),recipe[i]);
		i++;
	}


	fclose(recipeFile);
	return 0;
}