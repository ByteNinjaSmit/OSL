#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child process executing...\n");
        sleep(3);
        printf("Child exiting\n");
    }
    else
    {
        wait(NULL);
        printf("Parent resumes after child finishes\n");
    }
    return 0;
}