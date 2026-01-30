#include <stdio.h>
#include <string.h>
typedef struct
{
	char masach[20];
	char tieude[100];
	char tacgia[50];
	int namxuatban;
	float giaban;
	int sotrang;
	char nhaxuatban[50];
	char loaisach[30];
} SACH;
//khai bao ham tim sach
void timSach(SACH a[], int n);
//Nhap 1 quyen sach
void nhap(SACH *s)
{
	printf("Nhap: masach tieude tacgia namxuatban giaban sotrang nhaxuatban loaisach\n");
	scanf("%s %s %s %d %f %d %s %s", (*s).masach, (*s).tieude, (*s).tacgia, &(*s).namxuatban, &(*s).giaban, &(*s).sotrang, (*s).nhaxuatban, (*s).loaisach);
}
//Xuat 1 qyuen sach
void xuat(SACH s)
{
	printf("%s %s %s %d %f %d %s %s\n", s.masach, s.tieude, s.tacgia, s.namxuatban, s.giaban, s.sotrang, s.nhaxuatban, s.loaisach);
}
int main()
{
    SACH a[10];
    int n, i;

    // nhap n sach
    printf("Nhap so sach: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        nhap(&a[i]);

    //xuar n sach
    printf("\nDanh sach sach vua nhap:\n");
    for(i = 0; i < n; i++)
        xuat(a[i]);
	//goi ham tim sach
	timSach(a, n);
    return 0;
}
	//ghi file
	void ghiFile(SACH a[], int n)
	{
		FILE *f = fopen("sach.dat","wb");
		fwrite(&n, sizeof(int), 1, f);
		fwrite(a, sizeof(SACH), n, f);
		fclose(f);
	}
	//doc file 
	void docFile(SACH a[], int *n)
	{
		FILE *f = fopen("sach.dat","rb");
		fread(n, sizeof(int), 1, f);
		fread(a, sizeof(SACH), *n, f);
		fclose(f);
	}
	//tim sach
	void timSach(SACH a[], int n)
{
    char ma[20];
    int found = 0;

    printf("\nNhap ma sach can tim: ");
    scanf("%s", ma);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(a[i].masach, ma) == 0)
        {
            printf("\nDa tim thay sach:\n");
            xuat(a[i]);      // hien thi sach da nhap
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nKhong tim thay sach co ma %s\n", ma);
    }
}

