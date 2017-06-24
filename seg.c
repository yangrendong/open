#include <stdlib.h>
#include <signal.h>

static void foo(int sig)
{
    (void)sig;
    return;
}

int main(int argc, char* argv[])
{
    struct sigaction action;
    action.sa_handler = foo;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if(sigaction(SIGSEGV, &action, NULL) == -1){
        return -1;
    }

    int* p = NULL;
    *p = 0;

    return 0;
}
