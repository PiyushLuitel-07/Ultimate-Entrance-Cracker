void start(){       /////// start page
    que question;

    std stdt;
    int i,num,score=0,count =0,random[50];
    char option;
	char que_select;
    system("cls");
    coordn(2, 2);
    coordn(42, 3);
    delaying("Ultimate Entrance Cracker");
    coordn(15, 8);
    printf(" _____________________________________________________________________________\n");
    coordn(15, 25);
    printf("______________________________________________________________________________\n");


    ///////////////////////////////////user interaction in start//////
    fseek(stdin, 0, SEEK_END); //clear input buffer
    coordn(25, 11);
    printf("Enter Your name: ");gets(stdt.name);
    /////////////////questions  selection////////////////////
    coordn(25, 13);
    printf(" Please Select the valid options: ");
    coordn(25, 14);
    printf("A. Attempt 50 questions");
    coordn(25, 15);
    printf("B. Customized selection.");
    coordn(25, 16);
    printf("C. Return to main menu.");
    fseek(stdin, 0, SEEK_END);
    coordn(25, 20);
    printf(" Choose A/B/C: ");que_select = getche();
    if(que_select=='a'|| que_select=='A'){
        num = 50;
    }
    else if(que_select == 'b' || que_select == 'B'){
        coordn(25, 22);
        printf("Enter Number of question you want to attempt: ");scanf("%d",&num);
    }
    else{
        main();
    }
    FILE *fil;
    fil= fopen("question.dat","rb");
    if(fil==NULL)
    {
        printf("\nCannot read file. \n");
        exit (0);
    }
    while(fread(&question,sizeof(que),1,fil)){  // taking the stored number of data in file
        ++count;
    }

    srand(time(0)); //setting up for rand()
/////////////////making array of random numbers///////
    int temp;
    for(i=0;i<50;i++){
    temp=rand()%count;
    for(int j=0;j<i;j++){
        check:
        if (temp == random[j]) {
            temp=rand()%count;
            goto check;
        }
    }
    random[i]=temp;
    }

    int *n;
    n = &num;

    system("cls");
    coordn(45, 3);
    delaying("Ultimate Entrance Cracker");
    coordn(15, 8);
    printf(" _____________________________________________________________________________\n");
    coordn(15, 25);
    printf("______________________________________________________________________________\n");
    coordn(50, 15);
    printf("LOADING");
    for (int loadings = 0; loadings < 3; loadings++){
        Sleep(500);
        printf(".");
    }


    pthread_create(&thread, NULL, timer, (void *) n);
    
    for(int i = 0; i < num; i++)
    {
        if(pthread_kill(thread, 0) == 0) {
            system("cls");
///////////randomly accessing files content//////
            fseek(fil,random[i]*sizeof(que),0);
    ///////////////////////////////////
            fread(&question, sizeof(que), 1, fil);
            coordn(8, 3);
            printf("\n\n\tQuestion NO %d:\n", i + 1);
            printf("\n\t%s\n",question.question);
            printf("\ta. %s\n",question.a);
            printf("\tb. %s\n",question.b);
            printf("\tc. %s\n",question.c);
            printf("\td. %s\n",question.d);
            printf("\n\n");

            printf("\tEnter your Choice :\t");
            fseek(stdin, 0, SEEK_END); //clear input buffer
            coordn(25, 24);
            scanf("%c", &option);
            b = option;
            if (b == 'q' || b == 'Q') {
                goto end;
            }
            if(option==question.correct) score++;     //// editing score.
            }
        else {
            break;
            }
    }

    b = 'q';
    pthread_join(thread, NULL);
    fclose(fil);
/////////////////////opening file to store student data
    fil= fopen("student.dat","ab");
    if(fil==NULL)
    {
        printf("Cannot read file. \n");
        exit (1);
    }
/////////////////////checking conditions////////////////
    if(score != 0){
        stdt.marks=score;
        fwrite(&stdt,sizeof(std),1,fil);
    }
    fclose(fil);
    system("cls");

    end:
    coordn(15, 8);
    printf("Your Total Score is -> %d",score);
    coordn(15, 10);
    printf("Press any Key to continue: ");
    getche();

    main();    /// returning to main menu

}
