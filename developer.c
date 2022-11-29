void developer(){       //// developer page
    int n, i;
    system("cls");
    coordn(45, 3);
    delaying("Ultimate Entrance Cracker");
    coordn(15, 8);
    printf(" _____________________________________________________________________________\n");
    coordn(15, 25);
    printf("______________________________________________________________________________\n");
    coordn(30, 10);
    printf("\t WELCOME TO DEVELOPER PAGE:\n");
    
    coordn(30, 11);
    printf("Enter number of question to add"); scanf("%i", &n);
    que questions;
    FILE *fle;
    fle= fopen("question.dat","ab");

    if(fle==NULL)
    {
    coordn(38, 14);
    printf("Cannot open file. \n");
    exit (0);
    }
    
    for(i = 0; i < n; i++){
        fseek(stdin, 0, SEEK_END);
        system("cls");
        coordn(45, 3);
        printf("Ultimate Entrance Cracker");
        coordn(15, 8);
        printf(" _____________________________________________________________________________\n");
        coordn(15, 25);
        printf("______________________________________________________________________________\n");
        coordn(30, 10);
        printf("\t WELCOME TO DEVELOPER PAGE:\n");
        coordn(30, 11);
        printf("For question no %d",i+1);
        coordn(30, 12);
        printf("Question :"); gets(questions.question);
        coordn(30, 13);
        printf("Option a: "); gets(questions.a);
        coordn(30, 14);
        printf("Option b: "); gets(questions.b);
        coordn(30, 15);
        printf("Option c: "); gets(questions.c);
        coordn(30, 16);
        printf("Option d: ");gets(questions.d);
        coordn(30, 17);
        printf("Correct Option : ");questions.correct=getchar();
        fwrite(&questions, sizeof(que), 1, fle);
    }

    fclose(fle);
    system("cls");
    coordn(30, 11);
    printf("Your questions are sucessfully stored in file.");
    coordn(30, 12);
    printf("Press 'A' to add more .");
    coordn(30, 13);
    printf("Press any key to go to main menu");
    char select = getche();

    switch (select)
    {
    case 'a':
        developer();
        break;
    default:
        main();
        break;

    }
}

