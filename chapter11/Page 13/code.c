 void error(char* msg)
 {
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
 }
 int open_listener_socket()
 {
   int s = socket(PF_INET, SOCK_STREAM, 0);
   if (s == -1)
     error("Can't open socket");
   return s;
 }
 void bind_to_port(int socket, int port)
 {
   struct sockaddr_in name;
   name.sin_family = PF_INET;
   name.sin_port = (in_port_t)htons(30000);
   name.sin_addr.s_addr = htonl(INADDR_ANY);
   int reuse = 1;
   if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
     error("Can't set the reuse option on the socket");
   int c = bind (socket, (struct sockaddr *) &name, sizeof (name));
   if (c == -1)
     error("Can't bind to socket");
 }
 int say(int socket, char* s)
 {
   int result = send(socket, s, strlen(s), 0);
   if (result == -1)
     fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
   return result;
 }
