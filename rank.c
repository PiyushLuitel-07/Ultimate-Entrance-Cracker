void rank(){           ///// rank page
    system("cls");
    coordn(10, 3);
    printf("Result of ranks.\n\n\n");
    int count = 0,i,j;
    std stdt;
    FILE *fle;
    fle = fopen("student.dat","rb");
    while(fread(&stdt,sizeof(std),1,fle)){  // taking the stored number of data in file
        ++count;
    }
    std stdnt[count];   // declearing the array to store all data of file
    /////////////reading data from file////////////////
    fseek(fle, 0, SEEK_SET); // to set cursor (file pointer) at beginning of file
    for(i = 0; i < count; i++){
        fread(&stdnt[i], sizeof(std), 1, fle);
    }
    /////////////////////////////////////////////////SORTING//////////////
    std temp;
    temp.marks=0;
    temp.name;
    for (i=0;i<count;i++){
        for (j=i;j<=count;j++){
            if (stdnt[j].marks>stdnt[j+1].marks){
                temp.marks=stdnt[j].marks;
                stdnt[j].marks=stdnt[j+1].marks;
                stdnt[j+1].marks=temp.marks;
                strcpy(temp.name,stdnt[j].name);
                strcpy(stdnt[j].name,stdnt[j+1].name);
                strcpy(stdnt[j+1].name,temp.name);
            }
        }
    }
    j = 1;
    printf("\n\tRank\tName\t\t\t\tScore\n");
    for (i = count; i > 1 ; i--){
        printf("\t  %2d    %s\t\n", j, stdnt[i-1].name);
        j++;
    }

    j = 1;
    for (i = count; i > 1; i--){
        coordn(40, 7 + j);
        printf("\t%d\t", stdnt[i-1].marks);
        j++;
    }

    coordn(10, 3);
    printf("Press any key to continue: "); getche();
    main();     ///return to main menu

}

