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
	while((c=fgetc(file))!=EOF)//c��¼��ǰ�ļ�����ֵ
	{
		if(c==' '||c==','||c=='\n'||c==EOF)
			if(b!=9999&&b!=' '&&b!=','&&b!='\n')
				word++;
		chr++;
		b=c;//b��¼c��ǰֵ��b��ֵΪ9999
	}
	if(b!=9999&&b!=' '&&b!=','&&b!='\n')
		word++;//���ϵ��ʼ�¼��
	if(strcmp(argv[1],"-c")==0&&chr!=0)
		printf("�ַ�����%d\n",chr);
	else if(strcmp(argv[1],"-w")==0&&word!=0)
		printf("��������%d\n",word);
	else
		printf("no statistics!\n");
	fclose(file);
	system("pause");
	return 0;
}