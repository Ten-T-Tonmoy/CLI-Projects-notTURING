#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[100];
    char address[100];
    int sem;
    int year;
    char email[50];
    char phn[15];
} stu;

int count = 0;
stu students[100];

void add();
void update();
void search();
void show();
void Remove();
void remove_all();
void sort_by_year();

int main()
{
    int opt;

    while (1)
    {
        printf("\n--------------------------------------------\n");
        printf("|   --- Information Management Center ---  |\n");
        printf("--------------------------------------------\n");
        printf("| 1. Add Student Data                      |\n");
        printf("| 2. Update Existing Data                  |\n");
        printf("| 3. Search Student                        |\n");
        printf("| 4. Show Data of All Students             |\n");
        printf("| 5. Delete Student Data                   |\n");
        printf("| 6. Delete All Data                       |\n");
        printf("| 7. Sort Students(based on Year)          |\n");
        printf("| 8. Quit                                  |\n");
        printf("--------------------------------------------\n");
        printf("Enter your Option(1-8): ");
        scanf("%d", &opt);

        if (opt == 1)
            add();
        if (opt == 2)
            update();
        if (opt == 3)
            search();
        if (opt == 4)
            show();
        if (opt == 5)
            Remove();
        if (opt == 6)
            remove_all();
        if (opt == 7)
            sort_by_year();
        if (opt == 8)
            break;
    }

    return 0;
}

void add()
{
    if (count >= 100)
    {
        printf("List is full.\n");
        return;
    }

    stu s;

    printf("Enter Roll: ");
    scanf("%d", &s.id);

    getchar();

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = 0;

    printf("Enter Semester: ");
    scanf("%d", &s.sem);

    printf("Enter Year: ");
    scanf("%d", &s.year);

    getchar();

    printf("Enter Email: ");
    fgets(s.email, sizeof(s.email), stdin);
    s.email[strcspn(s.email, "\n")] = 0;

    printf("Enter Mobile no: ");
    fgets(s.phn, sizeof(s.phn), stdin);
    s.phn[strcspn(s.phn, "\n")] = 0;

    students[count] = s;

    printf("Data Added successfully.\n");
    count++;
}

void update()
{
    int targ, flag = 0;
    printf("Enter Roll(for updating): ");
    scanf("%d", &targ);
    for (int i = 0; i < 100; i++)
    {
        if (students[i].id == targ)
        {
            flag = 1;
            targ = i;
            break;
        }
    }
    if (!flag)
    {
        printf("Student not found!\n");
        return;
    }

    printf("Enter Name: ");
    getchar();
    fgets(students[targ].name, sizeof(students[targ].name), stdin);
    students[targ].name[strcspn(students[targ].name, "\n")] = 0;

    printf("Enter Address: ");
    fgets(students[targ].address, sizeof(students[targ].address), stdin);
    students[targ].address[strcspn(students[targ].address, "\n")] = 0;

    printf("Enter Semester: ");
    scanf("%d", &students[targ].sem);

    printf("Enter Year: ");
    scanf("%d", &students[targ].year);

    getchar();

    printf("Enter Email: ");
    fgets(students[targ].email, sizeof(students[targ].email), stdin);
    students[targ].email[strcspn(students[targ].email, "\n")] = 0;

    printf("Enter Mobile no: ");
    fgets(students[targ].phn, sizeof(students[targ].phn), stdin);
    students[targ].phn[strcspn(students[targ].phn, "\n")] = 0;

    printf("Data Updated successfully.\n");
}

void search()
{
    int targ, flag = 0;
    printf("Enter Roll(for searching): ");
    scanf("%d", &targ);
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == targ)
        {
            flag = 1;
            targ = i;
            break;
        }
    }
    if (!flag)
    {
        printf("Student not found!\n");
        return;
    }
    printf("Roll: %d\nName: %s\nAddress: %s\nSemester: %d\nYear: %d\nEmail: %s\nMobile: %s\n",
           students[targ].id, students[targ].name, students[targ].address,
           students[targ].sem, students[targ].year, students[targ].email, students[targ].phn);
}

void show()
{
    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("Roll: %d\nName: %s\nAddress: %s\nSemester: %d\nYear: %d\nEmail: %s\nMobile: %s\n",
               students[i].id, students[i].name, students[i].address,
               students[i].sem, students[i].year, students[i].email, students[i].phn);
        printf("\n");
    }
}

void Remove()
{
    int targ, flag = 0;
    printf("Enter Roll(for removing): ");
    scanf("%d", &targ);
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == targ)
        {
            flag = 1;
            targ = i;
            break;
        }
    }
    if (!flag)
    {
        printf("Student not found!\n");
        return;
    }
    for (int i = targ; i < count - 1; i++)
    {
        students[i] = students[i + 1];
    }
    count--;
    printf("Data Removed successfully.\n");
}

void remove_all()
{
    count = 0;
    printf("All data removed successfully.\n");
}

void sort_by_year()
{
    stu temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (students[i].year > students[j].year)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Data sorted by Year.\n");
}





