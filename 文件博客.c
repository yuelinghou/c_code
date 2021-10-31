
//struct FILE 
//{
//  char*_ ptr;
//  int _cnt;
//  char* _base;
//  int _flag;
//  int _file;
//  int _charbuf;
//  int _bufsiz;
//  char* _tmpfname;
//};

#include <stdio.h>

//void Testfputc()
//{
//  // 1、用"r"方式打开已经存在的文件
//  // 刚打开时_ptr指向字符的开始位置
//  FILE* pf = fopen("log.txt", "r");
//  // 2、使用fputc写入a~z
//  int i = 0;
//  for(i = 'a'; i <= 'z'; ++i)
//  {
//    fputc(i, pf);
//  }
//  // 3、使用fgetc依次读取文件的每一个字符
//  // 3、关闭文件
//  fclose(pf);
//  pf = NULL;

//void Testfgetc()
//{
//  // 1、用"r"方式打开已经存在的文件
//  // 刚打开时_ptr指向字符的开始位置
//  FILE* pf = fopen("log.txt", "r");
//
//  // 2、使用fgetc依次读取文件的每一个字符
//  int ch = 0;
//  while((ch = fgetc(pf)) != EOF)
//  {
//    printf("%c", ch);
//  }
//  printf("\n");
//
//  // 3、关闭文件
//  fclose(pf);
//  pf = NULL;
//}

//void Testfputs()
//{
//  // 1、以"w"方式打开文件，清除该文件之前的内容
//  FILE* pf = fopen("log.txt", "w");
//
//  // 2、使用fputs写入一行字符串
//  const char* s = "hello world";
//  fputs(s, pf);
//
//  // 3、关闭文件
//  fclose(pf);
//  pf = NULL;
//}


//void Testfgets()
//{
//  // 1、用"r"方式打开已经写入过的log.txt
//  FILE* pf = fopen("log.txt", "r");
//
//  // 2、使用fgets从文件里读取字符串放到str中
//  char str[12] = {0};
//  fgets(str, 12, pf);
//  printf("%s\n", str);
//
//  // 关闭文件
//  fclose(pf);
//  pf = NULL;
//}

//struct Person
//{
//  char name[20];
//  int age;
//};
//
//void Testfprintf()
//{
//  // 1、打开文件
//  FILE* pf = fopen("log.txt", "w");
//  // 2、对文件进行格式化写入
//  Person p = {"zhangsan", 18};
//  fprintf(pf, "%s %d", p.name, p.age);
//  // 3、关闭文件
//  fclose(pf);
//  pf = NULL;
//}
//
//struct Person
//{
//  char name[20];
//  int age;
//};
//
//
//void Testfscanf()
//{
//  // 1、打开前面格式化写入之后的文件
//  FILE* pf = fopen("log.txt", "r");
//  // 2、用fscanf格式化读取文件内容
//  Person p;
//  fscanf(pf, "%s %d", p.name, &p.age);
//  // 3、打印文件中读取出来的数据
//  printf("%s %d\n", p.name, p.age);
//  // 4、关闭文件
//  fclose(pf);
//  pf = NULL;
//}

//void Testfwrite()
//{
//  // 1、以"wb"方式打开文件，写入内容将转化为二进制形式
//  FILE* pf = fopen("log.txt", "wb");
//  // 2、把数组arr的内容以二进制形式写入到文件中
//  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//  fwrite(arr, sizeof(int), sizeof(arr)/sizeof(int), pf);
//  // 3、关闭文件
//  fclose(pf);
//  pf = NULL;
//}

//void Testfread()
//{
//  // 1、以"rb"方式打开文件，进行二进制内容的读取
//  FILE* pf = fopen("log.txt", "rb");
//  // 2、读取文件内容到数组arr中
//  int arr[10] = {0};
//  fread(arr, sizeof(int), 10, pf);
//  int i = 0;
//  for(i = 0; i < 10; ++i)
//  {
//    printf("%d ", arr[i]);
//  }
//  printf("\n");
//  // 3、关闭文件
//  fclose(pf);
//  pf = NULL;
//}

//struct FILE 
//{
//  char *_ptr;  
//  int   _cnt;  
//  char *_base;  
//  int   _flag;  
//  int   _file;  
//  int   _charbuf;  
//  int   _bufsiz;  
//  char *_tmpfname;
//};

void Test()
{
  FILE* pf = fopen("log.txt", "r");
  // 读取第一个字符，位置指示器向后移动一位
  int ch = 0;
  ch = fgetc(pf);
  printf("%c\n", ch);// a
  // 再次读取一个字符，位置指示器继续往后移动一位
  ch = fgetc(pf);
  printf("%c\n", ch);// b
  // 方法一
  //fseek(pf, SEEK_SET, 0);
  //ch = fgetc(pf);
  //printf("%c\n", ch);
  // 方法二
  //fseek(pf, -2, SEEK_CUR);
  //ch = fgetc(pf);
  //printf("%c\n", ch);
  // 方法三
  //fseek(pf, -7, SEEK_END);
  //ch = fgetc(pf);
  //printf("%c\n", ch);
  //long distance = ftell(pf);
  //printf("%ld\n", distance);//2
  rewind(pf);
  ch = fgetc(pf);
  printf("%c\n", ch);//a
  fclose(pf);
  pf = NULL;
}

int main()
{
  Test();
  //Testfread();
  //Testfwrite();
  //Testfprintf();
  //Testfscanf();



  //----------------------------------------------------------//
  //Testfgets();
  //Testfputs();
  //Testfgetc();
  //Testfputc();

  // 1、打开文件
  //FILE* pf = fopen("log.txt", "w");
  //if(pf == NULL)
  //{
  //  printf("open error\n");
  //  return 1;
  //}

  //// 2、对文件进行一系列操作
  //// .......
  //
  //// 3、关闭文件
  //fclose(pf);
  //pf = NULL;
  
  //FILE* pf = fopen("log.txt", "r");
  //fputc('a', pf);
  //fputc('b', pf);
  //fputc('c', pf);
  //printf("%c\n", fgetc(pf));

  return 0;
}

