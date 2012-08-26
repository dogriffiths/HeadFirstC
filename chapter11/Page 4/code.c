  #include <sys/socket.h>
  ...
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  if (listener_d == -1)
    error("Can't open socket");
  #include <arpa/inet.h>
  ...
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  int c = bind (listener_d, (struct sockaddr *) &name, sizeof (name));
  if (c == -1)
    error("Can't bind to socket");
