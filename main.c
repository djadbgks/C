#include <stdio.h>

#include <time.h>

#include <Windows.h>



void seat_arrangement(int row, int column, int student);

void shuffle_number(int sit_number[], int student);

void draw_check02(int column, int row);

void gotoxy(int x, int y);



int main(void)

{

    int row, column, student;

    printf("자리배치 프로그램\n");

    printf("좌석배치에 대한 행과 열을 입력해야 합니다\n");

    printf("학생수는 최대 100명입니다.(10X10)\n");

    printf("행의 수를 입력하고 Enter>");

    scanf_s("%d", &row);

    printf("열의 수를 입력하고 Enter>");

    scanf_s("%d", &column);

    printf("학생 수를 입력하고 Enter>");

    scanf_s("%d", &student);

    seat_arrangement(row, column, student);

    printf("\n\n\n");

    return 0;

}



void gotoxy(int x, int y)

{

    COORD Pos = { x - 1, y - 1 };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



/*

확장된 바둑판 그리기 함수 draw_check02

*/

void draw_check02(int c, int r)

{

    int i, j;

    unsigned char a = 0xa6;

    unsigned char b[12];

    for (i = 1; i < 12; i++)

        b[i] = 0xa0 + i;

    printf("%c%c", a, b[3]);

    for (i = 0; i < c - 1; i++)

    {

        printf("%c%c", a, b[1]);

        printf("%c%c", a, b[8]);

    }

    printf("%c%c", a, b[1]);

    printf("%c%c", a, b[4]);

    printf("\n");

    for (i = 0; i < r - 1; i++)

    {

        printf("%c%c", a, b[2]);;

        for (j = 0; j < c; j++)

        {

            printf("  ");

            printf("%c%c", a, b[2]);

        }

        printf("\n");

        printf("%c%c", a, b[7]);

        for (j = 0; j < c - 1; j++)

        {

            printf("%c%c", a, b[1]);

            printf("%c%c", a, b[11]);

        }

        printf("%c%c", a, b[1]);

        printf("%c%c", a, b[9]);

        printf("\n");

    }

    printf("%c%c", a, b[2]);

    for (j = 0; j < c; j++)

    {

        printf("  ");

        printf("%c%c", a, b[2]);

    }

    printf("\n");

    printf("%c%c", a, b[6]);

    for (i = 0; i < c - 1; i++)

    {

        printf("%c%c", a, b[1]);

        printf("%c%c", a, b[10]);

    }

    printf("%c%c", a, b[1]);

    printf("%c%c", a, b[5]);

    printf("\n");

}



/*

난수에 의해 배열에 저장된 값을 임의로 섞는 함수 shuffle_number

*/

void shuffle_number(int sit_number[], int student)

{

    int i, rnd, temp;

    for (i = 0; i < student; i++)

    {

        rnd = rand() % student;

        temp = sit_number[rnd];

        sit_number[rnd] = sit_number[i];

        sit_number[i] = temp;

    }

}



/*

좌석 번호를 임의로 배치하여 출력하는 함수 seat_arrangement

*/

void seat_arrangement(int row, int column, int student)

{

    int sit_number[100] = { 0 };

    int i, j, count = 0;

    for (i = 0; i < student; i++)

        sit_number[i] = i + 1;

    shuffle_number(sit_number, student);

    gotoxy(1, 7);

    draw_check02(column, row);

    for (i = 1; i <= row; i++)

    {

        for (j = 1; j <= column; j++)

        {

            gotoxy(j * 4 - 1, 6 + i * 2);

            printf("%2d", sit_number[count]);

            count++;

            if (count == student)

                return;

        }

    }

}
