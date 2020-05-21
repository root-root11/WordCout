#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE *file;
	int c,b=9999;
	int chr=0;
	int word=0;
	if(argc<=2)
	{
		printf("Entered number is erorr!\n");
		return 0;
	}
	file=fopen(argv[2],"r");
	if(file==NULL)
	{
		printf("File open error!\n");
		return 0;
	}
	while((c=fgetc(file))!=EOF)//c记录当前文件读出值
	{
		if(c==' '||c==','||c=='\n'||c==EOF)
			if(b!=9999&&b!=' '&&b!=','&&b!='\n')
				word++;
		chr++;
		b=c;//b记录c的前值，b初值为9999
	}
	if(b!=9999&&b!=' '&&b!=','&&b!='\n')
		word++;//补上单词记录数
	if(strcmp(argv[1],"-c")==0&&chr!=0)
		printf("字符数：%d\n",chr);
	else if(strcmp(argv[1],"-w")==0&&word!=0)
		printf("单词数：%d\n",word);
	else
		printf("no statistics!\n");
	fclose(file);
	system("pause");
	return 0;
}