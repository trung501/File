//Code con nhieu thieu sot mong moi nguoi gop y
//TRUNG TRAN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Iris
{
   float sepalLength, sepalWidth, petalLength, petalWidth;
   char cls[20];
} Iris;
bool readFile()
{
   Iris *iris;
   iris = (Iris *)malloc(sizeof(struct Iris));
   system("cls");
   int n;
   printf("1: Doc File iris.data:\n");
   printf("2: Doc File binary.data:\n");
   scanf("%d", &n);
   FILE *fp;
   char s[255];
   if (n == 2)
   {
      fp = fopen("binary.data", "rb");
      if ((fp) == NULL)
      {
         fprintf(stderr, "impossible to open: binary.data\n");
         perror("Because:");
         fclose(fp);
         fflush(stdin);
         getchar();
         return false;
      }
      while (fscanf(fp, "%s", s) != EOF)
      {
         s[strlen(s)] = '\n';
         printf("%s", s);
      }
   }
   else
   {
      fp = fopen("iris.data", "rb");
      if ((fp) == NULL)
      {
         fprintf(stderr, "impossible to open: iris.data\n");
         perror("Because:");
         fclose(fp);
         fflush(stdin);
         getchar();
         return false;
      }
      Iris *iris;
      iris = (Iris *)malloc(sizeof(struct Iris));
      fscanf(fp, "%s", s);
      printf(" So phan tu : %s\n", s);
      printf("   Sepal Length     Sepal Width     Petal Length    Petal Width            Class\n");
      while (fscanf(fp, "%f,%f,%f,%f,%s", &(iris->sepalLength), &(iris->sepalWidth), &(iris->petalLength), &(iris->petalWidth), iris->cls) != EOF)
      {
         //s[strlen(s)] = '\n';
         printf("\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%s\n", iris->sepalLength, iris->sepalWidth, iris->petalLength, iris->petalWidth, iris->cls);
      }
   }
   free(iris);
   fclose(fp);
   fflush(stdin);
   getchar();
   free(iris);
   return 0;
}
int writeFile()
{
   char iris_setosa[20] = "Iris-setosa";
   char iris_versicolo[20] = "Iris-versicolor";
   char iris_virginica[20] = "Iris-virginica";
   system("cls");
   char soDong[10];
   FILE *fp;
   Iris *iris;
   iris = (Iris *)malloc(sizeof(struct Iris));
   int a;
   fp = fopen("iris.data", "r+");
   if ((fp) == NULL)
   {
      fprintf(stderr, "impossible to open: iris.data\n");
      perror("Because:");
      fclose(fp);
      return false;
   }
   fscanf(fp, "%s", &soDong);
   int i = 0;
   sscanf(soDong, "%d", &i);
   while (true)
   {
      printf("\nNhap cac thong so vao de ghi file");
      printf("\nThoat ghi file nhap 0");
      printf("\nNhap Sepal Length :");
      scanf("%f", &(iris->sepalLength));
      if (iris->sepalLength == 0.0)
      {
         fclose(fp);
         return true;
      }
      printf("\nNhap Sepal Width :");
      scanf("%f", &(iris->sepalWidth));
      printf("\nNhap Petal Length :");
      scanf("%f", &(iris->petalLength));
      printf("\nNhap Petal Width :");
      scanf("%f", &(iris->petalWidth));

      printf("\nChon Class:");
      printf("\n1:  Iris Setosa");
      printf("\n2:  Iris Versicolour");
      printf("\n3:  Iris Virginica");
      printf("\n");
      scanf("%d", &a);
      char s[30];
      if (a == 1)
      {
         strcpy(iris->cls, iris_setosa);
      }
      else if (a == 2)
      {
         strcpy(iris->cls, iris_versicolo);
      }
      else
      {
         strcpy(iris->cls, iris_virginica);
      }
      i += 1;
      fseek(fp, 0, SEEK_SET);
      fprintf(fp, "%d\r", i);
      fseek(fp, 0, SEEK_END);
      fprintf(fp, "%0.1f,%0.1f,%0.1f,%0.1f,%s\r", iris->sepalLength, iris->sepalWidth, iris->petalLength, iris->petalWidth, iris->cls);
      system("cls");
      printf("Them du lieu thanh cong.\n");
      printf("Doc File :\n");
      printf("1: Co\n");
      printf("2: Ghi File tiep\n");
      int docfile;
      scanf("%d", &docfile);
      if (docfile == 1)
      {
         fclose(fp);
         readFile();
         return true;
      }
      system("cls");
   }
   fclose(fp);
   return true;
}
bool writeFileBinary()
{

   int n;
   FILE *in, *out;
   char str[255];
   char noi[] = " \r";
   system("cls");
   if ((in = fopen("iris.data", "rb")) == NULL)
   {
      fprintf(stderr, "impossible to open: iris.data\n");
      perror("Because:");
      fclose(in);
      fclose(out);
      fflush(stdin);
      getchar();
      return false;
   }
   if ((out = fopen("binary.data", "wb+")) == NULL)
   {
      fprintf(stderr, "impossible to open: binary.data\n");
      perror("Because:");
      fclose(out);
      fclose(in);
      fflush(stdin);
      getchar();
      return false;
   }
   while (fscanf(in, "%s", str) != EOF)
   {
      strcat(str, noi);
      fwrite(str, strlen(str) + 1, 1, out);
   }

   fclose(in);
   fclose(out);
   printf("Ghi file thanh cong vao thu muc binary.data");
   fflush(stdin);
   getchar();
   return true;
}
int main()
{

   int n;
   while (true)
   {
      system("cls");
      printf("1 : Doc File\n");
      printf("2 : Them du lieu vao File\n");
      printf("3 : Ghi File nhi phan\n");
      printf("0 : Thoat\n");
      scanf("%d", &n);
      if (n == 1)
      {
         readFile();
      }
      else if (n == 2)
      {
         writeFile();
      }
      else if (n == 3)
      {
         writeFileBinary();
      }
      else
      {
         return 0;
      }
   }
   return 0;
}
