#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int mode; // Chế độ chơi
    int max, min=1;     // Giới hạn
    int soBiMat, soDoan;
    int soLanDoan;
    int capdo; // 3 cấp độ
    int tieptuc; // Vòng lặp để quyết định có chơi tiếp không. Khác là để chọn lại chế độ chơi
    reset:
    do
    {
        system("cls");
        printf("Chao mung ban den voi tro choi doan so bi mat :)!!\n");
        printf("Hay chon che do choi\nNhan so 1 de chon che do choi 1 nguoi\nNhan so 2 de chon che do choi 2 nguoi\n");
        scanf("%d", &mode); // Nhập chế độ chơi
        //Chọn cấp độ chơi
        printf("Hay chon cap do phu hop\n");
        printf("1 - De : 1 --> 100 so\n");
        printf("2 - Binh thuong : 1 --> 1000 so\n");
        printf("3 - Kho : 1 --> 10000 so\n");
        scanf("%d", &capdo);
        if(capdo == 1)
        {
            max = 100;
        }
        else if(capdo ==2)
        {
            max = 1000;
        }
        else
        {
            max =10000;
        }
    if(mode == 1) //Chơi 1 người
    {
       gomode1:
       soLanDoan = 1;
    // srand phải được chạy duy nhất một lần ở đầu chương trình
    // srand (time(Null)); là để chương trình tránh chọn trùng 2 số ngẫu nhiên
    // rand() thì có thể sử dụng bao nhiêu lần tùy thích
        srand (time(NULL));
        soBiMat = (rand() % (max - min +1)) + min;  // function rand hỗ trợ tạo một số ngẫu nhiên bất kì
        printf("Hay doan so bi mat? ");
            do
            {
                scanf("%d", &soDoan);
                if(soDoan == soBiMat)
                {
                    printf("Chuc mung ban da doan dung sau %d lan doan %d la so bi mat!!!", soLanDoan, soDoan);
                }
                else if(soDoan < soBiMat)
                {
                    printf("So ban nhap nho hon so bi mat\n");
                }
                else
                {
                    printf("So ban nhap lon hon so bi mat\n");
                }
            soLanDoan++;
            }while(soDoan != soBiMat);
    }
    if(mode == 2)
    {
        gomode2:
        soLanDoan = 1;
        printf("Nguoi choi 1 hay nhap so bi mat \n");
        scanf("%d", &soBiMat);
        printf("Nguoi choi 2 hay doan so bi mat\n");
        do
            {
                scanf("%d", &soDoan);
                if(soDoan == soBiMat)
                {
                    printf("Chuc mung ban da doan dung sau %d lan doan %d la so bi mat!!!\n", soLanDoan, soDoan);
                }
                else if(soDoan < soBiMat)
                {
                    printf("So ban nhap nho hon so bi mat\n");
                }
                else
                {
                    printf("So ban nhap lon hon so bi mat\n");
                }
            soLanDoan++;
            }while(soDoan != soBiMat);

    }
        menu:
        printf("Ban co muon tiep tuc choi khong? Hay chon tuy chon duoi day\n");
        printf("1 - Yes\n2 - No\n3 - Co nhung chon lai che do choi");
        scanf("%d", &tieptuc);
        if(tieptuc == 1)
        {
            system("cls");
            if(mode == 1)
            {
                goto gomode1; //Quay lại chơi tiếp chế độ mode1. goto để nhảy về
            }
            else
            {
                goto gomode2;
            }
        }
        else if(tieptuc == 3)
        {
            if(mode == 3)
            {
            system("cls");
            goto reset; //Quay lại chơi tiếp và chọn lại chế độ. goto để nhảy về
            }
        }
        else if(tieptuc == 2)
        {
            printf("Cam on ban da chon chung toi! GoodBye.");
        }
        else
        {
            printf("Hay chon tuy chon dung");
            system("cls");
            goto menu;
        }
    }while(tieptuc!=2);
    return 0;
}