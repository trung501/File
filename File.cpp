#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Iris
{
    float sepalLength, sepalWidth, petalLength, petalWidth;
    char cls[20];

} Iris;
Iris *iris;
int N;
bool Update()
{
    FILE *fp;
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
    fscanf(fp, "%d\n", &N);
    printf("\nReading file data ...\n");

    iris = (Iris *)malloc(N * sizeof(struct Iris));
    for (int i = 0; i < N; i++)
    {
        fscanf(fp, "%f,%f,%f,%f,%s",
               &((iris + i)->sepalLength),
               &((iris + i)->sepalWidth),
               &((iris + i)->petalLength),
               &((iris + i)->petalWidth),
               (iris + i)->cls);
    }
    printf("\nSo phan tu : %d\n", N);
    fclose(fp);
    system("cls");
    return true;
}
void HienThiDuLieu()
{
    system("cls");
    printf("\nSo phan tu : %d\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%s\n",
               (iris + i)->sepalLength,
               (iris + i)->sepalWidth,
               (iris + i)->petalLength,
               (iris + i)->petalWidth,
               (iris + i)->cls);
    }
    printf("An phim bat ky de thoat\n ");
    fflush(stdin);
    getch();
}
int writeFile()
{
    char iris_setosa[20] = "Iris-setosa";
    char iris_versicolo[20] = "Iris-versicolor";
    char iris_virginica[20] = "Iris-virginica";
    system("cls");
    char soDong[10];
    FILE *fp;
    Iris *irs;
    irs = (Iris *)malloc(sizeof(struct Iris));
    int a;
    fp = fopen("iris.data", "r+");
    if ((fp) == NULL)
    {
        fprintf(stderr, "impossible to open: iris.data\n");
        perror("Because:");
        fclose(fp);
        getch();
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
        scanf("%f", &(irs->sepalLength));
        if (irs->sepalLength == 0.0)
        {
           break;
        }
        printf("\nNhap Sepal Width :");
        scanf("%f", &(irs->sepalWidth));
        printf("\nNhap Petal Length :");
        scanf("%f", &(irs->petalLength));
        printf("\nNhap Petal Width :");
        scanf("%f", &(irs->petalWidth));

        printf("\nChon Class:");
        printf("\n1:  Iris Setosa");
        printf("\n2:  Iris Versicolour");
        printf("\n3:  Iris Virginica");
        printf("\n");
        scanf("%d", &a);
        char s[30];
        if (a == 1)
        {
            strcpy(irs->cls, iris_setosa);
        }
        else if (a == 2)
        {
            strcpy(irs->cls, iris_versicolo);
        }
        else
        {
            strcpy(irs->cls, iris_virginica);
        }
        i += 1;
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, "%d\r", i);
        fseek(fp, 0, SEEK_END);
        fprintf(fp, "%0.1f,%0.1f,%0.1f,%0.1f,%s\r", irs->sepalLength, irs->sepalWidth, irs->petalLength, irs->petalWidth, irs->cls);
        system("cls");
        printf("Them du lieu thanh cong.\n");
        printf("Update du lieu :\n");
        printf("1: Co\n");
        printf("2: Ghi File tiep\n");
        int addFile;
        scanf("%d", &addFile);
        if (addFile == 1)
        {
            break;
        }
        system("cls");
    }
    fclose(fp);
    Update();
    return true;
}
void writeFileBinary()
{
    system("cls");
    printf("\nWriting binary file data ...\n");

    FILE *f = fopen("iris.bin", "wb");

    fwrite(&N, sizeof(4), 1, f);
    for (int i = 0; i < N; i++)
    {
        fwrite(iris + i, sizeof(Iris), 1, f);
    }

    fclose(f);
    printf("\nWrite Done!\n");
    fflush(stdin);
    getch();
}
int main()
{
    bool check = Update();
    if (check == false)
    {
        fflush(stdin);
        getchar();
        free(iris);
        return 0;
    }
    system("cls");
    int n;
    while (true)
    {
        printf("1 : Update\n");
        printf("2 : Hien Thi Du lieu\n");
        printf("3 : Them du lieu vao File\n");
        printf("4 : Ghi File nhi phan\n");
        printf("0 : Thoat\n");
        scanf("%d", &n);
        if (n == 1)
        {
            check = Update();
            if (check == false)
            {
                fflush(stdin);
                getchar();
                free(iris);
                return 0;
            }
            system("cls");
            printf("Doc du lieu thanh cong\n\n");
        }
        else if (n == 2)
        {
            HienThiDuLieu();
            system("cls");
        }
        else if (n == 3)
        {
            writeFile();
            system("cls");
        }
        else if (n == 4)
        {
            writeFileBinary();
            system("cls");
        }
        else
        {
            return 0;
        }
    }
    return 0;
    free(iris);
    return 0;
}