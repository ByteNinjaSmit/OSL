#include <stdio.h> 
#include <pthread.h> 
void* thread_function(void* arg) { 
printf("Thread is running\n"); 
return NULL; 
} 
int main() { 
pthread_t t1; 
pthread_create(&t1, NULL, thread_function, NULL); 
pthread_join(t1, NULL); 
printf("Thread finished execution\n"); 
return 0; 
} 