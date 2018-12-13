void *runner(void *ptr)( int i, threadNum = *((int *)ptr); char buffer[30]; struct timespec delay, left;
                        sprintf(buffer, "Hello from threadfld with tid %ld\n", threadNum, syscall( NR_gettid)); delay.tv_sec = 0;
                        for(i = 0; i < strlen(buffer); i++){ printf("%c",buffer[i]); delay.tv_nsec = rand()%90000; nanosleep(&delay,&left);
                        } pthread_exit(0);
                        }
