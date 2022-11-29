char b = 'a';

void* timer(void *numb) {
	int number = *((int *) numb);
    int min = 0, sec = 5, temp;
    temp = 72 * number;
    sec = temp % 60;
    min = temp/60;
    system("cls");
    Sleep(1000);
    
    Sleep(1000);

    do
    {	coordn(0, 1);
        printf("Time Remaining:\n");
    	
		printf("\r%02d:%02d", min, sec);
        
        if ( sec != 0)
            sec--;
        if (sec == 0 && min != 0){
            sec = 59;
            min--;
        }

        if (b == 'q'|| b == 'Q') {
            printf("\rThank you!!!");
        	pthread_exit(timer);
		}
        
        if (min == 0 && sec == 0) {
        	printf("\t\t\t\r%02d:%02d\t\t", min, sec);
            pthread_exit(timer);
    	}
        
    	coordn(30, 14);
        Sleep(1000);
    	
    }
    while(1);
    
    return NULL;
}