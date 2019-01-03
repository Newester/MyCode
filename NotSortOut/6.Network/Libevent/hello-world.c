#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>

#ifndef _WIN32
#include <netinet/in.h>
# ifdef _XOPEN_SOURCE_EXTENDED
#  include <arpa/innet.h>
# endif
#include <sys/socket.h>
#endif

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

static const char MESSAGE[] = "Hello, World!\n";

static const int PORT = 9995;

static void listener_cb(struct evconnlistener*, evutil_socket_t, struct sockaddr*, int socklen, void*);

static void conn_wirtecb(struct bufferevent*, void*);

static void conn_eventcb(struct bufferevent*, void*);

static void signal_cb(evutil_socket_t, short , void*);

int main(int argc, char *argv[]) {
    struct evdns_base* base;
    struct evconnlistener* listener;
    struct event* signal_event;

    struct sockaddr_in sin;

#ifdef _WIN32
    WSADATA wsa_daata;
    WSAStartup(0x0201, &wsa_daata);
#endif

    base = event_base_new();
    if(!base) {
        fprintf(stderr, "Could not initialize libevent!\n");
        return 1;
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htos(PORT);

    listener = evconnlistener_new_bind(base, listener_cb, (void*)base, LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1, (struct sockaddr*)&sin, sizeof(sin));

    if(!listener) {
        fprintf(stderr, "Could not create a listener!\n");
        return 1;
    }

    signal_event = evsignal_new(base, SIGINT, signal_cb, (void*)base);

    if(!signal_event) {
        fprintf(stderr, "Could not create a signal event!\n");
        return -1;
    }

    event_base_dispatch(base);

    evconnlistener_free(listener);
    event_free(signal_event);
    event_base_free(base);
    fprintf(stdout, "done!\n");
    return 0;

}