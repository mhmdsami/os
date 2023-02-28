#include <iostream>
#include <sys/wait.h> // for wait()
#include <unistd.h> // for fork()
using namespace std;

int main() 
{
    // creating 4 process using 2 fork calls
    // 1 parent, 2 child and 1 grandchild
    pid_t id1 = fork();
    pid_t id2 = fork();

    if (id1 > 0 && id2 > 0)
    {
        cout << "\nChild Process id: " << getpid() << endl;
        wait(NULL);
        cout << "\nChild Process with parent id: " << getppid() << endl;
    }

    // parent process
    if (id1 > 0 && id2 > 0)
    {
        wait(NULL);
        wait(NULL);
        cout << "Parent Terminated" << endl;
    }

    // first child
    else if (id1 == 0 && id2 > 0) 
    {
        sleep(2);
        wait(NULL);
        cout << "1st child Terminated" << endl;
    }

    // second child
    else if (id1 > 0 && id2 == 0)
    {
        sleep(1);
        cout << "2nd Child Terminated" << endl;
    }

    // grandchild
    else 
    {
        cout << "Grand Child Terminated" << endl;
        exit(0);
    }
    return 0;
}
