// ✅ mini_daemon.c 

#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

int main() {
    if (fork()) exit(0);
    setsid(); chdir("/"); umask(0);
    close(0); close(1); close(2);

    openlog("mini_daemon", LOG_PID, LOG_DAEMON);
    while (1) {
        syslog(LOG_INFO, "Daemon active");
        sleep(30);
    }
    return 0;
}

// 🧪 Compile and Run:
// gcc mini_daemon.c -o mini_daemon
// ./mini_daemon
// ps -ef | grep mini_daemon
// tail -f /var/log/syslog
