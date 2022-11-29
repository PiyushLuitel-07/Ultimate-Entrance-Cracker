void login(){              /////login page
    system("cls");
    char select, username[8], password[8];

    coordn(42, 3);
    delaying("Ultimate Entrance Cracker");
    coordn(15, 8);
    printf(" _____________________________________________________________________________\n");
    coordn(15, 25);
    printf("______________________________________________________________________________\n");
    coordn(30, 10);
    printf(" WELCOME TO DEVELOPER PAGE: ");
    coordn(30, 11);
    printf(" LOGIN HERE ");
    coordn(30, 13);
    printf(" Username = ");
    coordn(42, 13);
    scanf("%s",&username);
    coordn(30, 15);
    printf(" Password = ");
    coordn(42, 15);
    scanf("%s",&password);
    if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0) developer();
    else {
        coordn(30, 14);
        printf("Sorry! invalid username or password.");
        coordn(30, 15);
        printf("Press 'T' to try again. ");
        coordn(30, 16);
        printf("Press any other key to go to main menu.");
        select = getche();
        switch (select)
        {
        case 't':
            login();
            break;
        default:
            main();
            break;
        }

    }
}